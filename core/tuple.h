#pragma once 

#include <iostream>

struct tuple
{
    tuple(const float, const float, const float, const float);
    explicit tuple(const float);
    tuple() = default;

    union { float x = 0.0, r; };
    union { float y = 0.0, g; };
    union { float z = 0.0, b; };
    union { float w = 0.0, a; };
    
    static tuple make_point(const float x, const  float y, const float z);
    static tuple make_vector(const float x, const  float y, const  float z);
    static tuple zero();
};

struct color : tuple
{
    color(const float, const float, const float);
    color(const tuple&);
    color() = default;

    static const color& black();
    static const color& white();
    static const color& red();
};

color operator*(const color&,  const color&);

bool operator==(const tuple&, const tuple&);
bool operator!=(const tuple&, const tuple&);
bool is_point(const tuple&);
bool is_vector(const tuple&);
    
float length(const tuple&);
float dot(const tuple&, const tuple&);

tuple operator+(const tuple&, const tuple&);
tuple operator-(const tuple&, const tuple&);
tuple operator*(const tuple&, const float);
tuple operator*(float, const tuple&);
tuple operator/(const tuple&, const float);
tuple normalize(const tuple&);
tuple cross(const tuple&, const tuple&);
tuple operator-(const tuple&);

std::ostream& operator<<(std::ostream& os,const tuple&);