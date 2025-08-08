#include "catch_amalgamated.hpp"
#include "damage_calculation.h"
#include "typechart.h"
#include <iostream>

TEST_CASE("Type matchups are correct", "[TypeChart]") {
    SECTION("Normal Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Fire) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Grass) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Rock) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Ghost) == 0.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Normal, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Normal, Type::COUNT), std::invalid_argument);
    }
    SECTION("Fire Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Fire) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Water) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Grass) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Ice) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Bug) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Rock) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Dragon) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Steel) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fire, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Fire, Type::COUNT), std::invalid_argument);
    }
    SECTION("Water Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Fire) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Water) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Grass) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Ground) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Rock) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Dragon) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Steel) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Water, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Water, Type::COUNT), std::invalid_argument);
    }
    SECTION("Grass Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Fire) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Water) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Grass) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Poison) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Ground) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Flying) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Bug) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Rock) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Dragon) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Grass, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Grass, Type::COUNT), std::invalid_argument);
    }
    SECTION("Electric Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Fire) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Water) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Grass) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Electric) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Ground) == 0.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Flying) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Rock) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Dragon) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Steel) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Electric, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Electric, Type::COUNT), std::invalid_argument);
    }
    SECTION("Ice Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Fire) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Water) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Grass) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Ice) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Ground) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Flying) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Rock) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Dragon) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ice, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Ice, Type::COUNT), std::invalid_argument);
    }
    SECTION("Fighting Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Normal) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Fire) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Grass) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Ice) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Poison) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Flying) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Psychic) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Bug) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Rock) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Ghost) == 0.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Dark) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Steel) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fighting, Type::Fairy) == 0.5f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Fighting, Type::COUNT), std::invalid_argument);
    }
    SECTION("Poison Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Fire) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Grass) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Poison) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Ground) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Rock) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Ghost) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Steel) == 0.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Poison, Type::Fairy) == 2.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Poison, Type::COUNT), std::invalid_argument);
    }
    SECTION("Ground Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Fire) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Grass) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Electric) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Poison) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Flying) == 0.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Bug) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Rock) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Steel) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ground, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Ground, Type::COUNT), std::invalid_argument);
    }
    SECTION("Flying Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Fire) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Grass) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Electric) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Fighting) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Bug) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Rock) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Flying, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Flying, Type::COUNT), std::invalid_argument);
    }
    SECTION("Psychic Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Fire) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Grass) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Fighting) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Poison) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Psychic) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Rock) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Dark) == 0.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Psychic, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Psychic, Type::COUNT), std::invalid_argument);
    }
    SECTION("Bug Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Fire) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Grass) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Fighting) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Poison) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Flying) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Psychic) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Rock) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Ghost) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Dark) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Bug, Type::Fairy) == 0.5f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Bug, Type::COUNT), std::invalid_argument);
    }
    SECTION("Rock Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Fire) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Grass) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Ice) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Fighting) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Ground) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Flying) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Bug) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Rock) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Rock, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Rock, Type::COUNT), std::invalid_argument);
    }
    SECTION("Ghost Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Normal) == 0.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Fire) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Grass) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Psychic) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Rock) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Ghost) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Dark) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Steel) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Ghost, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Ground, Type::COUNT), std::invalid_argument);
    }
    SECTION("Dragon Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Fire) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Grass) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Rock) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Dragon) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dragon, Type::Fairy) == 0.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Normal, Type::COUNT), std::invalid_argument);
    }
    SECTION("Dark Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Fire) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Grass) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Fighting) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Psychic) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Rock) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Ghost) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Dark) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Steel) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Dark, Type::Fairy) == 0.5f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Dark, Type::COUNT), std::invalid_argument);
    }
    SECTION("Steel Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Fire) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Water) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Grass) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Electric) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Ice) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Fighting) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Poison) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Rock) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Dragon) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Dark) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Steel, Type::Fairy) == 2.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Steel, Type::COUNT), std::invalid_argument);
    }
    SECTION("Fairy Type Matchups") {
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Normal) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Fire) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Water) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Grass) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Electric) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Ice) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Fighting) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Poison) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Ground) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Flying) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Psychic) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Bug) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Rock) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Ghost) == 1.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Dragon) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Dark) == 2.0f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Steel) == 0.5f);
        REQUIRE(TypeChart::getEffectiveness(Type::Fairy, Type::Fairy) == 1.0f);
        REQUIRE_THROWS_AS(TypeChart::getEffectiveness(Type::Fairy, Type::COUNT), std::invalid_argument);
    }

}

TEST_CASE("0 Damage situations work properly", "damage_calculator") {
    PokedexEntry Haxorus("Haxorus", Type::Dragon, Type::None, 76, 147, 90, 60, 70, 97, 1.8f, 105.5f, "They are kind but can be relentless when defending territory. They challenge foes with tusks that can cut steel. ");
    Move DragonRage("Dragon Rage", MoveType::Special, 0, Type::Dragon, Type::None, false, 1, false, false, true, 40, "Always inflicts 40HP damage. ");
    Move DragonClaw("Dragon Claw", MoveType::Physical, 80, Type::Dragon, Type::None, false, 1, false, false, false, 0, "The target is raked with draconic claws. ");
    Move DragonPulse("Dragon Pulse", MoveType::Special, 80, Type::Dragon, Type::None, false, 1, false, false, false, 0, "The target is hit with a bolt of energy from the users mouth. ");
    PokedexEntry Flabebe("Flabebe", Type::Fairy, Type::None, 44, 38, 39, 61, 79, 42, 0.1f, 0.1f, "It draws out and controls the hidden power of flowers. The flower Flabébé holds is most likely part of its body.");
    std::array<int, 6> EVs = {0, 252, 4, 0, 0, 252};
    std::array<int, 6> IVs = {31, 31, 31, 31, 31, 31};
    Pokemon hax(&Haxorus, Nature::Jolly, "", EVs, IVs, 100);
    Pokemon fla(&Flabebe, Nature::Timid, "", EVs, IVs, 1);
    std::vector<int> zero_list = {0};
    REQUIRE(DamageCalculator::compute_damage_rolls(hax, fla, DragonRage, Weather::None, false) == zero_list);
    REQUIRE(DamageCalculator::compute_damage_rolls(hax, fla, DragonClaw, Weather::None, false) == zero_list);
    REQUIRE(DamageCalculator::compute_damage_rolls(hax, fla, DragonPulse, Weather::None, false) == zero_list);
}

TEST_CASE("Direct Damage situations work properly") {
    PokedexEntry Haxorus("Haxorus", Type::Dragon, Type::None, 76, 147, 90, 60, 70, 97, 1.8f, 105.5f, "They are kind but can be relentless when defending territory. They challenge foes with tusks that can cut steel. ");
    Move DragonRage("Dragon Rage", MoveType::Special, 0, Type::Dragon, Type::None, false, 1, false, false, true, 40, "Always inflicts 40HP damage. ");
    Move LowKick("Low Kick", MoveType::Physical, 0, Type::Fighting, Type::None, false, 1, false, false, true, -1, "Inflicts damage based on the user's weight");
    Move HeavySlam("Heavy Slam", MoveType::Physical, 0, Type::Steel, Type::None, false, 1, false, false, true, -2, "Inflicts damage based on the weight ratio");
    Move GyroBall("Gyro Ball", MoveType::Physical, 0, Type::Steel, Type::None, false, 1, false, false, true, -3, "Inflicts more damage if the user is slower than the target");
    Move SeismicToss("Seismic Toss", MoveType::Physical, 0, Type::Fighting, Type::None, false, 1, false, false, true, -4, "Inflicts damage based on the users level. ");
    std::array<int, 6> EVs = {0, 252, 4, 0, 0, 252};
    std::array<int, 6> IVs = {31, 31, 31, 31, 31, 31};
    
    Pokemon hax(&Haxorus, Nature::Jolly, "", EVs, IVs, 100);
    PokedexEntry Serperior("Serperior", Type::Grass, Type::None, 75, 75, 95, 75, 95, 113, 3.3f, 63.0f, "It can stop its opponents’ movements with just a glare. It takes in solar energy and boosts it internally.");
    Pokemon ser(&Serperior, Nature::Timid, "", EVs, IVs, 100);
    std::vector<int> forty_list = {40};
    REQUIRE(DamageCalculator::compute_damage_rolls(hax, ser, DragonRage, Weather::None, false) == forty_list);
    forty_list[0] = 100;
    REQUIRE(DamageCalculator::compute_damage_rolls(hax, ser, SeismicToss, Weather::None, false) == forty_list);
    REQUIRE(hax.getStats()[1] == 393);
    REQUIRE(ser.getStats()[2] == 227);
    std::vector<int> damage_rolls = DamageCalculator::compute_damage_rolls(hax, ser, LowKick, Weather::None, false);
    std::vector<int> expected = {100, 101, 102, 103, 105, 106, 107, 108, 109, 110, 112, 113, 114, 115, 116, 118};
    REQUIRE(damage_rolls == expected);
    damage_rolls = DamageCalculator::compute_damage_rolls(hax, ser, HeavySlam, Weather::None, false);
    expected = {51, 51, 52, 52, 53, 54, 54, 55, 55, 56, 57, 57, 58, 58, 59, 60};
    REQUIRE(damage_rolls == expected);
    damage_rolls = DamageCalculator::compute_damage_rolls(hax, ser, GyroBall, Weather::None, false);
    expected = {35, 36, 36, 36, 37, 37, 38, 38, 39, 39, 39, 40, 40, 41, 41, 42};
    REQUIRE(damage_rolls == expected);
}
TEST_CASE("Neutral Damage situations work properly") {
    PokedexEntry Haxorus("Haxorus", Type::Dragon, Type::None, 76, 147, 90, 60, 70, 97, 1.8f, 105.5f, "They are kind but can be relentless when defending territory. They challenge foes with tusks that can cut steel. ");
    Move DragonClaw("Dragon Claw", MoveType::Physical, 80, Type::Dragon, Type::None, false, 1, false, false, false, 0, "The target is raked with draconic claws. ");
    Move DragonPulse("Dragon Pulse", MoveType::Special, 85, Type::Dragon, Type::None, false, 1, false, false, false, 0, "The target is hit with a bolt of energy from the users mouth. ");
    Move Psyshock("Psyshock", MoveType::Special, 80, Type::Psychic, Type::None, false, 1, true, false, false, -0, "Uses the targets defense stat");
    Move FoulPlay("Foul Play", MoveType::Physical, 95, Type::Dark, Type::None, false, 1, false, true, false, 0, "Uses the targets attack stat");
    std::array<int, 6> EVs = {0, 252, 4, 0, 0, 252};
    std::array<int, 6> IVs = {31, 31, 31, 31, 31, 31};
    Pokemon hax(&Haxorus, Nature::Jolly, "", EVs, IVs, 100);
    PokedexEntry Serperior("Serperior", Type::Grass, Type::None, 75, 75, 95, 75, 95, 113, 3.3f, 63.0f, "It can stop its opponents’ movements with just a glare. It takes in solar energy and boosts it internally.");
    Pokemon ser(&Serperior, Nature::Timid, "", EVs, IVs, 100);
    //Physical with STAB
    std::vector<int> damage_rolls = DamageCalculator::compute_damage_rolls(hax, ser, DragonClaw, Weather::None, false);
    std::vector<int> expected = {150, 151, 153, 154, 157, 159, 160, 162, 163, 165, 168, 169, 171, 172, 174, 177};
    REQUIRE(damage_rolls == expected);
    REQUIRE(hax.getStats()[3] == 140);
    REQUIRE(ser.getStats()[4] == 226);
    //Special with STAB
    damage_rolls = DamageCalculator::compute_damage_rolls(hax, ser, DragonPulse, Weather::None, false);
    expected = {58, 58, 60, 60, 60, 61, 61, 63, 63, 64, 64, 66, 66, 67, 67, 69};
    REQUIRE(damage_rolls == expected);
    //Inverse defense
    damage_rolls = DamageCalculator::compute_damage_rolls(hax, ser, Psyshock, Weather::None, false);
    expected = {36, 36, 37, 37, 38, 38, 39, 39, 39, 40, 40, 41, 41, 42, 42, 43};
    REQUIRE(damage_rolls == expected);
    //Opposite Attack
    damage_rolls = DamageCalculator::compute_damage_rolls(hax, ser, FoulPlay, Weather::None, false);
    expected = {68, 68, 69, 70, 71, 72, 72, 73, 74, 75, 76, 76, 77, 78, 79, 80};
    REQUIRE(damage_rolls == expected);
    //Critical Hit
    damage_rolls = DamageCalculator::compute_damage_rolls(hax, ser, DragonClaw, Weather::None, true);
    expected = {225, 228, 229, 232, 235, 238, 241, 243, 246, 249, 252, 253, 256, 259, 262, 265};
    REQUIRE(damage_rolls == expected);
}
