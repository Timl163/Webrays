#include <gtest/gtest.h>
#include "../Helper.hpp"
#include "../Color.hpp"

TEST(ColorTests, constructor){
    Color c = Color(-0.5, 0.4, 1.7);
    EXPECT_TRUE(Helper::equal(c.r, -0.5));
    EXPECT_TRUE(Helper::equal(c.g, 0.4));
    EXPECT_TRUE(Helper::equal(c.b, 1.7));
}

TEST(ColorTests, add){
    Color c1 = Color(0.9, 0.6, 0.75);
    Color c2 = Color(0.7, 0.1, 0.25);
    EXPECT_TRUE(Helper::equal(c1+c2, Color(1.6, 0.7, 1.0)));
}

TEST(ColorTests, sub){
    Color c1 = Color(0.9, 0.6, 0.75);
    Color c2 = Color(0.7, 0.1, 0.25);
    EXPECT_TRUE(Helper::equal(c1-c2, Color(0.2, 0.5, 0.5)));
}

TEST(ColorTests, mul){
    Color c1 = Color(0.2, 0.3, 0.4);
    EXPECT_TRUE(Helper::equal(c1*2, Color(0.4, 0.6, 0.8)));
}