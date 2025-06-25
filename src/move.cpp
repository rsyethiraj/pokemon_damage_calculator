#include "move.h"
#include <stdexcept>

// Constructor
Move::Move(const std::string& name,
           MoveType move_type,
           int base_power,
           Type type1,
           Type type2,
           bool multi_hit,
           int max_hits,
           bool inv_defense,
           bool opp_attack,
           const std::string& description)
    : name(name),
      move_type(move_type),
      base_power(base_power),
      type1(type1),
      type2(type2),
      multi_hit(multi_hit),
      max_hits(max_hits),
      inv_defense(inv_defense),
      opp_attack(opp_attack),
      description(description)
{
    if (type1 == Type::None && type2 != Type::None) {
        throw std::invalid_argument("Type1 cannot be None unless both types are None.");
    }
    if (type1 == type2 && type2 != Type::None) {
        this->type2 = Type::None;
    }
    if (multi_hit && max_hits < 2) {
        throw std::invalid_argument("max_hits must be greater than 1 for multi-hit moves.");
    }
}

// Getter implementations
const std::string& Move::getName() const { return name; }
Type Move::getType1() const { return type1; }
Type Move::getType2() const { return type2; }
MoveType Move::getMoveType() const { return move_type; }
int Move::getBasePower() const { return base_power; }
bool Move::getMultiHitStatus() const { return multi_hit; }
int Move::getMaxHits() const { return multi_hit ? max_hits : 1; }
bool Move::usesInvDefense() const { return inv_defense; }
bool Move::usesOppAttack() const { return opp_attack; }
const std::string& Move::getDescription() const { return description; }
