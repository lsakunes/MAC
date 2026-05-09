#ifndef IMAGE_GEN_HPP
#define IMAGE_GEN_HPP

#include "IMAGE/image-global.hpp"
#include <cuda_runtime.h>

namespace image{


/**
 * Test image generator
 * 
 * @param numImages The number of images to generate
 * @param outFolder The folder in which to store the output
 * @param position The camera coord vector position of the satellite.
 * @param rotation The local XYZ euler rotation of the satellite.
 * 
 * @note Every generated image is given a new folder with outFolder with a name "img0", "img1", etc
*/

void image(int numImages, const char* outFolder, vec3 position, vec3 rotation);


/**
 * Test image generator
 * 
 * @param numImages The number of images to generate
 * @param outFolder The folder in which to store the output
 * @param position The camera coord vector position of the satellite.
 *
 * @note random rotations which can see the horizon will be generated
 * @note Every generated image is given a new folder with outFolder with a name "img0", "img1", etc
*/

void image(int numImages, const char* outFolder, vec3 position);


/**
 * Test image generator
 * 
 * @param numImages The number of images to generate
 * @param outFolder The folder in which to store the output
 *
 * @note random positions and rotations which can see the horizon will be generated 
 * @note Every generated image is given a new folder with outFolder with a name "img0", "img1", etc
*/

void image(int numImages, const char* outFolder);

}
#endif