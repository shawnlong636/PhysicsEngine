#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP

#include "gtest/gtest.h"
#include "phys/core.hpp"
using namespace phys;

TEST(VectorTests, ScalarMult) {
    Vector3 vec = Vector3(1,2,3);
    vec = vec * 3;

    EXPECT_DOUBLE_EQ(vec.x, 3);
    EXPECT_DOUBLE_EQ(vec.y, 6);
    EXPECT_DOUBLE_EQ(vec.z, 9);

    vec = vec * -1;

    EXPECT_DOUBLE_EQ(vec.x, -3);
    EXPECT_DOUBLE_EQ(vec.y, -6);
    EXPECT_DOUBLE_EQ(vec.z, -9);
}

TEST(VectorTests, VectorAddition) {
    Vector3 v1 = Vector3(-1,1,2);
    Vector3 v2 = Vector3(4,3,14);
    Vector3 v3 = v1 + v2;

    EXPECT_DOUBLE_EQ(v3.x, v1.x + v2.x);
    EXPECT_DOUBLE_EQ(v3.y, v1.y + v2.y);
    EXPECT_DOUBLE_EQ(v3.z, v1.z + v2.z);
}

TEST(VectorTests, Add_ScalarMult) {
    Vector3 vec = Vector3(5,5,5);

    Vector3 vec2 = Vector3(1,2,3);

    Vector3 vec3 = vec + (vec2 * -1);

    EXPECT_DOUBLE_EQ(vec3.x, vec.x - vec2.x);
    EXPECT_DOUBLE_EQ(vec3.y, vec.y - vec2.y);
    EXPECT_DOUBLE_EQ(vec3.z, vec.z - vec2.z);
}

TEST(VectorTests, VectorSubtraction) {
    Vector3 vec(5,7,11);
    Vector3 vec2(1,3,5);
    Vector3 vec3(2,4,6);
    Vector3 vec4 = vec - vec2 - vec3;
    EXPECT_DOUBLE_EQ(vec4.x,vec.x - vec2.x - vec3.x);
    EXPECT_DOUBLE_EQ(vec4.y,vec.y - vec2.y - vec3.y);
    EXPECT_DOUBLE_EQ(vec4.z,vec.z - vec2.z - vec3.z);
}

TEST(VectorTests, DotProduct) {
    Vector3 a(9,2,7);
    Vector3 b(4,8,10);
    EXPECT_DOUBLE_EQ(a.dotProduct(b), 122);

    Vector3 c(1,2,3);
    Vector3 d(4,-5,6);
    EXPECT_DOUBLE_EQ(c.dotProduct(d), 12);

    Vector3 e(5,0,-7);
    Vector3 f(7,2,5);
    EXPECT_DOUBLE_EQ(e.dotProduct(f),0); // Orthogonal Vectors
}

TEST(VectorTests, Magnitude) {
    Vector3 v1(-1,-1,-1);
    EXPECT_DOUBLE_EQ(v1.magnitude(),std::sqrt(3.0));

    Vector3 v2;
    EXPECT_DOUBLE_EQ(v2.magnitude(),0);

    Vector3 v3(5,15,-7);
    EXPECT_DOUBLE_EQ(v3.magnitude(),std::sqrt(v3.x*v3.x + v3.y*v3.y + v3.z*v3.z) );
}

TEST(VectorTests, Normalize) {
    Vector3 vec(3,4,5);
    vec.normalize();
    EXPECT_DOUBLE_EQ(vec.x, 3.0/std::sqrt(50));
    EXPECT_DOUBLE_EQ(vec.y, 4.0/std::sqrt(50));
    EXPECT_DOUBLE_EQ(vec.z, 5.0/std::sqrt(50));

    Vector3 vec2;
    ASSERT_NO_THROW(vec2.normalize());
    EXPECT_DOUBLE_EQ(vec2.x, 0);
    EXPECT_DOUBLE_EQ(vec2.y, 0);
    EXPECT_DOUBLE_EQ(vec2.z, 0);
}

TEST(VectorTests, AdditionAssignment) {
    Vector3 vec;
    Vector3 vec2(1,2,3);
    vec += vec2;
    EXPECT_DOUBLE_EQ(vec.x,1.0);
    EXPECT_DOUBLE_EQ(vec.y,2.0);
    EXPECT_DOUBLE_EQ(vec.z,3.0);
}

#endif // VECTOR_TEST_HPP
