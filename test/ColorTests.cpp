#include <gtest/gtest.h>
#include "../Helper.hpp"
#include "../Color.hpp"

TEST(ColorTests, constructor){
    Color c = Color(-0.5, 0.4, 1.7);
    EXPECT_TRUE(Helper::equal(c.r, -0.5));
    EXPECT_TRUE(Helper::equal(c.g, 0.4));
    EXPECT_TRUE(Helper::equal(c.b, 1.7));
}