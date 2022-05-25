#include "Example.hpp"
#include "Helper.hpp"

Tuple::Tuple(float x_val, float y_val, float z_val, float w_val){
    x = x_val;
    y = y_val;
    z = z_val; 
    w = w_val;
}

bool Tuple::isPoint(){
    return Helper::equal(w, 1.0);
}

bool Tuple::isVector(){
    return Helper::equal(w, 0.0);
}

Tuple Tuple::operator+( Tuple &other ){
    return Tuple(x + other.x, y + other.y, z + other.z, w + other.w);
}

Tuple Tuple::operator-( Tuple &other ){
    return Tuple(x - other.x, y - other.y, z - other.z, w - other.w);
}

Tuple Tuple::operator-(){
    return Tuple(-x , -y, -z, -w);
}

Tuple operator*( const Tuple &tuple, const float &other ){
    return Tuple(tuple.x*other, tuple.y*other, tuple.z*other, tuple.w*other);
}

Tuple operator*( const float &other, const Tuple &tuple){
    return tuple * other;
}
