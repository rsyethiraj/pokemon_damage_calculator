#pragma once
#include <array>
#include "enums.h"

namespace TypeChart {
    using Chart = std::array<std::array<float, 18>, 18>;

    const Chart& getChart();
    float getEffectiveness(Type attack, Type defense);
}
