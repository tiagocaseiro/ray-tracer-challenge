#include "common.h"

#include <cmath>
#include <limits>

bool equals(const float a, const float b)
{
    return std::fabs(a-b) < std::numeric_limits<float>::epsilon();
}