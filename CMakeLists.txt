cmake_minimum_required(VERSION 3.10)
project(PokemonStatCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
include_directories(tests)

set(SOURCES
    src/Pokemon.cpp
    src/PokedexEntry.cpp
)

add_executable(run_tests
    tests/test_main.cpp
    tests/test_pokemon.cpp
    tests/catch_amalgamated.cpp
    ${SOURCES}
)
