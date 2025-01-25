#include "canvas.h"

#include <fstream>

static size_t color_component_from_1_to_255(float component)
{
    return std::clamp(component*255.f, 0.f, 255.f);
} 

canvas::canvas(const size_t _width, const size_t _height, const color& default_color): width(_width), height(_height), pixels(_width*_height, default_color)
{
}

void canvas::paint_pixel(const size_t col, const size_t row, const color& color)
{
    size_t index = row*width + col;
    if (index >= pixels.size())
    {
        return;
    }
    pixels[index] = color;
}

void canvas::save_to_file(std::filesystem::path path)
{
    if(path.has_extension() == false)
    {
        path +=".ppm";
    }

  std::ofstream file{path};
  file << "P3" << std::endl;
  file << width << " " << height << std::endl;
  file << 255 << std::endl;
  int i = 0;
  for (auto& pixel : pixels)
  {
    file << color_component_from_1_to_255(pixel.r) << " " << color_component_from_1_to_255(pixel.g)  << " " << color_component_from_1_to_255(pixel.b);
    i++;
    if (i == width){
        i = 0;
        file << std::endl;
    }else
    {
        file << " ";
    }
  }
}

const color& canvas::pixel_at(const size_t col, const size_t row)
{
    size_t index = row*width + col;
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

std::ostream& operator<<(std::ostream& os, const canvas& canvas)
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