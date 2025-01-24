#include "common.h"

#include <cmath>
#include <limits>

static constexpr float EPSILON = 0.000001;

bool equals(const float a, const float b)
{
    return std::abs(a-b) < EPSILON;
}