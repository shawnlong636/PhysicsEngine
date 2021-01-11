#include "phys/core.hpp"
using namespace phys;

Vector3::Vector3() : x(0), y(0), z(0) { }

Vector3::Vector3(const double x, const double y, const double z) : x(x), y(y), z(z) { }

/* Other Methods */

void Vector3::invert() {
    x *= -1;
    y *= -1;
    z *= -1;
}

double Vector3::dotProduct(const Vector3& v) {
    double dotProduct = 0;
    dotProduct += (this->x * v.x);
    dotProduct += (this->y * v.y);
    dotProduct += (this->z * v.z);
    return dotProduct;
}

Vector3 Vector3::crossProduct(const Vector3& v) {
    Vector3 cp;
    cp.x = (this->y * v.z) - (this->z * v.y);
    cp.y = (this->z * v.x) - (this->x * v.z);
    cp.z = (this->x * v.y) - (this->y * v.x);
    return cp;
}

Vector3 Vector3::crossProduct(const Vector3& v1, const Vector3& v2) {
    Vector3 vec;
    vec.x = (v1.y * v2.z) - (v1.z * v2.y);
    vec.y = (v1.z * v2.x) - (v1.x * v2.z);
    vec.z = (v1.x * v2.y) - (v1.y * v2.x);
    return vec;
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

void Vector3::makeOrthonormalBasis(Vector3* a, Vector3* b, Vector3* c) {
    if (!(a && b && c)) {
        throw std::invalid_argument("Vectors a and b must be non-null");
    }
    a->normalize();

    *c = Vector3::crossProduct(*a,*b);
    c->normalize();
    *b = Vector3::crossProduct(*c,*a);
    /* Normalizing b is unnecessary since a and c are
    both normal and orthogonal. For LH coord sys, reverse
    order of both of the cross products (b x a and c x a)  */
}

void Vector3::addScaledVector(const Vector3& v, const double& scalar) {
    this->x += v.x*scalar;
    this->y += v.y*scalar;
    this->z += v.z*scalar;
}

void Vector3::clear() {
    x = 0;
    y = 0;
    z = 0;
}

/* Operator Overloaders */

Vector3 Vector3::operator+(const phys::Vector3& v) {
    Vector3 vec1(this->x,this->y,this->z);
    vec1.x += v.x;
    vec1.y += v.y;
    vec1.z += v.z;
    return vec1;
}

Vector3 Vector3::operator-(const phys::Vector3& v) {
    Vector3 vec1(this->x,this->y,this->z);
    vec1.x -= v.x;
    vec1.y -= v.y;
    vec1.z -= v.z;
    return vec1;
}

void Vector3::operator+=(const Vector3& v) {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}

void Vector3::operator-=(const Vector3& v) {
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}

Vector3 Vector3::operator*(const double& scalar) {
    Vector3 vec1(this->x,this->y,this->z);
    vec1.x *= scalar;
    vec1.y *= scalar;
    vec1.z *= scalar;
    return vec1;
}

void Vector3::operator*=(const double& scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
}