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

#endif // VECTOR_TEST_HPP
