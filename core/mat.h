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
    explicit mat(const std::array<float,n*n>& _data = {0}) : m_data(_data)
    {
    }
    
    float& at(const size_t x, const size_t y)
    {
        return m_data[x*n+y];
    }

    float at(const size_t x, const size_t y) const 
    {
        return m_data[x*n+y];
    }
  
    static const mat<n>& identity()
    {
        static auto init_id = []
        {
            std::array<float, n*n> data = {0};
            for (int i = 0; i < n; i++)
            {
                data[i*n+i] = 1;
            } 
            return data;
        };
        static mat<n> id = mat<n>(init_id());
        return id;
    }

private:
    std::array<float,n*n> m_data = {0};
};

using mat4 = mat<4>;
using mat3 = mat<3>;
using mat2 = mat<2>;

template<size_t n>
std::ostream& operator<<(std::ostream& os, const mat<n>& mat)
{
    os << std::fixed << std::setprecision(2);

    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != n; j++)
        {
            os << mat.at(i, j) << " ";
        }
        
        os << std::endl;
    }

    return os;
}

template<size_t n>
bool operator==(const mat<n>& a, const mat<n>& b)
{
    return (a != b) == false; 
}

template<size_t n>
bool operator!=(const mat<n>& a, const mat<n>& b)
{
    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != n; j++)
        {
            if (equals(a.at(i,j), b.at(i,j)) == false)
            {
                return true;
            }
        }
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
mat<n> transpose(const mat<n>& m)
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

tuple operator*(const mat4& m, const tuple& t)
{
    return tuple{
        m.at(0,0)*t.x+m.at(0,1)*t.y+m.at(0,2)*t.z+m.at(0,3)*t.w,
        m.at(1,0)*t.x+m.at(1,1)*t.y+m.at(1,2)*t.z+m.at(1,3)*t.w,
        m.at(2,0)*t.x+m.at(2,1)*t.y+m.at(2,2)*t.z+m.at(2,3)*t.w,
        m.at(3,0)*t.x+m.at(3,1)*t.y+m.at(3,2)*t.z+m.at(3,3)*t.w        
    };
}

template<size_t n>
float determinant(const mat<n>& m)
{
    auto determinant = 0;
    if constexpr (n == 2)
    {
        determinant = m.at(0,0)*m.at(1,1) - m.at(0,1)*m.at(1,0);
    }
    else{
        for (int j = 0; j != n; j++)
        {
            determinant+=(m.at(0,j)*cofactor(m, 0, j));
        }
    }
    
    return determinant;
}


template<size_t n>
mat<n-1> submatrix(const mat<n>& m, const size_t x, const size_t y)
{
    mat<n-1> sub;

    auto m_i   = 0; 
    for (auto sub_i = 0; sub_i != n-1; sub_i++)
    {
        if (m_i == x)
        {
            m_i++;
        }

        auto m_j   = 0; 
        for (auto sub_j = 0; sub_j != n-1; sub_j++)
        {
            if (m_j == y)
            {
                m_j++;
            }
            
            sub.at(sub_i, sub_j) = m.at(m_i, m_j);
            m_j++;
        }
        m_i++;
    }

    return sub;
}

float minor(const auto& m, const size_t x, const size_t y)
{
    return determinant(submatrix(m, x, y));
}


float cofactor(const auto& m, const size_t x, const size_t y)
{
    auto cofactor = minor(m, x, y);

    if ((x+y) % 2 != 0)
    {
        cofactor *= -1;
    }

    return cofactor;
}

bool is_invertible(const auto& m)
{
    return determinant(m) != 0;
}

template<size_t n>
auto inverse(mat<n> m)
{
    float d = determinant(m);
    if (d == 0)
    {
        throw std::domain_error("Attempted to invert a non-invertible matrix");
    }

    mat<n> m_inverse;
    for (int i = 0; i != n; i++)
    {
       for (int j = 0; j != n; j++)
        {
            m_inverse.at(j, i) = cofactor(m, i, j) / d;
        }     
    }

    return m_inverse;
}