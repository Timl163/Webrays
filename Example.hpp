#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

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
        Tuple operator*( float &other );
        Tuple operator/( float &other );
        bool isVector();
        bool isPoint();

};

class Point: public Tuple{
    public:
        Point(float x_val, float y_val, float z_val) : Tuple(x_val, y_val, z_val, 1.0){}
};

class Vector: public Tuple{
    public:
        Vector(float x_val, float y_val, float z_val) : Tuple(x_val, y_val, z_val, 0.0){}
};

#endif /* EXAMPLE_HPP */