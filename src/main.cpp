#include <iostream>

#include "tuple.h"

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
    projectile p = {tuple::create_point(0, 1, 0), normalize(tuple::create_vector(1, 1, 0))};
    environment e = {tuple::create_vector(0, -0.1, 0), tuple::create_vector(-0.01, 0, 0)};

    while(p.position.y > 0){
        p = tick(e, p);
    }
    
    return 0;
}