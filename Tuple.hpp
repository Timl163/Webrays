#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <math.h>

class Tuple {
    public:
        float x;
        float y;
        float z;
        float w;

        Tuple(float x_val, float y_val, float z_val, float w_val);

        Tuple operator+( Tuple &other );
        Tuple operator-( Tuple &other );
        Tuple operator-();
        friend Tuple operator*( const Tuple &tuple, const float &other );
        friend Tuple operator*( const float &other, const Tuple &tuple );
        friend Tuple operator/( const Tuple &tuple, const float &other );
        friend Tuple operator/( const float &other, const Tuple &tuple );
        bool isVector();
        bool isPoint();

        static float dot(Tuple a, Tuple b){
            return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
        }
};

class Vector;

class Point: public Tuple{
    public:
        Point() : Tuple(0,0,0,0){}
        Point(float x_val, float y_val, float z_val) : Tuple(x_val, y_val, z_val, 1.0){}

        Point operator+(Vector &other);
};

class Vector: public Tuple{
    public:
        Point test;
        Vector() : Tuple(0,0,0,0){}
        Vector(float x_val, float y_val, float z_val) : Tuple(x_val, y_val, z_val, 0.0){}

        Vector operator+(Vector &other);
        Point operator+(Point &other);

        static float magnitude( Vector vec ){
            return sqrt(pow(vec.x,2) + pow(vec.y,2)+ pow(vec.z,2)+ pow(vec.w,2));
        }

        static Vector norm( Vector vec ){
            float mag = magnitude(vec);
            return Vector(vec.x/mag, vec.y/mag, vec.z/mag);
        }

        static Vector cross(Vector a, Vector b){
            return Vector(a.y * b.z - a.z * b.y,
                            a.z * b.x - a.x * b.z,
                            a.x * b.y - a.y * b.x);
        }
};

#endif /* EXAMPLE_HPP */