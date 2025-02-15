#pragma once

#include "ray.h"

tuple position(const ray& r ,const float t)
{
    return r.origin + r.direction * t;
}

std::vector<hit> intersects(const ray& , const sphere& )
{
    return {};
}