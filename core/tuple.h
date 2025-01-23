#pragma once 

#include <iostream>

struct tuple
{
    tuple(const float, const float, const float, const float);
    explicit tuple(const float);

    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    float w = 0.0;
    
    static tuple create_point(const float x, const  float y, const float z);
    static tuple create_vector(const float x, const  float y, const  float z);
    static tuple zero();
};

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