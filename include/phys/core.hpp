#ifndef CORE_HPP
#define CORE_HPP

namespace phys {
    class Vector3 {
    private:
        double pad;
    public:
        double x;
        double y;
        double z;
    
        Vector3();
        Vector3(const double x, const double y, const double z);
        void invert();
    };
}

#endif // CORE_HPP