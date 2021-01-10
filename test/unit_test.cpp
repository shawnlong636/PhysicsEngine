#include "gtest/gtest.h"
#include "vector_test.hpp"
#include "particle_test.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}