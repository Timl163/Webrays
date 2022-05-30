#include <gtest/gtest.h>
#include "../Helper.hpp"
#include "../Tuple.hpp"


TEST(TupleTests, tuplePoint) {
    Tuple a = Tuple(4.3, -4.2, 3.1, 1.0);
    EXPECT_TRUE(Helper::equal(a.x, 4.3));
    EXPECT_TRUE(Helper::equal(a.y, -4.2));
    EXPECT_TRUE(Helper::equal(a.z, 3.1));
    EXPECT_TRUE(Helper::equal(a.w, 1.0));
    EXPECT_TRUE(a.isPoint());
    EXPECT_TRUE(!a.isVector());
}

TEST(TupleTests, tupleVector) {
    Tuple a = Tuple(4.3, -4.2, 3.1, 0.0);
    EXPECT_TRUE(Helper::equal(a.x, 4.3));
    EXPECT_TRUE(Helper::equal(a.y, -4.2));
    EXPECT_TRUE(Helper::equal(a.z, 3.1));
    EXPECT_TRUE(Helper::equal(a.w, 0.0));
    EXPECT_TRUE(!a.isPoint());
    EXPECT_TRUE(a.isVector());
}

TEST(TupleTests, equal){
    Tuple a = Tuple(4.3, -4.2, 3.1, 0.0);
    Tuple b = Tuple(4.3, -4.2, 3.1, 0.0);

    EXPECT_TRUE(Helper::equal(a,b));
}

TEST(TupleTests, pointConstructor){
    Point a = Point(4.0, -4.0, 3.0);
    EXPECT_TRUE(Helper::equal(a, Tuple(4.0, -4.0, 3.0, 1.0)));
}

TEST(TupleTests, vectorConstructor){
    Vector a = Vector(4.0, -4.0, 3.0);
    EXPECT_TRUE(Helper::equal(a, Tuple(4.0, -4.0, 3.0, 0.0)));
}

TEST(TupleTests, tupleAdd){
    Tuple a = Tuple(3, -2, 5, 1);
    Tuple b = Tuple(-2, 3, 1, 0);
    EXPECT_TRUE(Helper::equal(a+b, Tuple(1, 1, 6, 1)));
}

TEST(TupleTests, tupleSub1){
    Point a = Point(3,2,1);
    Point b = Point(5,6,7);
    EXPECT_TRUE(Helper::equal(a-b, Vector(-2, -4, -6)));
}

TEST(TupleTests, tupleSub2){
    Point a = Point(3,2,1);
    Vector b = Vector(5,6,7);
    EXPECT_TRUE(Helper::equal(a-b, Point(-2, -4, -6)));
}

TEST(TupleTests, tupleSub3){
    Vector a = Vector(3,2,1);
    Vector b = Vector(5,6,7);
    EXPECT_TRUE(Helper::equal(a-b, Vector(-2, -4, -6)));
}

TEST(TupleTests, tupleNeg1){
    Vector zero = Vector(0,0,0);
    Vector b = Vector(1,-2,3);
    EXPECT_TRUE(Helper::equal(zero-b, Vector(-1, 2, -3)));
}

TEST(TupleTests, tupleNeg2){
    Tuple b = Tuple(1, -2, 3, -4);
    EXPECT_TRUE(Helper::equal(-b, Tuple(-1, 2, -3, 4)));
}

TEST(TupleTests, tupleMult1){
    Tuple a = Tuple(1, -2, 3, -4);
    EXPECT_TRUE(Helper::equal(a*3.5, Tuple(3.5, -7, 10.5, -14)));
}

TEST(TupleTests, tupleMult2){
    Tuple a = Tuple(1, -2, 3, -4);
    EXPECT_TRUE(Helper::equal(a*0.5, Tuple(0.5, -1, 1.5, -2)));
}

TEST(TupleTests, tupleDiv){
    Tuple a = Tuple(1, -2, 3, -4);
    EXPECT_TRUE(Helper::equal(a/2, Tuple(0.5, -1, 1.5, -2)));
}

TEST(TupleTests, magnitude1){
    Vector a = Vector(1,0,0);
    EXPECT_TRUE(Vector::magnitude(a) == 1);
}

TEST(TupleTests, magnitude2){
    Vector a = Vector(0,1,0);
    EXPECT_TRUE(Vector::magnitude(a) == 1);
}

TEST(TupleTests, magnitude3){
    Vector a = Vector(0,0,1);
    EXPECT_TRUE(Vector::magnitude(a) == 1);
}

TEST(TupleTests, magnitude4){
    Vector a = Vector(1,2,3);
    EXPECT_TRUE(Helper::equal(Vector::magnitude(a), sqrt(14)));
}

TEST(TupleTests, magnitude5){
    Vector a = Vector(-1,-2,-3);
    EXPECT_TRUE(Helper::equal(Vector::magnitude(a), sqrt(14)));
}

TEST(TupleTests, norm1){
    Vector v = Vector(4,0,0);
    EXPECT_TRUE(Helper::equal(Vector::norm(v), Vector(1,0,0)));
}

TEST(TupleTests, norm2){
    Vector v = Vector(1,2,3);
    EXPECT_TRUE(Helper::equal(Vector::norm(v), Vector(1/sqrt(14),2/sqrt(14),3/sqrt(14))));
}

TEST(TupleTests, norm3){
    Vector v = Vector(1,2,3);
    Vector norm = Vector::norm(v);
    EXPECT_TRUE(Helper::equal(Vector::magnitude(norm), 1));
}

TEST(TupleTests, dotProduct){
    Vector a = Vector(1,2,3);
    Vector b = Vector(2,3,4);
    EXPECT_TRUE(Helper::equal(Tuple::dot(a,b), 20));
}

TEST(TupleTests, crossProduct){
    Vector a = Vector(1,2,3);
    Vector b = Vector(2,3,4);
    EXPECT_TRUE(Helper::equal(Vector::cross(a,b), Vector(-1,2,-1)));
    EXPECT_TRUE(Helper::equal(Vector::cross(b,a), Vector(1,-2,1)));
}
