#ifndef CORE_HPP
#define CORE_HPP
#include <cmath>
#include <stdexcept>

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
        static Vector3 crossProduct(const Vector3& v1, const Vector3& v2);
        double magnitude();
        void normalize();
        static void makeOrthonormalBasis(Vector3* a, Vector3* b, Vector3* c);

        Vector3 operator+(const Vector3& v); // Vector Addition
        Vector3 operator-(const Vector3& v); // Vector Subtraction
        void operator+=(const Vector3& v);
        void operator-=(const Vector3& v);
        Vector3 operator*(const double& scalar); // Scalar Multiplication
        void operator*=(const double& scalar); // Scalar Multiplication
        
    };
}

#endif // CORE_HPP
