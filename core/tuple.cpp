#include "tuple.h"

#include <cmath>

#include "common.h"

tuple::tuple(const float _x, const float _y, const float _z, const float _w) : x(_x), y(_y), z(_z), w(_w)
{
}

tuple::tuple(const float a) : x(a), y(a), z(a), w(a)
{

}

bool is_point(const tuple& tuple)
{
    return equals(tuple.w, 1.0f);
}

bool is_vector(const tuple& tuple)
{
    return equals(tuple.w, 0.0f);
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

color::color(const float r, const float g, const float b) : tuple(create_vector(r, g, b))
{
    
}

color::color(const tuple& other) : tuple(other)
{

}

float& color::red()
{
    return x;
}

float& color::green()
{
    return y;
}

float& color::blue()
{
    return z;
}

bool operator==(const tuple& a, const tuple& b)
{
    return equals(a.x, b.x) && 
           equals(a.y, b.y) &&
           equals(a.z, b.z) &&
           equals(a.w, b.w);
}

bool operator!=(const tuple& a, const tuple& b)
{
    return !(a == b);
}

tuple operator+(const tuple& a, const tuple& b)
{
    return {a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w};
}

tuple operator-(const tuple& a, const tuple& b)
{
    return {a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w};
}

tuple operator*(const tuple& tuple, const float scalar)
{
 return {tuple.x*scalar, tuple.y*scalar, tuple.z*scalar, tuple.w*scalar};
}

tuple operator*(float scalar, const tuple& tuple)
{
    return tuple*scalar;
}
tuple operator/(const tuple& tuple, const float scalar)
{
    return {tuple.x/scalar, tuple.y/scalar, tuple.z/scalar, tuple.w/scalar};
}

float length(const tuple& tuple)
{
    return std::sqrt(tuple.x*tuple.x + tuple.y*tuple.y + tuple.z*tuple.z + tuple.w*tuple.w);
}

float dot(const tuple& a, const tuple& b)
{
    return a.x*b.x + 
           a.y*b.y + 
           a.z*b.z + 
           a.w*b.w;
}

tuple normalize(const tuple& tuple)
{
    const float l = length(tuple);
    return {tuple.x/l, tuple.y/l, tuple.z/l, tuple.w/l};
}

tuple cross(const tuple& a, const tuple& b)
{
    return tuple::create_vector(a.y*b.z - a.z * b.y, 
                         a.z*b.x - a.x * b.z,
                         a.x*b.y - a.y * b.x);
}

tuple operator-(const tuple& tuple)
{
    return tuple*-1;
}

std::ostream& operator<<(std::ostream& os, const tuple& tuple)
{
    os << "["<< tuple.x << " " << tuple.y << " " << tuple.z << " " << tuple.w << "]"; 
    return os;
}



