#include "tuple.h"

#include <cmath>
#include <limits>

static bool equals(float a, float b)
{
    return std::fabs(a-b) < std::numeric_limits<float>::epsilon();
}

bool Tuple::is_point() const noexcept
{
    return equals(w, 1.0f);
}

bool Tuple::is_vector() const noexcept
{
    return equals(w, 0.0f);
}

Tuple Tuple::create_point(float x, float y, float z)
{
    return {x, y, z, 1.0f};
}

Tuple Tuple::create_vector(float x, float y, float z)
{
    return {x, y, z, 0.0f};
}

bool Tuple::operator==(const Tuple& other) const
{
    return equals(x, other.x) && 
           equals(y, other.y)  &&
           equals(z, other.z)  &&
           equals(w, other.w) ;
}
