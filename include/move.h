#pragma once
#include "enums.h"
#include <string>

class Move {
public:
    Move(const std::string& name,
         MoveType move_type,
         int base_power,
         Type type1,
         Type type2 = Type::None,
         bool multi_hit = false,
         int max_hits = 1,
         bool inv_defense = false,
         bool opp_attack = false,
         const std::string& description = "");

    const std::string& getName() const;
    Type getType1() const;
    Type getType2() const;
    MoveType getMoveType() const;
    int getBasePower() const;
    bool getMultiHitStatus() const;
    int getMaxHits() const;
    bool usesInvDefense() const;
    bool usesOppAttack() const;
    const std::string& getDescription() const;

private:
    const std::string name;
    const std::string description;
    const MoveType move_type;
    const int base_power;
    Type type1;
    Type type2;
    const bool multi_hit;
    const int max_hits;
    const bool inv_defense;
    const bool opp_attack;
};
