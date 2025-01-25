#include <gtest/gtest.h>

#include "canvas.h"
#include "common.h"

// Demonstrate some basic assertions.
TEST(canvas, Ctor) 
{
  canvas c{10, 20};

  EXPECT_EQ(c.width, 10);
  EXPECT_EQ(c.height, 20);

  for(const auto& pixel : c.get_pixels())
  {
    EXPECT_EQ(pixel, color::black());
  }
}

TEST(canvas, PaintPixel) 
{
  canvas c{10, 20};

  c.paint_pixel(2, 3, color::red());
      
  EXPECT_EQ(c.pixel_at(2, 3), color::red());
}
