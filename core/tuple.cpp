#include "tuple.h"

#include <cmath>

#include "common.h"

tuple::tuple(const float _x, const float _y, const float _z, const float _w) : x(_x), y(_y), z(_z), w(_w)
{
}

tuple::tuple(const float a) : x(a), y(a), z(a), w(a)
{

}

bool tuple::is_point() const
{
    return equals(w, 1.0f);
}

bool tuple::is_vector() const
{
    return equals(w, 0.0f);
}

tuple tuple::create_point(const float x, const float y, const float z)
{
    return {x, y, z, 1.0f};
}

tuple tuple::create_vector(const float x, const float y, const float z)
{
    return {x, y, z, 0.0f};
}

tuple tuple::zero()
{
    return tuple{0.0f};
}

bool tuple::operator==(const tuple& other) const
{
    return equals(x, other.x) && 
           equals(y, other.y) &&
           equals(z, other.z) &&
           equals(w, other.w);
}

tuple tuple::operator+(const tuple& other) const
{
    return {x+other.x, y+other.y, z+other.z, w+other.w};
}

tuple tuple::operator-(const tuple& other) const
{
    return {x-other.x, y-other.y, z-other.z, w-other.w};
}

tuple tuple::operator*(const float scalar) const
{
 return {x*scalar, y*scalar, z*scalar, w*scalar};
}

tuple tuple::operator/(const float scalar)  const
{
    return {x/scalar, y/scalar, z/scalar, w/scalar};
}

float tuple::length() const
{
    return std::sqrt(x*x + y*y + z*z + w*w);
}

tuple tuple::normalized() const
{
    const float l = length();
    return {x/l, y/l, z/l, w/l};
}


std::ostream& operator<<(std::ostream& os, const tuple& tuple)
{
    os << "["<< tuple.x << " " << tuple.y << " " << tuple.z << " " << tuple.w << "]"; 
    return os;
}

tuple operator-(const tuple& tuple)
{
    return tuple*-1;
}

tuple operator*(float scalar, const tuple& tuple)
{
    return tuple*scalar;
}