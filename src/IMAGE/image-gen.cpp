#include "IMAGE/image-gen.hpp"
#include <iostream>

namespace image{
    void image(int numImages, const char* outFolder, vec3 position, vec3 rotation){

    }

    void image(int numImages, const char* outFolder, vec3 position){

    }

    void image(int numImages, const char* outFolder){
        std::cout << "Hello from Image! Outputting files to a folder starting with " << *outFolder << std::endl;
    }
}