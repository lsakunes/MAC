#ifndef IMAGE_GLOBAL_HPP
#define IMAGE_GLOBAL_HPP

#include "common/global.hpp"

namespace image{
    using Vec3 = GLOBAL_Vec3;
    using Vec2 = GLOBAL_Vec2;
    using Mat3 = GLOBAL_Mat3;
    using Quaternion = GLOBAL_Quaternion;
    
    inline Vec3 EARTH_AXES = GLOBAL_EARTH_AXES;
}

#endif