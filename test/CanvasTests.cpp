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