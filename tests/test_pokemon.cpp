#include "catch_amalgamated.hpp"
#include "../include/Pokemon.h"
#include "../include/PokedexEntry.h"

TEST_CASE("Pokemon stats are calculated correctly", "[Pokemon]") {
    PokedexEntry pikachu("Pikachu", Type::Electric, Type::None, 35, 55, 40, 50, 50, 90, 0.4, 6.0, "Electric mouse");
    
    std::array<int, 6> EVs = {0, 0, 0, 0, 0, 0};
    std::array<int, 6> IVs = {31, 31, 31, 31, 31, 31};
    Pokemon p(&pikachu, Nature::Hardy, "Sparky", EVs, IVs, 50);
    
    std::array<int, 6> stats = p.getStats();
    
    SECTION("HP stat calculation") {
        REQUIRE(stats[0] == ((2 * 35 + 31 + 0) * 50) / 100 + 50 + 10);
    }
    SECTION("Attack stat calculation") {
        REQUIRE(stats[1] == 75);
    }
    SECTION("Defense stat calculation") {
        REQUIRE(stats[2] == 60);
    }
    SECTION("Special Attack stat calculation") {
        REQUIRE(stats[3] == 70);
    }
    SECTION("Special Defense stat calculation") {
        REQUIRE(stats[4] == 70);
    }
    SECTION("Speed stat calculation") {
        REQUIRE(stats[5] == 110);
    }
}

