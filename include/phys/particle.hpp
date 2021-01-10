#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "core.hpp"
#include <stdexcept>

namespace phys {
    class Particle {
    protected:
        Vector3 position;
        Vector3 velocity;
        Vector3 acceleration;
        Vector3 forceAccum;
        double damping;
        double inverseMass;
    public:
        void integrate(double duration);
    };
}

#endif // PARTICLE_HPP