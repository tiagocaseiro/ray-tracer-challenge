#include <numbers>
#include <chrono>

#include "tuple.h"
#include "canvas.h"
#include "mat.h"

using namespace std::numbers;

static const auto to_the_center  = translate(200, 200, 0);
static const auto two_pi = 2.f*static_cast<float>(pi);
static const auto radius = 50;

void draw_hour_points(canvas& c)
{
     for (auto i = 0; i != 12; i++)
    {
        static const auto step = two_pi/12.f;
        const auto rotation = rotate_z(step*static_cast<float>(i));
        for (auto j = 0; j != 3; j++)
        {            
            auto p = tuple::make_point();
            const auto to_the_right  = translate(radius-static_cast<float>(j), 0, 0);
            p = to_the_center * rotation * to_the_right *p;
            c.paint_pixel(static_cast<size_t>(p.x), static_cast<size_t>(p.y), color::white());
        }
    }
}

void draw_minute_points(canvas& c)
{
    static const auto to_the_right  = translate(radius, 0, 0);
    for (auto i = 0; i != 60; i++)
    {
        static const auto step = two_pi/60.f;
        const auto rotation = rotate_z(step*static_cast<float>(i));
        auto p = tuple::make_point();
        p = to_the_center * rotation * to_the_right *p;
        c.paint_pixel(static_cast<size_t>(p.x), static_cast<size_t>(p.y), color::green());
    }
}

void draw_hour_hand(canvas& c, const std::chrono::hours& hours, const std::chrono::minutes& minutes)
{
    const float hours_ratio = static_cast<float>(hours.count()) + static_cast<float>(minutes.count())/60.f;
    const auto rotation = rotate_z(hours_ratio/12.f *two_pi);
    for(auto i = 0; i != radius/2; i++)
    {
        auto go_up = translate(0, static_cast<float>(-i), 0);
        auto p = tuple::make_point();
        p = to_the_center * rotation * go_up *p;
        c.paint_pixel(static_cast<size_t>(p.x), static_cast<size_t>(p.y), color::blue());
    }
}


void draw_minutes_hand(canvas& c, const std::chrono::minutes& minutes)
{
    for(auto i = 0; i != radius; i++)
    {
        auto go_up = translate(0, static_cast<float>(-i), 0);
        auto rotation = rotate_z(1.f/60.f * static_cast<float>(minutes.count())*two_pi);
        auto p = tuple::make_point();
        p = to_the_center * rotation * go_up *p;
        c.paint_pixel(static_cast<size_t>(p.x), static_cast<size_t>(p.y), color::yellow());
    }
}

int main()
{
    canvas c = {400, 400};

    std::chrono::time_point now = std::chrono::system_clock::now();
    std::chrono::hh_mm_ss time_of_day{now - std::chrono::floor<std::chrono::days>(now)};

    draw_minute_points(c);
    draw_hour_points(c);
    draw_hour_hand(c, time_of_day.hours(), time_of_day.minutes());
    draw_minutes_hand(c, time_of_day.minutes());
   
    c.save_to_file("result");
    
    return 0;
}