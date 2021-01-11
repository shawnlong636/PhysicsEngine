#ifndef PARTICLE_TEST_HPP
#define PARTICLE_TEST_HPP

#include "gtest/gtest.h"
#include "phys/particle.hpp"
using namespace phys;

TEST(ParticleTest,MassMutators) {
    Particle p;
    EXPECT_DOUBLE_EQ(p.getMass(),1.0);

    EXPECT_THROW(p.setMass(0),std::invalid_argument);
    EXPECT_THROW(p.setMass(0.0),std::invalid_argument);
    EXPECT_THROW(p.setMass(-1.0),std::invalid_argument);

    p.setMass(3.0);

    EXPECT_DOUBLE_EQ(p.getMass(),3.0);
}

TEST(ParticleTest,InverseMassMutators) {
    Particle p;
    EXPECT_DOUBLE_EQ(p.getInverseMass(),1.0);
    EXPECT_THROW(p.setInverseMass(-1.2345),std::invalid_argument);

    p.setInverseMass(0.0);
    EXPECT_DOUBLE_EQ(p.getInverseMass(),0.0);
}

TEST(ParticleTest,HasFiniteMass) {
    Particle p;
    EXPECT_TRUE(p.hasFiniteMass());
    p.setInverseMass(0);
    EXPECT_FALSE(p.hasFiniteMass());
}

TEST(ParticleTest,DampingMutators) {
    Particle p;
    EXPECT_DOUBLE_EQ(p.getDamping(), 0.999);
    
    EXPECT_THROW(p.setDamping(-1.2),std::invalid_argument);

    p.setDamping(3.14159);
    EXPECT_DOUBLE_EQ(p.getDamping(),3.14159);
}
#endif // PARTICLE_TEST_HPP
