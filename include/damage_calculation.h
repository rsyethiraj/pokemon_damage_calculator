#pragma once
#include "enums.h"
#include "pokemon.h"
#include "move.h"
#include <array>
#include <vector>
class DamageCalculator {
public:
    static float calculate_type_effectiveness(Type attacking_1, Type attacking_2, Type defending_1, Type defending_2);
    static std::vector<int> compute_damage_rolls(Pokemon& attacker, Pokemon& defender, Move& move, Weather weather, bool critical);
    float compute_ohko_chance(std::vector<int> damage_rolls, int hp);
    float compute_tkho_chance(std::vector<int> damage_rolls, int hp);
private:
    static std::array<std::array<int, 18>, 18> damage_table;
};
