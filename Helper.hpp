#ifndef HELPER_HPP
#define HELPER_HPP

#include <cmath>
#include "Example.hpp"

class Helper{
    private:
        inline static double epsilon = 0.00001;

    public:
        static bool equal(float a, float b){
            if (std::abs(a - b) < epsilon){
                return true;
            } else {
                return false;
            }
        }

        static bool equal(Tuple a, Tuple b){
            if (equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z) && equal(a.w, b.w)){
                return true;
            }
            return false;
        }
};

#endif