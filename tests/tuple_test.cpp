#include <gtest/gtest.h>

#include <cmath>
#include <limits>

#include "tuple.h"

// Demonstrate some basic assertions.
TEST(tuple, IsPoint) 
{
  tuple v{4.3f, -4.2f, 3.1f, 1.0f};

  EXPECT_EQ(v.x, 4.3f);
  EXPECT_EQ(v.y, -4.2f);
  EXPECT_EQ(v.z, 3.1f);
  EXPECT_EQ(v.w, 1.0f);
  EXPECT_TRUE(is_point(v));
  EXPECT_FALSE(is_vector(v));
}

TEST(tuple, IsVector) {
  tuple v{4.3f, -4.2f, 3.1f, 0.0f};

  EXPECT_EQ (v.x, 4.3f);
  EXPECT_EQ (v.y, -4.2f);
  EXPECT_EQ (v.z, 3.1f);
  EXPECT_EQ (v.w, 0.0f);
  EXPECT_TRUE(is_vector(v));
  EXPECT_FALSE(is_point(v));
}

TEST(tuple, PointFactory) {
  tuple v = tuple::create_point(4.f, -4.f, 3.f);
  tuple u = {4.f, -4.f, 3.f, 1.f};

  EXPECT_EQ (v, u);
  EXPECT_TRUE(is_point(v));
  EXPECT_FALSE(is_vector(v));
}

TEST(tuple, VectorFactory) {
  tuple v = tuple::create_vector(4.f, -4.f, 3.f);
  tuple u = {4.f, -4.f, 3.f, 0.f};

  EXPECT_EQ (v, u);
  EXPECT_TRUE(is_vector(v));
  EXPECT_FALSE(is_point(v));
}


TEST(tuple, Equals) 
{
  tuple v = {1.f, 2.f, 3.f, 4.f};
  tuple u = {1.f, 2.f, 3.f, 4.f};

  EXPECT_EQ(v, u);
}

TEST(tuple, NotEqualsX) {
  tuple v = {0, 2.f, 3.f, 4.f};
  tuple u = {1.f, 2.f, 3.f, 4.f};

  EXPECT_NE(v, u);
}

TEST(tuple, NotEqualsY) {
  tuple v = {1.f, 2.f, 3.f, 4.f};
  tuple u = {1.f, 1.f, 3.f, 4.f};

  EXPECT_NE(v, u);
}

TEST(tuple, NotEqualsZ) {
  tuple v = {1.f, 2.f, 1.f, 4.f};
  tuple u = {1.f, 2.f, 3.f, 4.f};

  EXPECT_NE(v, u);
}

TEST(tuple, NotEqualsW) {
  tuple v = {1.f, 2.f, 3.f, 1.f};
  tuple u = {1.f, 2.f, 3.f, 4.f};

  EXPECT_NE(v, u);
}

TEST(tuple, NotEqualsAll) {
  tuple v = {4.f, 3.f, 2.f, 1.f};
  tuple u = {1.f, 2.f, 3.f, 4.f};

  EXPECT_NE(v, u);
}

TEST(tuple, Addition) {
  tuple v = {3.f, -2.f, 5.f, 1.f};
  tuple u = {-2.f, 3.f, 1.f, 0.f};

  tuple expected = {1.f, 1.f, 6.f, 1.f};

  EXPECT_EQ(expected, v+u);
}

TEST(tuple, Subraction) {
  tuple v = tuple::create_point(3.f, 2.f, 1.f);
  tuple u = tuple::create_point(5.f, 6.f, 7.f);
    
  tuple expected = tuple::create_vector(-2.f, -4.f, -6);

  EXPECT_EQ(expected, v-u);

  v = tuple::create_point(3.f, 2.f, 1.f);
  u = tuple::create_vector(5.f, 6.f, 7.f);
    
  expected = tuple::create_point(-2.f, -4.f, -6.f);

  EXPECT_EQ(expected, v-u);

  v = tuple::create_vector(3.f, 2.f, 1.f);
  u = tuple::create_vector(5.f, 6.f, 7.f);
    
  expected = tuple::create_vector(-2.f, -4.f, -6.f);

  EXPECT_EQ(expected, v-u);
  v = tuple::zero();
  u = tuple::create_vector(1.f, -2.f, 3.f);
    
  expected = tuple::create_vector(-1.f, 2.f, -3.f);

  EXPECT_EQ(expected, v-u);

  v = {1.f, -2.f, 3.f, -4.f};

  expected = {-1.f, 2.f, -3.f, 4.f};

  EXPECT_EQ(expected, -v);
}

TEST(tuple, Multiplication) {
  tuple v = {1.f, -2.f, 3.f, -4.f};

  tuple expected = {3.5f, -7.f, 10.5f, -14.f};

  EXPECT_EQ(expected, v*3.5f);
  EXPECT_EQ(expected, 3.5f*v);

  v = {1.f, -2.f, 3.f, -4.f};

  expected = {0.5, -1.f, 1.5f, -2.f};

  EXPECT_EQ(expected, v*0.5f);
  EXPECT_EQ(expected, 0.5f*v);
}

TEST(tuple, Division) {
  tuple v = {1.f, -2.f, 3.f, -4.f};

  tuple expected = {0.5, -1.f, 1.5f, -2.f};

  EXPECT_EQ(expected, v/2.f);
}

TEST(tuple, Length) {
  tuple v = tuple::create_vector(1.f, 0.f, 0.f);

  EXPECT_EQ(length(v), 1.0f);

  v = tuple::create_vector(0.f, 1.f, 0.f);

  EXPECT_EQ(length(v), 1.0f);    
    
  v = tuple::create_vector(0.f, 0.f, 1.f);

  EXPECT_EQ(length(v), 1.0f);

  v = tuple::create_vector(1.f, 2.f, 3.f);

  EXPECT_NEAR(length(v), std::sqrt(14.f), std::numeric_limits<float>::epsilon());

  v = tuple::create_vector(1.f, -2.f, -3.f);

  EXPECT_NEAR(length(v), std::sqrt(14.f), std::numeric_limits<float>::epsilon());
}

TEST(tuple, Normalize) {
  tuple v = tuple::create_vector(4.f, 0.f, 0.f);

  tuple expected = {1.0f, 0.0f, 0.0f, 0.0f};

  EXPECT_EQ(normalize(v), expected);
  
  v = tuple::create_vector(1.f, 2.f, 3.f);

  tuple n = normalize(v);

  expected = {1.0f/std::sqrt(14.f), 2.0f/std::sqrt(14.f), 3.0f/std::sqrt(14.f), 0.0f};

  EXPECT_EQ(n, expected);

  EXPECT_NEAR(length(n), 1.f, std::numeric_limits<float>::epsilon());
}

TEST(tuple, Dot) {
  tuple v = tuple::create_vector(1.f, 2.f, 3.f);
  tuple u = tuple::create_vector(2.f, 3.f, 4.f);

  float expected = 20;

  EXPECT_EQ(dot(v, u), expected);
}

TEST(tuple, Cross) {
  tuple v = tuple::create_vector(1.f, 2.f, 3.f);
  tuple u = tuple::create_vector(2.f, 3.f, 4.f);

  tuple expected = tuple::create_vector(-1.0f, 2.0f, -1.0f);

  EXPECT_EQ(cross(v,u), expected);

  expected = tuple::create_vector(1.0f, -2.0f, 1.0f);

  EXPECT_EQ(cross(u, v), expected);
}


