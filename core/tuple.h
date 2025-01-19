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

    bool is_point() const;
    bool is_vector() const;
    
    static tuple create_point(const float x, const  float y, const float z);
    static tuple create_vector(const float x, const  float y, const  float z);
    static tuple zero();

    bool operator==(const tuple&) const;

    tuple operator+(const tuple&) const;
    tuple operator-(const tuple&) const;
    tuple operator*(const float)  const;
    tuple operator/(const float)  const;

    float length()  const;
    tuple normalized() const;
};

std::ostream& operator<<(std::ostream& os,const tuple&);
tuple operator-(const tuple&);
tuple operator*(float, const tuple&);
