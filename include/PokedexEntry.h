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
                 float height, float weight,
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
    float getHeight() const;
    float getWeight() const;
    std::string getDescription() const;

private:
    const std::string name, description;
    Type type1, type2;
    const int base_hp, base_atk, base_def, base_sp_atk, base_sp_def, base_speed;
    const float height, weight;
};
