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

        /* Mutators */

        // Mass Mutators
        void setMass(const double mass);
        double getMass() const;
        void setInverseMass(const double inverseMass);
        double getInverseMass()const;
        bool hasFiniteMass()const;

        // Damping Mutators
        void setDamping(const double damping);
        double getDamping()const;

        // Position Mutators
        void setPosition(const double x, const double y, const double z);
        void setPosition(const Vector3& v);
        Vector3 getPosition()const;
        void copyPositionTo(Vector3* v);

        // Velocity Mutators
        void setVelocity(const double x, const double y, const double z);
        void setVelocity(const Vector3& v);
        Vector3 getVelocity()const;
        void copyVelocityTo(Vector3* v);

        /* Other Methods */
        void integrate(double duration);
    };
}

#endif // PARTICLE_HPP