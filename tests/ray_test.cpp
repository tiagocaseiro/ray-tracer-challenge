#include <gtest/gtest.h>

#include <sstream>
#include <fstream>

#include "ray.h"

TEST(ray, Ctor) 
{
  tuple origin    = make_point(1, 2, 3);
  tuple direction = make_vector(4, 5, 6);
  ray r = ray{origin, direction}; 

  EXPECT_EQ(r.origin, origin);
  EXPECT_EQ(r.direction, direction);
}

TEST(ray, Position) 
{
  tuple origin    = make_point(2, 3, 4);
  tuple direction = make_vector(1, 0, 0);
  ray r = ray{origin, direction}; 
  
  EXPECT_EQ(position(r, 0.f), origin);
  EXPECT_EQ(position(r, 1.f),  make_point(3, 3, 4));
  EXPECT_EQ(position(r, -1.f), make_point(1, 3, 4));
  EXPECT_EQ(position(r, 2.5f), make_point(4.5, 3, 4));
}
