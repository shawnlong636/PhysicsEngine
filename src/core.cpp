#include "phys/core.hpp"
using namespace phys;

Vector3::Vector3() : x(0), y(0), z(0) { }

Vector3::Vector3(const double x, const double y, const double z) : x(x), y(y), z(z) { }

void Vector3::invert() {
    x *= -1;
    y *= -1;
    z *= -1;
}

Vector3 Vector3::operator+(const phys::Vector3& vec2) {
    Vector3 vec1;
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    vec1.z += vec2.z;
    return vec1;
}

Vector3 Vector3::operator*(const double& scalar) {
    Vector3 vec1;
    vec1.x *= scalar;
    vec1.y *= scalar;
    vec1.z *= scalar;
    return vec1;
}