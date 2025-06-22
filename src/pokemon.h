#pragma once

#include "PokedexEntry.h"
#include <string>
#include <array>
#include <atomic>

class Pokemon {
public:
    Pokemon(PokedexEntry* species,
            const Nature nature,
            const std::string& nickname,
            const std::array<int, 6>& EVs,
            const std::array<int, 6>& IVs,
            const int level);
    
    //getter methods
    const std::array<int, 6>& getEVs() const;
    const std::array<int, 6>& getIVs() const;
    const std::array<int, 6>& getStats() const;
    int getLevel() const;
    Nature getNature() const;
    std::string& getNickname() const;
    const PokedexEntry* getSpecies() const;
    std::array<int, 6> computeStats(PokedexEntry* species, Nature nature, std::array<int, 6> EVs, std::array<int, 6> IVs, int level);

    //setter methods
    void setEVs(const std::array<int, 6>& newEVs);
    void setLevel(const int level)
    void setNickname(const std::string& newNickname);

private:
    Nature nature;
    const int pokemonID;
    std::string nickname;
    const PokedexEntry* species;

    std::array<int, 6> EVs;
    std::array<int, 6> stats; //These are defined at initialization time, can only be changed through EV modification
    const std::array<int, 6> IVs;
    int level;
    static std::atomic<int> idCounter;
};
