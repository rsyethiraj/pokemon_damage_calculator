#include <string>
#include "PokedexEntry.h"
#include <stdexcept>

// Constructor
PokedexEntry::PokedexEntry(const std::string& name,
                           Type type1,
                           Type type2,
                           int base_hp, int base_atk, int base_def,
                           int base_sp_atk, int base_sp_def, int base_speed,
                           double height, double weight,
                           const std::string& description)
    : name(name),
      type1(type1),
      type2(type2),
      base_hp(base_hp),
      base_atk(base_atk),
      base_def(base_def),
      base_sp_atk(base_sp_atk),
      base_sp_def(base_sp_def),
      base_speed(base_speed),
      height(height),
      weight(weight),
      description(description)
{
    if (type1 == Type::None) {
        throw std::invalid_argument("Primary type cannot be None. ");
    }
    if (type2 == type1){
        type2 = Type::None;
    }
}

// Getters
std::string PokedexEntry::getName() const { return name; }
Type PokedexEntry::getType1() const { return type1; }
Type PokedexEntry::getType2() const { return type2; }
int PokedexEntry::getBaseHP() const { return base_hp; }
int PokedexEntry::getBaseAtk() const { return base_atk; }
int PokedexEntry::getBaseDef() const { return base_def; }
int PokedexEntry::getBaseSpAtk() const { return base_sp_atk; }
int PokedexEntry::getBaseSpDef() const { return base_sp_def; }
int PokedexEntry::getBaseSpeed() const { return base_speed; }
double PokedexEntry::getHeight() const { return height; }
double PokedexEntry::getWeight() const { return weight; }
std::string PokedexEntry::getDescription() const { return description; }
