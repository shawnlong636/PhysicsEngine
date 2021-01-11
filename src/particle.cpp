#include "phys/particle.hpp"
using namespace phys;

Particle::Particle() {
    inverseMass = 1;
    damping = 0.999;
}

/* Mutators & Accessors */

// Mass Methods
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

// Damping Methods
void Particle::setDamping(const double damping) {
    if (damping<0) {
        throw std::invalid_argument("Damping must be greater than 0");
    }

    this->damping = damping;
}

double Particle::getDamping()const {
    return damping;
}

// Position Methods
void Particle::setPosition(const double x, const double y, const double z) {
    position.x = x;
    position.y = y;
    position.z = z;
}

void Particle::setPosition(const Vector3& v) {
    position = v;
}

Vector3 Particle::getPosition()const {
    return position;
}

void Particle::copyPositionTo(Vector3* v) {
    v->x = position.x;
    v->y = position.y;
    v->z = position.z;
}

// Velocity Methods
void Particle::setVelocity(const double x, const double y, const double z) {
    velocity.x = x;
    velocity.y = y;
    velocity.z = z;
}

void Particle::setVelocity(const Vector3& v) {
    velocity = v;
}

Vector3 Particle::getVelocity()const {
    return velocity;
}

void Particle::copyVelocityTo(Vector3* v) {
    v->x = velocity.x;
    v->y = velocity.y;
    v->z = velocity.z;
}

// Acceleration Methods
void Particle::setAcceleration(const double x, const double y, const double z) {
    acceleration.x = x;
    acceleration.y = y;
    acceleration.z = z;
}

void Particle::setAcceleration(const Vector3& v) {
    acceleration = v;
}

Vector3 Particle::getAcceleration()const {
    return acceleration;
}

void Particle::copyAccelerationTo(Vector3* v) {
    v->x = acceleration.x;
    v->y = acceleration.y;
    v->z = acceleration.z;
}

/* Other Methods */
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