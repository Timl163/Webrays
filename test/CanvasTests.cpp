#include <gtest/gtest.h>
#include "../Helper.hpp"
#include "../Canvas.hpp"
#include "../Color.hpp"

TEST(CanvasTests, constructor){
    Canvas c = Canvas(10,20);
    EXPECT_TRUE(c.width == 10);
    EXPECT_TRUE(c.height == 20);
    Color col = Color(0,0,0);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            EXPECT_TRUE(Helper::equal(c.getPixel(i,j),col));
        }
    }
}

TEST(CanvasTests, writePixel){
    Canvas c = Canvas(10,20);
    Color red = Color(1,0,0);
    c.setPixel(2,3,red);
    EXPECT_TRUE(Helper::equal(c.getPixel(2,3),red));
}

TEST(CanvasTests, toJS){
    Canvas c = Canvas(5,3);
    Color c1 = Color(1.5, 0, 0);
    Color c2 = Color(0, 0.5, 0);
    Color c3 = Color(-0.5, 0, 1);

    c.setPixel(0,0,c1);
    c.setPixel(2,1,c2);
    c.setPixel(4,2,c3);

    unsigned char array[45] = { 255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,127,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,255};

    unsigned char* js = Canvas::to_js(c);
    delete[] js;
    EXPECT_TRUE(true);

    /*for(int i = 0; i < 45; i++){
        std::cout << "js " << (unsigned int)js[i] << " test "<< (unsigned int)array[i] << " i= " << i << std::endl;
        std::cout << (js[i] == array[i]) << std::endl;
        EXPECT_TRUE(js[i] == array[i]);
    }
    free(js);*/
}