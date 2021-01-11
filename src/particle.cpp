#include "phys/particle.hpp"
using namespace phys;

Particle::Particle() {
    inverseMass = 1;
    damping = 0.999;
}

// Mutators

void Particle::setMass(const double mass) {
    if (mass<=0) {
        throw std::invalid_argument("Mass must be greater than zero");
    }
    inverseMass = 1.0 / mass;
}

double Particle::getMass()const {
    if (inverseMass == 0) {
        return std::numeric_limits<double>::max();
    }
    else {
        return 1.0/inverseMass;
    }
}

void Particle::setInverseMass(double inverseMass) {
    if (inverseMass < 0) {
        throw std::invalid_argument("Inverse mass must be greater than or equal to 0");
    }
    this->inverseMass = inverseMass;
}

double Particle::getInverseMass()const {
    return inverseMass;
}

bool Particle::hasFiniteMass()const {
    if (inverseMass == 0 ) {
        return false;
    }
    else {
        return true;
    }
}

void Particle::setDamping(const double damping) {
    if (damping<0) {
        throw std::invalid_argument("Damping must be greater than 0");
    }

    this->damping = damping;
}

double Particle::getDamping()const {
    return damping;
}

void Particle::integrate(double duration) {

    // ERROR CHECKS
    if (inverseMass <= 0.0) {
        return;
    }
    if (duration <=0.0) {
        throw std::invalid_argument("Duration must be greater than 0.0");
    }

    position.addScaledVector(velocity,duration);

    velocity = velocity * std::pow(damping,duration) + acceleration*duration;
}