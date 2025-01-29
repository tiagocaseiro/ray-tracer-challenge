#include <gtest/gtest.h>

#include <sstream>
#include <fstream>

#include "mat.h"
#include "tuple.h"

TEST(mat4, At) 
{
    mat4 mat({
                   1.f,   2.f,   3.f,   4.f,
                   5.5f,  6.5f,  7.5f,  8.5f,
                   9.f,   10.f,  11.f,  12.f,
                   13.5f, 14.5f, 15.5f, 16.5f
                });

    EXPECT_EQ(mat.at(0,0), 1);        
    EXPECT_EQ(mat.at(0,3), 4);     
    EXPECT_EQ(mat.at(1,0), 5.5);        
    EXPECT_EQ(mat.at(1,2), 7.5);     
    EXPECT_EQ(mat.at(2,2), 11);        
    EXPECT_EQ(mat.at(3,0), 13.5);     
    EXPECT_EQ(mat.at(3,2), 15.5);  
}

TEST(mat2, At) 
{
    mat2 mat({
                   -3.f,  5.f,   
                    1.f, -2.f
                });

    EXPECT_EQ(mat.at(0,0), -3);        
    EXPECT_EQ(mat.at(0,1), 5);     
    EXPECT_EQ(mat.at(1,0), 1);        
    EXPECT_EQ(mat.at(1,1), -2);
}

TEST(mat3, At) 
{
    mat3 mat({
                   -3.f,   5.f,   0.f,
                   1.f,   -2.f,   -7.f,
                   0.f,   1.f,   1.f,
                });

    EXPECT_EQ(mat.at(0,0), -3);        
    EXPECT_EQ(mat.at(1,1), -2);        
    EXPECT_EQ(mat.at(2,2), 1);        
}


TEST(mat4, Equals) 
{
    mat4 mat_a({
                   1.f,   2.f,   3.f,   4.f,
                   5.f,  6.f,  7.f,  8.f,
                   9.f,   8.f,  7.f,  6.f,
                   5.f, 4.f, 3.f, 2.f
                });

    mat4 mat_b({
                   1.f,   2.f,   3.f,   4.f,
                   5.f,  6.f,  7.f,  8.f,
                   9.f,   8.f,  7.f,  6.f,
                   5.f, 4.f, 3.f, 2.f
                });

    EXPECT_EQ(mat_a, mat_b);    
    EXPECT_FALSE(mat_a != mat_b);
}

TEST(mat4, NotEquals) 
{
    mat4 mat_a({
                   1.f,   2.f,   3.f,   4.f,
                   5.f,  6.f,  7.f,  8.f,
                   9.f,   8.f,  7.f,  6.f,
                   5.f, 4.f, 3.f, 2.f
                });

    mat4 mat_b({
                   2.f,   3.f,   4.f,   5.f,
                   6.f,  7.f,  8.f,  9.f,
                   8.f,   7.f,  6.f,  5.f,
                   4.f, 3.f, 2.f, 1.f
                });

    EXPECT_NE(mat_a, mat_b);    
    EXPECT_TRUE(mat_a != mat_b);
}

TEST(mat4, Multiplication) 
{
    mat4 mat_a({
                   1.f,   2.f,   3.f,   4.f,
                   5.f,  6.f,  7.f,  8.f,
                   9.f,   8.f,  7.f,  6.f,
                   5.f, 4.f, 3.f, 2.f
                });

    mat4 mat_b({
                   -2.f,   1.f,   2.f,   3.f,
                   3.f,  2.f,  1.f,  -1.f,
                   4.f,   3.f,  6.f,  5.f,
                   1.f, 2.f, 7.f, 8.f
                });

    mat4 result({
                   20.f,  22.f,   50.f,   48.f,
                   44.f,  54.f,  114.f,  108.f,
                   40.f,   58.f,  110.f,  102.f,
                   16.f, 26.f, 46.f, 42.f
                });

    EXPECT_EQ(mat_a*mat_b, result);    
}

TEST(mat4, MultiplicationTuple) 
{
    mat4 m({
                   1.f,   2.f,   3.f,   4.f,
                   2.f,  4.f,  4.f,  2.f,
                   8.f,   6.f,  4.f,  1.f,
                   0.f,   0.f,  0.f   ,1.f
                });

    tuple t{1, 2, 3, 1};

    tuple expected{18, 24, 33, 1};

    EXPECT_EQ(m*t, expected);    
}

TEST(mat4, MultiplicationIdentity) 
{
    mat4 m({
                1.f,   2.f,   3.f,   4.f,
                5.5f,  6.5f,  7.5f,  8.5f,
                9.f,   10.f,  11.f,  12.f,
                13.5f, 14.5f, 15.5f, 16.5f
            });
                
    EXPECT_EQ(m*mat4::identity(), m);    
}

TEST(mat4, MultiplicationIdentityTuple) 
{
    tuple t{1, 2, 3, 4};

    EXPECT_EQ(mat4::identity()*t, t);    
}

TEST(mat4, Transpose) 
{
    mat4 m({
                0.f,   9.f,   3.f,   0.f,
                9.f,   8.f,   0.f,   8.f,
                1.f,   8.f,   5.f,   3.f,
                0.f,   0.f,   5.f,   8.f
            });

    mat4 expected({
                0.f,   9.f,   1.f,   0.f,
                9.f,   8.f,   8.f,   0.f,
                3.f,   0.f,   5.f,   5.f,
                0.f,   8.f,   3.f,   8.f
            });
                
    EXPECT_EQ(transpose(m),expected);    
}

TEST(mat4, TransposeIdentity) 
{
    EXPECT_EQ(transpose(mat4::identity()),mat4::identity());    
}

TEST(mat2, Determinant) 
{
    mat2 m({
                   1.f,  5.f,   
                   -3.f, 2.f
                });

    EXPECT_EQ(determinant(m), 17.f);    
}


