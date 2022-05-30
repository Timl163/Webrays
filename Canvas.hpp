#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "Color.hpp"

class Canvas{
    public:
        unsigned int width;
        unsigned int height;

        Color *data;

        Canvas(unsigned int w, unsigned int h);
        ~Canvas();

        Color getPixel(int w, int h);
        void setPixel(int w, int h, Color col);
};

#endif