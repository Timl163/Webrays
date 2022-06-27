#include "Canvas.hpp"
#include "Color.hpp"
#include <stdlib.h>
#include <algorithm>
#include <assert.h>
#include <iostream>

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
    return data[w + width*h];
}

void Canvas::setPixel(int w, int h, Color col){
    if (w > width || h > height) return;
    data[w + width*h] = col;
}

unsigned char* Canvas::to_js(Canvas c){
    unsigned char* tmp = (unsigned char*) calloc(c.width*c.height*3, sizeof(unsigned char));
    Color currentcolor = Color(-1,-1,-1);
    for (int i=0; i < c.width*c.height; i++ ){
        currentcolor = (Color)c.data[i];
        if(i == 0){
            std::cout << "from tojs " << currentcolor.r << " " << currentcolor.g << " " << currentcolor.b << std::endl;
            std::cout << "from tojs " << std::max(0, std::min((unsigned char) currentcolor.r * 255, 255)) << std::endl;
        }
        if(i == 7){
            std::cout << "from tojs " << currentcolor.r << " " << currentcolor.g << " " << currentcolor.b << std::endl;
            std::cout << "from tojs " << std::max(0, std::min((int)(currentcolor.g * 255) , 255)) << std::endl;
            std::cout << "from tojs " << (int)currentcolor.g * 255 << std::endl;
        }
        tmp[i*3] = std::max(0, std::min((int) (currentcolor.r * 255), 255));
        tmp[i*3+1] = std::max(0, std::min((int) (currentcolor.g * 255), 255));
        tmp[i*3+2] = std::max(0, std::min((int) (currentcolor.b * 255), 255));
    }
    return tmp;
}
