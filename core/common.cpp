#include "common.h"

#include <cmath>
#include <limits>

bool equals(const float a, const float b)
{
    return std::abs(a-b) < EPSILON;
}