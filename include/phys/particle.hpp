#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "core.hpp"
#include <stdexcept>
#include <climits>

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
        Particle();

        // Mutators
        void setMass(const double mass);
        double getMass() const;
        void setInverseMass(const double inverseMass);
        double getInverseMass()const;
        bool hasFiniteMass()const;

        void integrate(double duration);
    };
}

#endif // PARTICLE_HPP