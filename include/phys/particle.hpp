#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "core.hpp"

namespace phys {
    class Particle {
protected:
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    double damping;
    };
}

#endif // PARTICLE_HPP