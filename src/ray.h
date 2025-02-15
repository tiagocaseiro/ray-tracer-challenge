#pragma once

#include <vector>

#include "tuple.h"
#include "figures.h"

struct ray
{
    tuple origin;
    tuple direction;
};

struct hit 
{
    float t;
};

[[nodiscard]] tuple position(const ray& r ,const float t);

[[nodiscard]] std::vector<hit> intersects(const ray& r, const sphere& s);