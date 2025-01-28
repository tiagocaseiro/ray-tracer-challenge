#include <gtest/gtest.h>

#include <sstream>
#include <fstream>

#include "mat.h"

TEST(mat4, At) 
{
    mat4 mat({
                   1.f,   2.f,   3.f,   4.f,
                   5.5f,  6.5f,  7.5f,  8.5f,
                   9.f,   10.f,  11.f,  12.f,
                   13.5f, 14.5f, 15.5f, 16.5f
                });

    EXPECT_EQ(mat[0][0], 1);        
    EXPECT_EQ(mat[0][3], 4);     
    EXPECT_EQ(mat[1][0], 5.5);        
    EXPECT_EQ(mat[1][2], 7.5);     
    EXPECT_EQ(mat[2][2], 11);        
    EXPECT_EQ(mat[3][0], 13.5);     
    EXPECT_EQ(mat[3][2], 15.5);  
}

TEST(mat2, At) 
{
    mat2 mat({
                   -3.f,  5.f,   
                    1.f, -2.f
                });

    EXPECT_EQ(mat[0][0], -3);        
    EXPECT_EQ(mat[0][1], 5);     
    EXPECT_EQ(mat[1][0], 1);        
    EXPECT_EQ(mat[1][1], -2);
}

TEST(mat3, At) 
{
    mat3 mat({
                   -3.f,   5.f,   0.f,
                   1.f,   -2.f,   -7.f,
                   0.f,   1.f,   1.f,
                });

    EXPECT_EQ(mat[0][0], -3);        
    EXPECT_EQ(mat[1][1], -2);        
    EXPECT_EQ(mat[2][2], 1);        
}
