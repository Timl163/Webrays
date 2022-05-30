#include "Canvas.hpp"
#include "Color.hpp"
#include <stdlib.h>
#include <assert.h>

Canvas::Canvas(unsigned int w, unsigned int h){
    width = w;
    height = h;
    data = (Color*) calloc(w*h,sizeof(Color));
    assert(data);

    for (int i = 0; i<(w*h); i++){
        data[i] = Color(0,0,0);
    }
}

Canvas::~Canvas(){
    free(data);
    data = NULL;
}

Color Canvas::getPixel(int w, int h){
    if (w > width || h > height) return Color(-1,-1,-1);
    return data[w*h];
}

void Canvas::setPixel(int w, int h, Color col){
    data[w*h] = col;
}