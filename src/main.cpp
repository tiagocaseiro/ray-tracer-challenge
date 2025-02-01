#include "tuple.h"
#include "canvas.h"

struct projectile
{
    tuple position;
    tuple velocity;
};

struct environment
{
    tuple gravity;
    tuple wind;
};

projectile tick(const environment& env, const projectile& p)
{
    tuple new_position = p.position + p.velocity;
    tuple new_velocity = p.velocity + env.gravity + env.wind;
    return {new_position, new_velocity};
}

int main()
{
    canvas c = {900, 550};
    projectile p = {tuple::make_point(0.0f, 1.0f, 0.0f), normalize(tuple::make_vector(1.0f, 1.8f, 0.0f))* 11.25f};
    environment e = {tuple::make_vector(0.0f, -0.1f, 0.0f), tuple::make_vector(-0.01, 0.0f, 0.0f)};

    c.paint_pixel(p.position.x, c.height - p.position.y, color::white());
    while(p.position.y > 0){
        p = tick(e, p);
        c.paint_pixel(p.position.x, c.height - p.position.y, color::white());
    }
    
    c.save_to_file("result");
    
    return 0;
}