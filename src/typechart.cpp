#include "typechart.h"
#include <stdexcept>
namespace {
    TypeChart::Chart initializeChart() {
        TypeChart::Chart chart{};

        // Set all to 1.0 by default
        for (int i = 0; i < 18; ++i)
            for (int j = 0; j < 18; ++j)
                chart[i][j] = 1.0f;

        // Fill in key effectiveness values (Gen 6):
        // Normal type matchups
        chart[(int)Type::Normal][(int)Type::Rock] = 0.5f;
        chart[(int)Type::Normal][(int)Type::Steel] = 0.5f;
        chart[(int)Type::Normal][(int)Type::Ghost] = 0.0f;
        //Fire type matchups
        chart[(int)Type::Fire][(int)Type::Grass] = 2.0f;
        chart[(int)Type::Fire][(int)Type::Ice] = 2.0f;
        chart[(int)Type::Fire][(int)Type::Bug] = 2.0f;
        chart[(int)Type::Fire][(int)Type::Steel] = 2.0f;
        chart[(int)Type::Fire][(int)Type::Fire] = 0.5f;
        chart[(int)Type::Fire][(int)Type::Water] = 0.5f;
        chart[(int)Type::Fire][(int)Type::Rock] = 0.5f;
        chart[(int)Type::Fire][(int)Type::Dragon] = 0.5f;
        // Water type matchups
        chart[(int)Type::Water][(int)Type::Fire] = 2.0f;
        chart[(int)Type::Water][(int)Type::Ground] = 2.0f;
        chart[(int)Type::Water][(int)Type::Rock] = 2.0f;
        chart[(int)Type::Water][(int)Type::Water] = 0.5f;
        chart[(int)Type::Water][(int)Type::Grass] = 0.5f;
        chart[(int)Type::Water][(int)Type::Dragon] = 0.5f;
        //Grass type matchups
        chart[(int)Type::Grass][(int)Type::Water] = 2.0f;
        chart[(int)Type::Grass][(int)Type::Ground] = 2.0f;
        chart[(int)Type::Grass][(int)Type::Rock] = 2.0f;
        chart[(int)Type::Grass][(int)Type::Fire] = 0.5f;
        chart[(int)Type::Grass][(int)Type::Grass] = 0.5f;
        chart[(int)Type::Grass][(int)Type::Poison] = 0.5f;
        chart[(int)Type::Grass][(int)Type::Flying] = 0.5f;
        chart[(int)Type::Grass][(int)Type::Bug] = 0.5f;
        chart[(int)Type::Grass][(int)Type::Dragon] = 0.5f;
        chart[(int)Type::Grass][(int)Type::Steel] = 0.5f;
        //Electric type matchups
        chart[(int)Type::Electric][(int)Type::Water] = 2.0f;
        chart[(int)Type::Electric][(int)Type::Flying] = 2.0f;
        chart[(int)Type::Electric][(int)Type::Grass] = 0.5f;
        chart[(int)Type::Electric][(int)Type::Electric] = 0.5f;
        chart[(int)Type::Electric][(int)Type::Dragon] = 0.5f;
        chart[(int)Type::Electric][(int)Type::Ground] = 0.0f;
        //Ιce type matchups
        chart[(int)Type::Ice][(int)Type::Grass] = 2.0f;
        chart[(int)Type::Ice][(int)Type::Ground] = 2.0f;
        chart[(int)Type::Ice][(int)Type::Flying] = 2.0f;
        chart[(int)Type::Ice][(int)Type::Dragon] = 2.0f;
        chart[(int)Type::Ice][(int)Type::Fire] = 0.5f;
        chart[(int)Type::Ice][(int)Type::Water] = 0.5f;
        chart[(int)Type::Ice][(int)Type::Ice] = 0.5f;
        chart[(int)Type::Ice][(int)Type::Steel] = 0.5f;
        //Fighting type matchups
        chart[(int)Type::Fighting][(int)Type::Normal] = 2.0f;
        chart[(int)Type::Fighting][(int)Type::Ice] = 2.0f;
        chart[(int)Type::Fighting][(int)Type::Rock] = 2.0f;
        chart[(int)Type::Fighting][(int)Type::Dark] = 2.0f;
        chart[(int)Type::Fighting][(int)Type::Steel] = 2.0f;
        chart[(int)Type::Fighting][(int)Type::Poison] = 0.5f;
        chart[(int)Type::Fighting][(int)Type::Flying] = 0.5f;
        chart[(int)Type::Fighting][(int)Type::Psychic] = 0.5f;
        chart[(int)Type::Fighting][(int)Type::Bug] = 0.5f;
        chart[(int)Type::Fighting][(int)Type::Fairy] = 0.5f;
        chart[(int)Type::Fighting][(int)Type::Ghost] = 0.0f;
        //Poison type matchups
        chart[(int)Type::Poison][(int)Type::Grass] = 2.0f;
        chart[(int)Type::Poison][(int)Type::Fairy] = 2.0f;
        chart[(int)Type::Poison][(int)Type::Poison] = 0.5f;
        chart[(int)Type::Poison][(int)Type::Ground] = 0.5f;
        chart[(int)Type::Poison][(int)Type::Rock] = 0.5f;
        chart[(int)Type::Poison][(int)Type::Ghost] = 0.5f;
        chart[(int)Type::Poison][(int)Type::Steel] = 0.0f;
        //Ground type matchups
        chart[(int)Type::Ground][(int)Type::Fire] = 2.0f;
        chart[(int)Type::Ground][(int)Type::Electric] = 2.0f;
        chart[(int)Type::Ground][(int)Type::Poison] = 2.0f;
        chart[(int)Type::Ground][(int)Type::Rock] = 2.0f;
        chart[(int)Type::Ground][(int)Type::Steel] = 2.0f;
        chart[(int)Type::Ground][(int)Type::Grass] = 0.5f;
        chart[(int)Type::Ground][(int)Type::Bug] = 0.5f;
        chart[(int)Type::Ground][(int)Type::Flying] = 0.0f;
        //Flying type matchups
        chart[(int)Type::Flying][(int)Type::Grass] = 2.0f;
        chart[(int)Type::Flying][(int)Type::Fighting] = 2.0f;
        chart[(int)Type::Flying][(int)Type::Bug] = 2.0f;
        chart[(int)Type::Flying][(int)Type::Electric] = 0.5f;
        chart[(int)Type::Flying][(int)Type::Rock] = 0.5f;
        chart[(int)Type::Flying][(int)Type::Steel] = 0.5f;
        //Psychic type matchups
        chart[(int)Type::Psychic][(int)Type::Fighting] = 2.0f;
        chart[(int)Type::Psychic][(int)Type::Poison] = 2.0f;
        chart[(int)Type::Psychic][(int)Type::Psychic] = 0.5f;
        chart[(int)Type::Psychic][(int)Type::Steel] = 0.5f;
        chart[(int)Type::Psychic][(int)Type::Dark] = 0.0f;
        //Bug type matchups
        chart[(int)Type::Bug][(int)Type::Grass] = 2.0f;
        chart[(int)Type::Bug][(int)Type::Psychic] = 2.0f;
        chart[(int)Type::Bug][(int)Type::Dark] = 2.0f;
        chart[(int)Type::Bug][(int)Type::Fire] = 0.5f;
        chart[(int)Type::Bug][(int)Type::Fighting] = 0.5f;
        chart[(int)Type::Bug][(int)Type::Poison] = 0.5f;
        chart[(int)Type::Bug][(int)Type::Flying] = 0.5f;
        chart[(int)Type::Bug][(int)Type::Ghost] = 0.5f;
        chart[(int)Type::Bug][(int)Type::Steel] = 0.5f;
        chart[(int)Type::Bug][(int)Type::Fairy] = 0.5f;
        //Rock type matchups
        chart[(int)Type::Rock][(int)Type::Fire] = 2.0f;
        chart[(int)Type::Rock][(int)Type::Ice] = 2.0f;
        chart[(int)Type::Rock][(int)Type::Flying] = 2.0f;
        chart[(int)Type::Rock][(int)Type::Bug] = 2.0f;
        chart[(int)Type::Rock][(int)Type::Fighting] = 0.5f;
        chart[(int)Type::Rock][(int)Type::Ground] = 0.5f;
        chart[(int)Type::Rock][(int)Type::Steel] = 0.5f;
        //Ghost type matchups
        chart[(int)Type::Ghost][(int)Type::Psychic] = 2.0f;
        chart[(int)Type::Ghost][(int)Type::Ghost] = 2.0f;
        chart[(int)Type::Ghost][(int)Type::Dark] = 0.5f;
        chart[(int)Type::Ghost][(int)Type::Normal] = 0.0f;
        //Dragon type matchups
        chart[(int)Type::Dragon][(int)Type::Dragon] = 2.0f;
        chart[(int)Type::Dragon][(int)Type::Steel] = 0.5f;
        chart[(int)Type::Dragon][(int)Type::Fairy] = 0.0f;
        //Dark type matchups
        chart[(int)Type::Dark][(int)Type::Psychic] = 2.0f;
        chart[(int)Type::Dark][(int)Type::Ghost] = 2.0f;
        chart[(int)Type::Dark][(int)Type::Fighting] = 0.5f;
        chart[(int)Type::Dark][(int)Type::Dark] = 0.5f;
        chart[(int)Type::Dark][(int)Type::Fairy] = 0.5f;
        //Steel type matchups
        chart[(int)Type::Steel][(int)Type::Ice] = 2.0f;
        chart[(int)Type::Steel][(int)Type::Rock] = 2.0f;
        chart[(int)Type::Steel][(int)Type::Fairy] = 2.0f;
        chart[(int)Type::Steel][(int)Type::Fire] = 0.5f;
        chart[(int)Type::Steel][(int)Type::Water] = 0.5f;
        chart[(int)Type::Steel][(int)Type::Electric] = 0.5f;
        chart[(int)Type::Steel][(int)Type::Steel] = 0.5f;
        //Fairy type matchups
        chart[(int)Type::Fairy][(int)Type::Fighting] = 2.0f;
        chart[(int)Type::Fairy][(int)Type::Dragon] = 2.0f;
        chart[(int)Type::Fairy][(int)Type::Dark] = 2.0f;
        chart[(int)Type::Fairy][(int)Type::Fire] = 0.5f;
        chart[(int)Type::Fairy][(int)Type::Poison] = 0.5f;
        chart[(int)Type::Fairy][(int)Type::Steel] = 0.5f;
        return chart;
    }

    const TypeChart::Chart typeChart = initializeChart();
}


namespace TypeChart {
    const Chart& getChart() {
        return typeChart;
    }

    float getEffectiveness(Type attack, Type defense) {
        if (attack == Type::None || defense == Type::None) {
            return 1.0f;
        }
        if (attack == Type::COUNT || defense == Type::COUNT) {
            throw std::invalid_argument("Type::COUNT is not a valid type. ");
        }
        return typeChart[(int)attack][(int)defense];
    }
}
