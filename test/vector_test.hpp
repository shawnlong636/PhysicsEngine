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
    EXPECT_DOUBLE_EQ(a.dot(b), 122);

    Vector3 c(1,2,3);
    Vector3 d(4,-5,6);
    EXPECT_DOUBLE_EQ(c.dot(d), 12);

    Vector3 e(5,0,-7);
    Vector3 f(7,2,5);
    EXPECT_DOUBLE_EQ(e.dot(f),0); // Orthogonal Vectors
}

#endif // VECTOR_TEST_HPP