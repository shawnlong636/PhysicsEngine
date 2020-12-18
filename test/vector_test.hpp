#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP

#include "gtest/gtest.h"
#include "phys/core.hpp"
using namespace phys;

TEST(VectorTests, Add) {
    Vector3 vec = Vector3(1,2,3);
    EXPECT_TRUE(true);
}

#endif // VECTOR_TEST_HPP
