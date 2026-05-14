#include "IMAGE/image-gen.hpp"
#include <iostream>

namespace image{
    void GenericImageGenerator::generateImages(int numImages, std::string outFolder, Vec3 position, Quaternion rotation){
        for (int i = 0; i < numImages; i++){
            generateImage(position, rotation, outFolder + "/" + std::to_string(i));
        }
    }

    void GenericImageGenerator::generateImages(int numImages, std::string outFolder, Vec3 position){
        // TODO
    }

    void GenericImageGenerator::generateImages(int numImages, std::string outFolder){
        // TODO
    }

    Vec3 GenericImageGenerator::generatePosition(double minAltitude, double maxAltitude){
        // TODO
        return Vec3(0,0,0);
    }

    Quaternion GenericImageGenerator::generateRotation(Vec3 position, double fov, Vec3 axes){
        // TODO
        return Quaternion(1,0,0,0);
    }

    
    void ExampleImageGenerator::generateImage(Vec3 position, Quaternion rotation, std::string path, double focalLength, int xResolution, int yResolution, double pixelPitch){
        std::cout << "rendering image to " << path << "\n";
    }
}