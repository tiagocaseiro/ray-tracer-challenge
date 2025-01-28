#pragma once

#include <span>
#include <array>
#include <algorithm>
#include <cmath>

template<size_t n>
struct mat
{
    explicit mat(const std::array<float,n*n>&);
    std::span<float> operator[](const size_t x);
private:
    std::array<float,n*n>m_data = {0};
    
    template<size_t n1>
    friend std::ostream& operator<<(std::ostream& os, mat<n1> mat);
};

template<size_t n>
mat<n>::mat(const std::array<float,n*n>& data) 
{
    std::memcpy(&m_data, &data, sizeof(decltype(data)));
}

template<size_t n>
std::span<float> mat<n>::operator[](const size_t x)
{
    return {std::begin(m_data)+(x*n), std::begin(m_data)+(x*n+n)};
}

template<size_t n>
std::ostream& operator<<(std::ostream& os, mat<n> mat)
{
    os << std::fixed << std::setprecision(2);
    for (int i = 0; i != n*n; i++)
    {
        if (i !=0 && i % n == 0)
        {
            os << std::endl;
        }
        else if (i != 0)
        {
            os << " ";
        }

        os << mat.m_data[i];
    }

    return os;
}

using mat4 = mat<4>;
using mat3 = mat<3>;
using mat2 = mat<2>;
