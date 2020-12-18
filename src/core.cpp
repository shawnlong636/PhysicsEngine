#include "phys/core.hpp"
using namespace phys;

Vector3::Vector3() : x(0), y(0), z(0) { }

Vector3::Vector3(const double x, const double y, const double z) : x(x), y(y), z(z) { }

void Vector3::invert() {
    x *= -1;
    y *= -1;
    z *= -1;
}

double Vector3::dot(const Vector3& vec2) {
    double dotProduct = 0;
    dotProduct += (this->x * vec2.x);
    dotProduct += (this->y * vec2.y);
    dotProduct += (this->z * vec2.z);
    return dotProduct;
}

double Vector3::magnitude() {
    return std::sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2));
}

void Vector3::normalize() {
    double mag = magnitude();
    if (mag>0) { // Avoids Div/0
        x /= mag;
        y /= mag;
        z /= mag;
    }
}

Vector3 Vector3::operator+(const phys::Vector3& vec2) {
    Vector3 vec1(this->x,this->y,this->z);
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    vec1.z += vec2.z;
    return vec1;
}

Vector3 Vector3::operator-(const phys::Vector3& vec2) {
    Vector3 vec1(this->x,this->y,this->z);
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;
    vec1.z -= vec2.z;
    return vec1;
}

Vector3 Vector3::operator*(const double& scalar) {
    Vector3 vec1(this->x,this->y,this->z);
    vec1.x *= scalar;
    vec1.y *= scalar;
    vec1.z *= scalar;
    return vec1;
}