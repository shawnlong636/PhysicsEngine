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

    Vector3 vec3(-1,-2,-3);
    Vector3 vec4(1,2,3);
    vec3 += vec4;
    
    EXPECT_DOUBLE_EQ(vec3.x,0);
    EXPECT_DOUBLE_EQ(vec3.y,0);
    EXPECT_DOUBLE_EQ(vec3.z,0);

    vec3 += Vector3(9,8,7);

    EXPECT_DOUBLE_EQ(vec3.x,9);
    EXPECT_DOUBLE_EQ(vec3.y,8);
    EXPECT_DOUBLE_EQ(vec3.z,7);
    
}

TEST(VectorTests, CrossProduct) {
    Vector3 v1(1,0,0);
    Vector3 v2(0,1,0);
    Vector3 v3 = v1.crossProduct(v2);

    EXPECT_DOUBLE_EQ(v3.x,0);
    EXPECT_DOUBLE_EQ(v3.y,0);
    EXPECT_DOUBLE_EQ(v3.z,1);

    Vector3 v4(2,3,4);
    Vector3 v5(5,6,7);

    v4 = v4.crossProduct(v5);

    EXPECT_DOUBLE_EQ(v4.x,-3);
    EXPECT_DOUBLE_EQ(v4.y,6);
    EXPECT_DOUBLE_EQ(v4.z,-3);
}

TEST(VectorTests, StaticCrossProduct) {
    Vector3 v1(1,0,0);
    Vector3 v2(0,1,0);
    Vector3 v3 = Vector3::crossProduct(v1,v2);

    EXPECT_DOUBLE_EQ(v3.x,0);
    EXPECT_DOUBLE_EQ(v3.y,0);
    EXPECT_DOUBLE_EQ(v3.z,1);

    Vector3 v4(2,3,4);
    Vector3 v5(5,6,7);

    v4 = Vector3::crossProduct(v4,v5);

    EXPECT_DOUBLE_EQ(v4.x,-3);
    EXPECT_DOUBLE_EQ(v4.y,6);
    EXPECT_DOUBLE_EQ(v4.z,-3);
}

TEST(VectorTests, OrthonormalBasis) {
    Vector3* a = nullptr;
    Vector3* b = nullptr;
    Vector3* c = nullptr;

    EXPECT_THROW(Vector3::makeOrthonormalBasis(a,b,c), std::invalid_argument);

    a = new Vector3(2,4,4);
    b = new Vector3(-1, 5, 2);
    c = new Vector3();
    Vector3::makeOrthonormalBasis(a,b,c);
    
    EXPECT_DOUBLE_EQ(a->x, 1.0/3.0);
    EXPECT_DOUBLE_EQ(a->y,2.0/3.0);
    EXPECT_DOUBLE_EQ(a->z,2.0/3.0);

    EXPECT_DOUBLE_EQ(c->x, -6.0 / std::sqrt(101));
    EXPECT_DOUBLE_EQ(c->y, -4.0 / std::sqrt(101));
    EXPECT_DOUBLE_EQ(c->z, 7.0 / std::sqrt(101));

    EXPECT_DOUBLE_EQ(b->x, -22.0/(3.0*std::sqrt(101)));
    EXPECT_DOUBLE_EQ(b->y, 19.0/(3.0*std::sqrt(101)));
    EXPECT_DOUBLE_EQ(b->z, -8.0/(3.0*std::sqrt(101)));

    delete a;
    delete b;
    delete c;
}

TEST(VectorTests, AddScaledVector) {
    Vector3 v1(0,0,0);
    Vector3 v2(1,1,1);

    v1.addScaledVector(v2,3);

    // Confirm that v1 is correctly modified
    EXPECT_DOUBLE_EQ(v1.x,3);
    EXPECT_DOUBLE_EQ(v1.y,3);
    EXPECT_DOUBLE_EQ(v1.z,3);

    // Confirm that v2 is not modified
    EXPECT_DOUBLE_EQ(v2.x,1);
    EXPECT_DOUBLE_EQ(v2.y,1);
    EXPECT_DOUBLE_EQ(v2.z,1);

    // Test adding scaled version of itself
    v2.addScaledVector(v2,-1);
    
    EXPECT_DOUBLE_EQ(v2.x,0);
    EXPECT_DOUBLE_EQ(v2.y,0);
    EXPECT_DOUBLE_EQ(v2.z,0);

    // Test Scaling by Zero
    Vector3 v3(9,5,1);
    v2.addScaledVector(v2,0);

    EXPECT_DOUBLE_EQ(v3.x,9);
    EXPECT_DOUBLE_EQ(v3.y,5);
    EXPECT_DOUBLE_EQ(v3.z,1);
}

TEST(VectorTest, Clear) {
    Vector3 v1;
    v1.clear();

    EXPECT_DOUBLE_EQ(v1.x,0.0);
    EXPECT_DOUBLE_EQ(v1.y,0.0);
    EXPECT_DOUBLE_EQ(v1.z,0.0);

    Vector3 v2(-99999,1238905792,123454);
    v2.clear();

    EXPECT_DOUBLE_EQ(v2.x,0.0);
    EXPECT_DOUBLE_EQ(v2.y,0.0);
    EXPECT_DOUBLE_EQ(v2.z,0.0);
}

#endif // VECTOR_TEST_HPP
