#ifndef GLOBAL_HPP
#define GLOBAL_HPP

  //////////////////////
 ////// INCLUDES //////
//////////////////////
#include <Eigen/Dense>


  //////////////////////
 ////// TYPEDEFS //////
//////////////////////
using GLOBAL_Vec3 = Eigen::Vector3d;
using GLOBAL_Vec2 = Eigen::Vector2d;
using GLOBAL_Mat3 = Eigen::Matrix3d;
using GLOBAL_Quaternion = Eigen::Quaterniond;


  ///////////////////////
 ////// CONSTANTS //////
///////////////////////

// Distances
#define LEO_MAX_ALTITUDE 2000
#define LEO_MIN_ALTITUDE  160

#define EARTH_POLAR_RADIUS 6357
#define EARTH_EQUATORIAL_RADIUS 6378

inline GLOBAL_Vec3 GLOBAL_EARTH_AXES(EARTH_EQUATORIAL_RADIUS, EARTH_EQUATORIAL_RADIUS, EARTH_POLAR_RADIUS);

// Camera
#define X_RESOLUTION 700
#define Y_RESOLUTION 700
#define FOCAL_LENGTH 0.035 // meters
#define PIXEL_PITCH 0.000005 // meters
#define MIN_FOV 0.0998 // radians; The smallest fov of the camera. Idk why it's so small I may have messed smth up

// Math
#define PI 3.14159265359

#endif