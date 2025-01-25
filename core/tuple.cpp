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

tuple tuple::make_point(const float x, const float y, const float z)
{
    return {x, y, z, 1.0f};
}

tuple tuple::make_vector(const float x, const float y, const float z)
{
    return {x, y, z, 0.0f};
}

tuple tuple::zero()
{
    return tuple{0.0f};
}

color::color(const float _r, const float _g, const float _b) : tuple(make_vector(_r, _g, _b))
{
    
}

color::color(const tuple& t) : tuple(t)
{

} 

const color& color::black()
{
    static color black; 
    return black;
}

const color& color::white()
{
    static color red = {1.0f, 1.0f, 1.0f};
    return red;
}

const color& color::red()
{
    static color red = {1.0f, 0.0f, 0.0f};
    return red;
}

color operator*(const color& c1, const color& c2) 
{
    return {c1.r*c2.r,
            c1.g*c2.g,
            c1.b*c2.b};
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
    return tuple::make_vector(a.y*b.z - a.z * b.y, 
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



