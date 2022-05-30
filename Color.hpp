#ifndef COLOR_HPP
#define COLOR_HPP

class Color{
    public:
        float r;
        float g;
        float b;
        float a;

        Color(float r_val, float g_val, float b_val);
        Color operator+( Color &other );
        Color operator-( Color &other );
        Color operator*( Color &other );
        friend Color operator*( const Color &col, const float &other );
        friend Color operator*( const float &other, const Color &col );
        
};

#endif