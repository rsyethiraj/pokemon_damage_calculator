#include "damage_calculation.h"
#include "typechart.h"
#include <numeric>
#include <cmath>
#include <iostream> //Used in debugging, not needed.

auto round_half_down = [](double val) -> int {
    int floored = static_cast<int>(std::floor(val));
    return (val - floored == 0.5) ? floored : static_cast<int>(std::round(val));
};

float DamageCalculator::calculate_type_effectiveness(Type attacking_1, Type attacking_2, Type defending_1, Type defending_2){
    return TypeChart::getEffectiveness(attacking_1, defending_1)*TypeChart::getEffectiveness(attacking_1, defending_2)*TypeChart::getEffectiveness(attacking_2, defending_1)*TypeChart::getEffectiveness(attacking_2, defending_2);
}


std::vector<int> DamageCalculator::compute_damage_rolls(Pokemon& attacker, Pokemon& defender, Move& move, Weather weather=Weather::None, bool critical = false){
    //Computes type effectiveness
    const PokedexEntry* attacker_species = attacker.getSpecies();
    const PokedexEntry* defender_species = defender.getSpecies();

    float type_effectiveness = DamageCalculator::calculate_type_effectiveness(move.getType1(), move.getType2(), defender_species->getType1(), defender_species->getType2());
    if (type_effectiveness == 0.0f) {
        return {0};
    }
    float base_power = move.getBasePower();
    if (move.dealsDirectDamage()) {
        float defender_weight = defender_species->getWeight();
        float weight_ratio = attacker_species->getWeight() / defender_weight;
        int val = move.getDirectDamageAmount();
        // Target weight-based code (Grass Knot, Low Kick, etc. ): -1
        // Weight ratio-based code (Heavy Slam, Heat Crash, etc. ): -2
        // Target Speed-based code (Gyro Ball, etc. ): -3
        // Level based: < -3
        if (val >= 0) {
            return std::vector<int> {val};
        } else if (val < -3) {
            val = attacker.getLevel();
            return std::vector<int> {val};

        } else if (val == -1) {
            if (defender_weight < 0) {
                return std::vector<int> {0};
            } else if (defender_weight < 10.0f) {
                base_power = 20.0f;
            } else if (defender_weight < 25.0f) {
                base_power = 40.0f;
            } else if (defender_weight < 50.0f) {
                base_power = 60.0f;
            } else if (defender_weight < 100.0f) {
                base_power = 80.0f;
            } else if (defender_weight < 200.0f) {
                base_power = 100.0f;
            } else {
                base_power = 120.0f;
            }
        } else if (val == -2) {
            if (weight_ratio >= 5.0f) {
                base_power = 120.0f;
            } else if (weight_ratio >= 4) {
                base_power = 100.0f;
            } else if (weight_ratio >= 3) {
                base_power = 80.0f;
            } else if (weight_ratio >= 2) {
                base_power = 60.0f;
            } else {
                base_power = 40.0f;
            }
        } else {
            int attacker_speed = attacker.getStats()[5];
            int defender_speed = defender.getStats()[5];
            //No stat changes currently factored in
            if (attacker_speed == 0) {
                base_power = 1;
            } else {
                float raw_power = 25 * (static_cast<float>(defender_speed) / attacker_speed) + 1;
                if (raw_power >= 150) {
                    base_power = 150;
                } else {
                    base_power = std::floor(raw_power);
                }
            }
        }
    }
    //Computes the respective attack/defense stats
    int attack = 0;
    int defense = 1;
    bool uses_phys_defense = true;
    if (move.getMoveType() == MoveType::Physical) {
        if (move.usesInvDefense()) {
            defense = defender.getStats()[4];
            uses_phys_defense = false;
        } else {
            defense = defender.getStats()[2];
        }
        if (move.usesOppAttack()) {
            attack = defender.getStats()[1];
        } else {
            attack = attacker.getStats()[1];
        }
    } else if (move.getMoveType() == MoveType::Special) {
        if (move.usesInvDefense()) {
            defense = defender.getStats()[2];
        } else {
            defense = defender.getStats()[4];
            uses_phys_defense = false;
        }
        if (move.usesOppAttack()) {
            attack = defender.getStats()[3];
        } else {
            attack = attacker.getStats()[3];
        }
    } else {
        return std::vector<int> {0};
    }
    //calculates weather factors wrt stats
    bool sand_boost = false; //gives all rock types a 1.5 special defense boost in sand
    if (weather == Weather::Sand && (defender_species->getType1() == Type::Rock || defender_species->getType2() == Type::Rock)) {
        sand_boost = true;
    }
    float ad_ratio = static_cast<float>(attack) / defense;
    if (sand_boost and !uses_phys_defense) {
        ad_ratio /= 1.5;
    }
    int damage = std::floor(std::floor(std::floor(2.0 * attacker.getLevel() / 5.0 + 2) * base_power * ad_ratio) / 50.0) + 2;
    //Currently ignores multi-target moves and Parental Bond
    //Handles rain/sun, no feature for Hydro Steam/Cloud Nine.
    if ((weather == Weather::Rain || weather == Weather::ExtremeRain) && (move.getType1() == Type::Water ||move.getType2() == Type::Water) || (weather == Weather::Sun || weather == Weather::ExtremeSun) && (move.getType1() == Type::Fire ||move.getType2() == Type::Fire)){
        damage = std::floor(damage*1.5);
    }
    if ((weather == Weather::Rain) && (move.getType1() == Type::Fire ||move.getType2() == Type::Fire) || (weather == Weather::Sun) && (move.getType1() == Type::Water ||move.getType2() == Type::Water)){
        damage = std::floor(damage*0.5);
    }
    if ((weather == Weather::ExtremeRain && (move.getType1() == Type::Fire ||move.getType2() == Type::Fire) ) || (weather == Weather::ExtremeSun && (move.getType1() == Type::Water ||move.getType2() == Type::Water))) {
        return std::vector<int> {0};
    }
    //Ignores Glaive Rush currently
    //Handles Crits
    if (critical == true) {
        damage = std::floor(damage*1.5);
    }
    //computes damage rolls
    std::vector<int> result(16);
    for (int i = 0; i < 16; i++) {
        int multiplier = 85 + i;
        result[i] = damage * multiplier / 100;
        //STAB
        if (move.getType1() == attacker.getSpecies()->getType1() || move.getType1() == attacker.getSpecies()->getType2()) {
            result[i] = std::floor(result[i]*1.5);
        }
        result[i] = std::floor(result[i]*type_effectiveness);
        //Handles burn here
    }

    return result;
    
}

float DamageCalculator::compute_ohko_chance(std::vector<int> damage_rolls, int hp){
    int length = damage_rolls.size();
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (damage_rolls[i] >= hp) {
            count++;
        }
    }
    return static_cast<float>(count) / length;
}
float DamageCalculator::compute_thko_chance(std::vector<int> damage_rolls, int hp){
    int length = damage_rolls.size();
    int count = 0;
    for (int i = 0; i < length; i++) {
        for (int j  = 0; j < length; j++) {
            int damage = damage_rolls[i] + damage_rolls[j];
            if (damage >= hp) {
                count++;
            }
        }
    }
    return static_cast<float>(count)/(length*length);

}
