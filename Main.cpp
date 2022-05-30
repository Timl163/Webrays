#include <iostream>
#include "Tuple.hpp"
#include "Helper.hpp"


class Projectile{
    public: 
        Point position;
        Vector velocity;
        Projectile(Point pos, Vector vel);
};

Projectile::Projectile(Point pos, Vector vel){
    position = pos;
    velocity = vel;
}

class Environment{
    public:
        Vector gravity;
        Vector wind;
        Environment(Vector grav, Vector win);
};

Environment::Environment(Vector grav, Vector win){
    gravity = grav;
    wind = win;
}

Projectile tick(Environment env, Projectile proj){
    Point position = proj.position + proj.velocity;
    Vector velocity = proj.velocity + env.gravity + env.wind;
    return Projectile(position,velocity);
}

int main(){
    Projectile p = Projectile(Point(0,1,0), Vector::norm(Vector(1,1,0)));
    Environment e = Environment(Vector(0,-0.1,0), Vector(0.01, 0, 0));

    while (p.position.y >= 0){
        std::cout << "x: " << p.position.x << " y: " << p.position.y << "\n";
        p = tick(e,p);
    }
}