#pragma once

#include <span>
#include <array>
#include <algorithm>
#include <cmath>

#include "common.h"
#include "tuple.h"

template<size_t n>
struct mat
{
    explicit mat(const std::array<float,n*n>& _data)
    {
        std::memcpy(&m_data, &_data, sizeof(decltype(_data)));
    }

    mat() = default;
    
    std::span<float> operator[](const size_t x)
    {
        auto begin = std::begin(m_data);
        begin+=(x*n);
        auto end = begin + n;
        return {begin, end};
    }

    std::span<const float> operator[](const size_t x) const
    {
        auto begin = std::cbegin(m_data);
        begin+=(x*n);
        auto end = begin + n;
        return {begin, end};    
    }
    
    const std::array<float,n*n>& data() const
    {
        return m_data;
    }
    
    static const mat<n>& identity()
    {
        auto init_id = []
        {
            mat<n> id;
            for (int i = 0; i < n; i++)
            {
                id.m_data[i*n+i] = 1;
            } 
            return id;
        };
        static mat<n> id = init_id();
        return id;
    }

private:
    std::array<float,n*n>m_data = {0};
};

template<size_t n>
std::ostream& operator<<(std::ostream& os, const mat<n>& mat)
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

        os << mat.data()[i];
    }

    return os;
}

template<size_t n>
bool operator==(const mat<n>& a, const mat<n>& b)
{
    return std::ranges::equal(a.data(), b.data(), equals);
}

template<size_t n>
bool operator!=(const mat<n>& a, const mat<n>& b)
{
    int i = 0;
    for (auto val_a : a.data())
    {
        auto val_b = b.data()[i];
        if (equals(val_a, val_b)== false)
        {
            return true;
        }
        i++;
    }
    return false;
}

template<size_t n>
mat<n> operator*(const mat<n>& a, const mat<n>& b)
{
    mat<n> new_mat;
    
    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != n; j++)
        {
            for (int k = 0; k != n; k++)
            {
                new_mat[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    return new_mat;
}


using mat4 = mat<4>;
using mat3 = mat<3>;
using mat2 = mat<2>;


tuple operator*(const mat4& m, const tuple& t)
{
    return {
        m[0][0]*t.x+m[0][1]*t.y+m[0][2]*t.z+m[0][3]*t.w,
        m[1][0]*t.x+m[1][1]*t.y+m[1][2]*t.z+m[1][3]*t.w,
        m[2][0]*t.x+m[2][1]*t.y+m[2][2]*t.z+m[2][3]*t.w,
        m[3][0]*t.x+m[3][1]*t.y+m[3][2]*t.z+m[3][3]*t.w        
    };
}

