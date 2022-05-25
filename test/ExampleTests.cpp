#include <gtest/gtest.h>
#include "../Helper.hpp"
#include "../Example.hpp"

TEST(ExampleTests, tuplePoint) {
    Tuple a = Tuple(4.3, -4.2, 3.1, 1.0);
    EXPECT_TRUE(Helper::equal(a.x, 4.3));
    EXPECT_TRUE(Helper::equal(a.y, -4.2));
    EXPECT_TRUE(Helper::equal(a.z, 3.1));
    EXPECT_TRUE(Helper::equal(a.w, 1.0));
    EXPECT_TRUE(a.isPoint());
    EXPECT_TRUE(!a.isVector());
}

TEST(ExampleTests, tupleVector) {
    Tuple a = Tuple(4.3, -4.2, 3.1, 0.0);
    EXPECT_TRUE(Helper::equal(a.x, 4.3));
    EXPECT_TRUE(Helper::equal(a.y, -4.2));
    EXPECT_TRUE(Helper::equal(a.z, 3.1));
    EXPECT_TRUE(Helper::equal(a.w, 0.0));
    EXPECT_TRUE(!a.isPoint());
    EXPECT_TRUE(a.isVector());
}

TEST(ExampleTests, equal){
    Tuple a = Tuple(4.3, -4.2, 3.1, 0.0);
    Tuple b = Tuple(4.3, -4.2, 3.1, 0.0);

    EXPECT_TRUE(Helper::equal(a,b));
}

TEST(ExampleTests, pointConstructor){
    Point a = Point(4.0, -4.0, 3.0);
    EXPECT_TRUE(Helper::equal(a, Tuple(4.0, -4.0, 3.0, 1.0)));
}

TEST(ExampleTests, vectorConstructor){
    Vector a = Vector(4.0, -4.0, 3.0);
    EXPECT_TRUE(Helper::equal(a, Tuple(4.0, -4.0, 3.0, 0.0)));
}

TEST(ExampleTests, tupleAdd){
    Tuple a = Tuple(3, -2, 5, 1);
    Tuple b = Tuple(-2, 3, 1, 0);
    EXPECT_TRUE(Helper::equal(a+b, Tuple(1, 1, 6, 1)));
}

TEST(ExampleTests, tupleSub1){
    Point a = Point(3,2,1);
    Point b = Point(5,6,7);
    EXPECT_TRUE(Helper::equal(a-b, Vector(-2, -4, -6)));
}

TEST(ExampleTests, tupleSub2){
    Point a = Point(3,2,1);
    Vector b = Vector(5,6,7);
    EXPECT_TRUE(Helper::equal(a-b, Point(-2, -4, -6)));
}

TEST(ExampleTests, tupleSub3){
    Vector a = Vector(3,2,1);
    Vector b = Vector(5,6,7);
    EXPECT_TRUE(Helper::equal(a-b, Vector(-2, -4, -6)));
}

TEST(ExampleTests, tupleNeg1){
    Vector zero = Vector(0,0,0);
    Vector b = Vector(1,-2,3);
    EXPECT_TRUE(Helper::equal(zero-b, Vector(-1, 2, -3)));
}

TEST(ExampleTests, tupleNeg2){
    Tuple b = Tuple(1, -2, 3, -4);
    EXPECT_TRUE(Helper::equal(-b, Tuple(-1, 2, -3, 4)));
}

TEST(ExampleTests, tupleMult1){
    Tuple a = Tuple(1, -2, 3, -4);
    a * (float)3.9;
    //EXPECT_TRUE(Helper::equal(a*3.5, Tuple(3.5, -7, 10.5, -14)));
}