#ifndef IMAGE_GEN_HPP
#define IMAGE_GEN_HPP

#include "IMAGE/image-global.hpp"
#include <string>

// I would like to define some metric for determining
// whether an image is expected to behave nicely (i.e well lit)
// This way we can differentiate MAC's general
// performance and MAC's performance on "clean" images
// #define MIN_CLEAN_ILLUMINATION_ANGLE

namespace image{

class GenericImageGenerator{
    public:

    GenericImageGenerator() {}
    ~GenericImageGenerator() {}
    /**
    * Generate a certain amount of test images with fixed position and rotation
    * 
    * Generating multiple may be useful to test MAC's performance against noise
    * 
    * @param numImages The number of images to generate
    * @param outFolder The folder in which to store the output
    * @param position The camera coord vector position of the satellite.
    * @param rotation The local Quaternion rotation of the satellite.
    * 
    * @note Images that cannot see the horizon may be generated (duh)
    * @note Every generated image is given a new folder with outFolder with a name "img0", "img1", etc
    */

    void generateImages(int numImages, std::string outFolder, Vec3 position, Quaternion rotation);


    /**
    * Generate a certain amount of test images with fixed position and random rotation
    * 
    * @param numImages The number of images to generate
    * @param outFolder The folder in which to store the output
    * @param position The camera coord vector position of the satellite.
    *
    * @note Only images which can see the horizon will be generated
    * @note Every generated image is given a new folder with outFolder with a name "img0", "img1", etc
    */

    void generateImages(int numImages, std::string outFolder, Vec3 position);


    /**
    * Generate a certain amount of test images with random position and rotation
    * 
    * @param numImages The number of images to generate
    * @param outFolder The folder in which to store the output
    *
    * @note Only images which can see the horizon will be generated
    * @note Every generated image is given a new folder with outFolder with a name "img0", "img1", etc
    */

    void generateImages(int numImages, std::string outFolder);

    protected:


    /**
    * Generates a random position within the altitude range
    * 
    * @param minAltitude (Optional) The minimum altitude. Default value uses global value
    * @param maxAltitude (Optional) The maximum altitude. Default value uses global value
    *
    * @return A Vec3 pointing from the planetary body's center to the satellite in km
    *
    */
    
    Vec3 generatePosition(double minAltitude = LEO_MIN_ALTITUDE, double maxAltitude = LEO_MAX_ALTITUDE);


    /**
    * Generates a random rotation that contains the horizon
    * 
    * @param position The position in km
    * @param fov (Optional) A circular FOV (radians) to contain the horizon within. Default value uses global MIN_FOV.
    * @param axes (Optional) A matrix describing the axes of the body. Default value uses global value.
    *
    * @return A quaternion describing the rotation from a camera facing positive Z
    * @note An unrotated camera's forward vector faces positive Z, right vector faces positive X, and up vector faces negative Y
    *
    */
    
    Quaternion generateRotation(Vec3 position, double fov = MIN_FOV, Vec3 axes = EARTH_AXES);

    /**
    * Generate a test image at a fixed position and rotation
    * 
    * @param position    The camera coord vector position of the satellite.
    * @param rotation    The local Quaternion rotation of the satellite.
    * @param focalLength (Optional) The focal length of the camera. Default value uses global value.
    * @param xResolution (Optional) The x resolution of the camera. Default value uses global value.
    * @param yResolution (Optional) The y resolution of the camera. Default value uses global value.
    * @param pixelPitch  (Optional) The pixel pitch of the camera.  Default value uses global value.
    * 
    */

    virtual void generateImage(Vec3 position, Quaternion rotation, std::string path, double focalLength = FOCAL_LENGTH, int xResolution = X_RESOLUTION, int yResolution = Y_RESOLUTION, double pixelPitch = PIXEL_PITCH) = 0;
};

class ExampleImageGenerator : public GenericImageGenerator {
    public:
    ExampleImageGenerator() : GenericImageGenerator() {}
    ~ExampleImageGenerator() {}
    protected:
    /**
    * Generate a test image at a fixed position and rotation
    * 
    * @param position    The camera coord vector position of the satellite.
    * @param rotation    The local Quaternion rotation of the satellite.
    * @param focalLength (Optional) The focal length of the camera. Default value uses global value.
    * @param xResolution (Optional) The x resolution of the camera. Default value uses global value.
    * @param yResolution (Optional) The y resolution of the camera. Default value uses global value.
    * @param pixelPitch  (Optional) The pixel pitch of the camera.  Default value uses global value.
    * 
    */

    void generateImage(Vec3 position, Quaternion rotation, std::string path, double focalLength = FOCAL_LENGTH, int xResolution = X_RESOLUTION, int yResolution = Y_RESOLUTION, double pixelPitch = PIXEL_PITCH) override;
};

}
#endif