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
        double dotProduct(const Vector3& v);
        Vector3 crossProduct(const Vector3& v);
        double magnitude();
        void normalize();

        Vector3 operator+(const Vector3& v); // Vector Addition
        Vector3 operator-(const Vector3& v); // Vector Subtraction
        void operator+=(const Vector3& v);
        void operator-=(const Vector3& v);
        Vector3 operator*(const double& scalar); // Scalar Multiplication
        void operator*=(const double& scalar); // Scalar Multiplication
        
    };
}

#endif // CORE_HPP
