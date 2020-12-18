#ifndef CORE_HPP
#define CORE_HPP
#include <cmath>

namespace phys {
    class Vector3 {
    public:
        double x;
        double y;
        double z;
    
        Vector3();
        Vector3(const double x, const double y, const double z);
        void invert();
        double dot(const Vector3& vec2);
        double magnitude();
        void normalize();

        Vector3 operator+(const Vector3& vec2); // Vector Addition
        Vector3 operator-(const Vector3& vec2); // Vector Subtraction
        Vector3 operator*(const double& scalar); // Scalar Multiplication
        
    };
}

#endif // CORE_HPP
