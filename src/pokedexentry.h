#pragma once
#include <string>
#include "enums.h"

class PokedexEntry {
public:
    PokedexEntry(const std::string& name,
                 Type type1,
                 Type type2,
                 int base_hp, int base_atk, int base_def,
                 int base_sp_atk, int base_sp_def, int base_speed,
                 double height, double weight,
                 const std::string& description);

    std::string getName() const;
    Type getType1() const;
    Type getType2() const;
    int getBaseHP() const;
    int getBaseAtk() const;
    int getBaseDef() const;
    int getBaseSpAtk() const;
    int getBaseSpDef() const;
    int getBaseSpeed() const;
    double getHeight() const;
    double getWeight() const;
    std::string getDescription() const;

private:
    const std::string name, type1, type2, description;
    const int base_hp, base_atk, base_def, base_sp_atk, base_sp_def, base_speed;
    const double height, weight;
};
