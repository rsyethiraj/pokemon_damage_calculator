#include "pokemon.h"
#include <stdexcept>
#include <numeric>
#include <iostream> //Used in debugging, not needed.
std::atomic<int> Pokemon::idCounter = 0;
Pokemon::Pokemon(const PokedexEntry* species,
                 Nature nature,
                 const std::string& nickname,
                 const std::array<int, 6>& EVs,
                 const std::array<int, 6>& IVs,
                 int level)
    : species(species),
      nature(nature),
      nickname(nickname),
      EVs(EVs),
      IVs(IVs),
      level(level),
      pokemonID(idCounter++)
{
    for (int ev : EVs) {
        if (ev < 0 || ev > 255) {
            throw std::invalid_argument("EVs must each be in [0, 255]");
        }
    }
    int totalEVs = std::accumulate(EVs.begin(), EVs.end(), 0);
    if (totalEVs > 510)
        throw std::invalid_argument("Total EVs must not exceed 510.");

    for (int iv : IVs) {
        if (iv < 0 || iv > 31)
            throw std::invalid_argument("IVs must each be in [0, 31]");
    }

    this->stats = computeStats(this->species, this->nature, this->EVs, this->IVs, this->level);
}
//Getter methods
const std::array<int, 6>& Pokemon::getEVs() const { return EVs; }
const std::array<int, 6>& Pokemon::getIVs() const { return IVs; }
const std::array<int, 6>& Pokemon::getStats() const { return stats; }
int Pokemon::getLevel() const { return level; }
Nature Pokemon::getNature() const { return nature; }
const std::string& Pokemon::getNickname() const { return nickname; }
const PokedexEntry* Pokemon::getSpecies() const { return species; }

//Used to compute the stats for each pokemon based on base stats, level, natures, IVs, and EVs.
std::array<int, 6> Pokemon::computeStats(const PokedexEntry* species, Nature nature,
                                std::array<int, 6>& EVs,
                                const std::array<int, 6>& IVs,
                                int level) {
    std::array<int, 6> stats = {
        species->getBaseHP(),
        species->getBaseAtk(),
        species->getBaseDef(),
        species->getBaseSpAtk(),
        species->getBaseSpDef(),
        species->getBaseSpeed()
    };

    // HP stat
    if (stats[0] == 1) {
        stats[0] = 1; // For Shedinja or creative users
    } else {
        stats[0] = ((2 * stats[0] + IVs[0] + (EVs[0] / 4)) * level) / 100 + level + 10;
    }

    // Convert enum class to int
    int nature_value = static_cast<int>(nature);
    int increased_stat = nature_value / 5; 
    int decreased_stat = nature_value % 5;
    for (int i = 1; i < 6; i++) {
        double modifier = 1.0;
        if (i - 1 == increased_stat && increased_stat != decreased_stat) {
            modifier = 1.1;
        } else if (i - 1 == decreased_stat && increased_stat != decreased_stat) {
            modifier = 0.9;
        }

        stats[i] = static_cast<int>(
            ((2 * stats[i] + IVs[i] + (EVs[i] / 4)) * level) / 100 + 5
        );
        stats[i] = static_cast<int>(stats[i] * modifier);
    }

    return stats;
}

//Setter methods
void Pokemon::setEVs(const std::array<int, 6>& EVs) {
    for (int ev : EVs) {
        if (ev < 0 || ev > 255) {
            throw std::invalid_argument("EVs must each be in [0, 255]");
        }
    }
    int totalEVs = std::accumulate(EVs.begin(), EVs.end(), 0);
    if (totalEVs > 510)
        throw std::invalid_argument("Total EVs must not exceed 510.");
    this->EVs = EVs;
    this->stats = computeStats(this->species, this->nature, this->EVs, this->IVs, this->level);
}

void Pokemon::setNickname(const std::string& nickname) { this->nickname = nickname; }
void Pokemon::setLevel(const int level) {
    if (level <= 0 || level > 100) {
        throw std::invalid_argument("Level must be in [1, 100]");
    }
    this->level = level;
    this->stats = computeStats(this->species, this->nature, this->EVs, this->IVs, this->level);
}
