#include "phys/particle.hpp"
using namespace phys;

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