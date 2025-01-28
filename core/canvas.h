#pragma once

#include <vector>
#include <iostream>
#include <filesystem> 

#include "tuple.h"

struct canvas
{
    canvas(const size_t _width, const size_t _height, const color& default_color = color::black());

    const size_t width;
    const size_t height;

    void paint_pixel(const size_t col, const size_t row, const color&);
    void save_to_file(std::filesystem::path);

    const color& pixel_at(const size_t col, const size_t row);
    const std::vector<color>& get_pixels() const;
    
private:
    std::vector<color> m_pixels;
};

std::ostream& operator<<(std::ostream& os,const canvas&);