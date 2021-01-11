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

TEST(ParticleTest, PositionMutators) {
    Particle p;
    p.setPosition(-3.14,2.82,3.3333);
    EXPECT_DOUBLE_EQ(p.getPosition().x,-3.14);
    EXPECT_DOUBLE_EQ(p.getPosition().y,2.82);
    EXPECT_DOUBLE_EQ(p.getPosition().z,3.3333);

    Vector3 v(1,1,1);
    p.setPosition(v);

    EXPECT_DOUBLE_EQ(p.getPosition().x,1.0);
    EXPECT_DOUBLE_EQ(p.getPosition().y,1.0);
    EXPECT_DOUBLE_EQ(p.getPosition().z,1.0);

    Vector3* v1;
    p.copyPositionTo(v1);

    EXPECT_DOUBLE_EQ(v1->x,1.0);
    EXPECT_DOUBLE_EQ(v1->y,1.0);
    EXPECT_DOUBLE_EQ(v1->z,1.0);
}

TEST(ParticleTest, VelocityMutators) {
    Particle p;
    p.setVelocity(9,-9,9);

    EXPECT_DOUBLE_EQ(p.getVelocity().x,9.0);
    EXPECT_DOUBLE_EQ(p.getVelocity().y,-9.0);
    EXPECT_DOUBLE_EQ(p.getVelocity().z,9.0);

    Vector3 v(-1,-1,-1);
    p.setVelocity(v);

    EXPECT_DOUBLE_EQ(p.getVelocity().x,-1);
    EXPECT_DOUBLE_EQ(p.getVelocity().y,-1);
    EXPECT_DOUBLE_EQ(p.getVelocity().z,-1);

    p.setVelocity(Vector3(0,0,0));
    EXPECT_DOUBLE_EQ(p.getVelocity().x,0.0);
    EXPECT_DOUBLE_EQ(p.getVelocity().y,0.0);
    EXPECT_DOUBLE_EQ(p.getVelocity().z,0.0);

    Vector3* v1;

    p.copyVelocityTo(v1);

    EXPECT_DOUBLE_EQ(v1->x,0.0);
    EXPECT_DOUBLE_EQ(v1->y,0.0);
    EXPECT_DOUBLE_EQ(v1->z,0.0);

}
#endif // PARTICLE_TEST_HPP
