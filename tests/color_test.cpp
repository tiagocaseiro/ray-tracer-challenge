#include <gtest/gtest.h>

#include <cmath>
#include <limits>

#include "tuple.h"

// Demonstrate some basic assertions.
TEST(color, Ctor) 
{
  color c{-0.5f, 0.4f, 1.7f};

  EXPECT_NEAR(c.red(), -0.5, std::numeric_limits<float>::epsilon());
  EXPECT_NEAR(c.green(), 0.4, std::numeric_limits<float>::epsilon());
  EXPECT_NEAR(c.blue(), 1.7, std::numeric_limits<float>::epsilon());
}

TEST(color, Addition) {
  color c1{0.9f, 0.6f, 0.75f};
  color c2{0.7f, 0.1f, 0.25f};

  color c3 = c1 + c2;
  
  color expected =  {1.6f, 0.7, 1.0f};

  EXPECT_EQ(c3, expected);
}

TEST(color, Subtraction) {
  color c1{0.9f, 0.6f, 0.75f};
  color c2{0.7f, 0.1f, 0.25f};

  color c3 = c1 - c2;
  
  color expected =  {0.2f, 0.5, 0.5f};

  EXPECT_EQ(c3, expected);
}

TEST(color, Multiplication) {
  color c1{0.2f, 0.3f, 0.4};

  color expected =  {0.4f, 0.6f, 0.8f};

  EXPECT_EQ(c1*2, expected);
}