#include <memory>
#include <iostream>
#include "IMAGE/image-gen.hpp"

int main() {
    std::cout << "Hello World!" << std::endl;
    std::unique_ptr<image::GenericImageGenerator> imageGen = std::make_unique<image::ExampleImageGenerator>();
    imageGen->generateImages(5, "./data", GLOBAL_Vec3(5, 5, 5), GLOBAL_Quaternion(1, 0, 0, 0));
    return 0;
}