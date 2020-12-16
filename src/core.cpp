#include "../header/core.hpp"

phys::Vector3::Vector3() : x(0), y(0), z(0) { }

phys::Vector3::Vector3(const double x, const double y, const double z) : x(x), y(y), z(z) { }

void phys::Vector3::invert() {
    x *= -1;
    y *= -1;
    z *= -1;
}