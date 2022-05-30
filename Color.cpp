#include "Color.hpp"

Color::Color(float r_val, float g_val, float b_val){
    r = r_val;
    g = g_val;
    b = b_val;
}

Color Color::operator+( Color &other ){
    return Color(r+other.r, g+other.g, b+other.b);
}

Color Color::operator-( Color &other ){
    return Color(r-other.r, g-other.g, b-other.b);
}

Color Color::operator*( Color &other ){
    return Color(r*other.r, g*other.g, b*other.b);
}

Color operator*(const Color &col, const float &other){
    return Color(col.r*other, col.g*other, col.b*other);
}

Color operator*(const float &other, const Color &col){
    return col*other;
}