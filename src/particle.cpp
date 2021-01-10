#include "phys/particle.hpp"
using namespace phys;

Particle::Particle() {
    inverseMass = 1;
    damping = 0.999;
}

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