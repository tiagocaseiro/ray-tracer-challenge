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
    
    float& at(const size_t x, const size_t y)
    {
        return m_data[x*n+y];
    }

    const float at(const size_t x, const size_t y) const 
    {
        return m_data[x*n+y];
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
                id.at(i,i) = 1;
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
                new_mat.at(i,j) += (a.at(i,k) * b.at(k, j));
            }
        }
    }

    return new_mat;
}

template<size_t n>
mat<n> transpose(const mat<n> m)
{
    mat<n> new_m;
    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != n; j++)
        {
            new_m.at(i,j) = m.at(j,i);
        }
    }
    return new_m;
}


using mat4 = mat<4>;
using mat3 = mat<3>;
using mat2 = mat<2>;


tuple operator*(const mat4& m, const tuple& t)
{
    return {
        m.at(0,0)*t.x+m.at(0,1)*t.y+m.at(0,2)*t.z+m.at(0,3)*t.w,
        m.at(1,0)*t.x+m.at(1,1)*t.y+m.at(1,2)*t.z+m.at(1,3)*t.w,
        m.at(2,0)*t.x+m.at(2,1)*t.y+m.at(2,2)*t.z+m.at(2,3)*t.w,
        m.at(3,0)*t.x+m.at(3,1)*t.y+m.at(3,2)*t.z+m.at(3,3)*t.w        
    };
}


float determinant(const mat2& m)
{
    return m.at(0,0)*m.at(1,1) - m.at(0,1)*m.at(1,0);
}
