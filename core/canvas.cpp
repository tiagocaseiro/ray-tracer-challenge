#include "canvas.h"

canvas::canvas(const size_t _width, const size_t _height): width(_width), height(_height), pixels(_width*_height, color::black())
{
}

void canvas::paint_pixel(const size_t x, const size_t y, const color& color)
{
    size_t index = x*width + y;
    if (index >= pixels.size())
    {
        return;
    }
    pixels[index] = color;
}

const color& canvas::pixel_at(const size_t x, const size_t y)
{
    size_t index = x*width + y;
    if (index >= pixels.size())
    {
        return color::black();
    }
    return pixels[index];
}

const std::vector<color>& canvas::get_pixels() const
{
    return pixels;
}

std::ostream& operator<<(std::ostream& os,const canvas& canvas)
{
    size_t i = 0;
    for (auto& pixel : canvas.get_pixels())
    {
        if (i == canvas.width){
            i = 0;
            os << std::endl;
        }
        os << pixel << " ";
        i++;
    }
    return os;
}