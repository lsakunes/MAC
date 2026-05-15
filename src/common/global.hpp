#ifndef GLOBAL_HPP
#define GLOBAL_HPP

  //////////////////////
 ////// INCLUDES //////
//////////////////////
#include <Eigen/Dense>
#include <cmath>

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

// Distances (km)
constexpr double LEO_MAX_ALTITUDE = 2000.0;
constexpr double LEO_MIN_ALTITUDE = 160.0;
constexpr double EARTH_POLAR_RADIUS = 6357.0;
constexpr double EARTH_EQUATORIAL_RADIUS = 6378.0;

inline const GLOBAL_Vec3 GLOBAL_EARTH_AXES(EARTH_EQUATORIAL_RADIUS, EARTH_EQUATORIAL_RADIUS, EARTH_POLAR_RADIUS);

// Camera
constexpr double X_RESOLUTION = 700.0;
constexpr double Y_RESOLUTION = 700.0;
constexpr double FOCAL_LENGTH = 0.05;
constexpr double SENSORWIDTH  = 36 * 0.001;
constexpr double SENSORHEIGHT = 36 * 0.001; 
constexpr double MIN_FOV = 0.0998;

// World
inline GLOBAL_Vec3 GLOBAL_SUN_DIRECTION = GLOBAL_Vec3(0, 2, 3).normalized();

// Math
#ifndef PI
constexpr double PI = 3.14159265358979323846;
#endif

  ///////////////////////////////
 ////// DERIVED VARIABLES //////
///////////////////////////////

constexpr double X_PIXEL_PITCH  = SENSORWIDTH/X_RESOLUTION;
constexpr double Y_PIXEL_PITCH  = SENSORHEIGHT/Y_RESOLUTION;
constexpr double GLOBAL_DX = FOCAL_LENGTH / X_PIXEL_PITCH;
constexpr double GLOBAL_DY = FOCAL_LENGTH / Y_PIXEL_PITCH;

// Ellipsoid Diagonal Matrices
inline const GLOBAL_Mat3 GLOBAL_DIAG_AXES = GLOBAL_EARTH_AXES.asDiagonal();
inline const GLOBAL_Mat3 GLOBAL_DIAG_INV_AXES = GLOBAL_EARTH_AXES.cwiseInverse().asDiagonal();

// Camera Intrinsic Matrix (K)
inline const GLOBAL_Mat3 GLOBAL_K_MAT = [] {
    GLOBAL_Mat3 K;
    K << GLOBAL_DX, 0,         X_RESOLUTION / 2.0,
         0,         GLOBAL_DY, Y_RESOLUTION / 2.0,
         0,         0,         1.0;
    return K;
}();

// Inverse Camera Intrinsic Matrix (invK)
inline const GLOBAL_Mat3 GLOBAL_INV_K_MAT = [] {
    GLOBAL_Mat3 invK;
    invK << 1.0 / GLOBAL_DX, 0,              -(X_RESOLUTION) / (2.0 * GLOBAL_DX),
            0,               1.0 / GLOBAL_DY, -(Y_RESOLUTION) / (2.0 * GLOBAL_DY),
            0,               0,               1.0;
    return invK;
}();

  ////////////////////////
 ////// FUNCTIONS ///////
////////////////////////

inline GLOBAL_Mat3 get_TPC(const GLOBAL_Quaternion& q) {
    return q.normalized().toRotationMatrix();
}

inline GLOBAL_Mat3 get_Ac(const GLOBAL_Quaternion& q) {
    GLOBAL_Vec3 ap_diag = GLOBAL_EARTH_AXES.array().square().inverse().matrix();
    GLOBAL_Mat3 Ap = ap_diag.asDiagonal();
    GLOBAL_Mat3 TPC = get_TPC(q);
    return TPC * Ap * TPC.transpose();
}

#endif