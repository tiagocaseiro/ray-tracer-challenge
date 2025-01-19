#pragma once 

class Tuple
{
public:
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    float w = 0.0;

    bool is_point() const noexcept;
    bool is_vector() const noexcept;

    static Tuple create_point(float x, float y, float z);
    static Tuple create_vector(float x, float y, float z);

    bool operator==(const Tuple&) const;
};