#pragma once

#include <vector>
#include <iostream>

#include "tuple.h"

struct canvas
{
    canvas(const size_t _width, const size_t _height);

    const size_t width;
    const size_t height;

    void paint_pixel(const size_t x, const size_t y, const color&);
    
    const color& pixel_at(const size_t x, const size_t y);
    const std::vector<color>& get_pixels() const;
    
private:
    std::vector<color> pixels;
};

std::ostream& operator<<(std::ostream& os,const canvas&);