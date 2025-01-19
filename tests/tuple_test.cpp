#include <gtest/gtest.h>

#include "tuple.h"

// Demonstrate some basic assertions.
TEST(Tuple, IsPoint) 
{
  Tuple t{4.3f, -4.2f, 3.1f, 1.0f};

  EXPECT_EQ(t.x, 4.3f);
  EXPECT_EQ(t.y, -4.2f);
  EXPECT_EQ(t.z, 3.1f);
  EXPECT_EQ(t.w, 1.0f);
  EXPECT_TRUE(t.is_point());
  EXPECT_FALSE(t.is_vector());
}

TEST(Tuple, IsVector) {
  Tuple t{4.3f, -4.2f, 3.1f, 0.0f};

  EXPECT_EQ (t.x, 4.3f);
  EXPECT_EQ (t.y, -4.2f);
  EXPECT_EQ (t.z, 3.1f);
  EXPECT_EQ (t.w, 0.0f);
  EXPECT_TRUE(t.is_vector());
  EXPECT_FALSE(t.is_point());
}

TEST(Tuple, PointFactory) {
  Tuple a = Tuple::create_point(4, -4, 3);
  Tuple b = {4, -4, 3, 1};

  EXPECT_EQ (a, b);
  EXPECT_TRUE(a.is_point());
  EXPECT_FALSE(a.is_vector());
}

TEST(Tuple, VectorFactory) {
  Tuple a = Tuple::create_vector(4, -4, 3);
  Tuple b = {4, -4, 3, 0};

  EXPECT_EQ (a, b);
  EXPECT_TRUE(a.is_vector());
  EXPECT_FALSE(a.is_point());
}


TEST(Tuple, Equals) 
{
    Tuple a = {1, 2, 3, 4};
    Tuple b = {1, 2, 3, 4};

    EXPECT_EQ(a, b);
}


TEST(Tuple, NotEqualsX) {
    Tuple a = {0, 2, 3, 4};
    Tuple b = {1, 2, 3, 4};

    EXPECT_NE(a, b);
}

TEST(Tuple, NotEqualsY) {
    Tuple a = {1, 2, 3, 4};
    Tuple b = {1, 1, 3, 4};

    EXPECT_NE(a, b);
}

TEST(Tuple, NotEqualsZ) {
    Tuple a = {1, 2, 1, 4};
    Tuple b = {1, 2, 3, 4};

    EXPECT_NE(a, b);
}

TEST(Tuple, NotEqualsW) {
    Tuple a = {1, 2, 3, 1};
    Tuple b = {1, 2, 3, 4};

    EXPECT_NE(a, b);
}

TEST(Tuple, NotEqualsAll) {
    Tuple a = {4, 3, 2, 1};
    Tuple b = {1, 2, 3, 4};

    EXPECT_NE(a, b);
}