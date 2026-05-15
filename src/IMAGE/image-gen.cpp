#include "IMAGE/image-gen.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

namespace image{
    void GenericImageGenerator::generateImages(int numImages, std::string outFolder, Vec3 position, Quaternion rotation){
        try {
            // Check if path exists and is a directory
            if (!fs::exists(outFolder)) {
                if (fs::create_directory(outFolder)) {
                    std::cout << "Data folder created successfully: " << outFolder << "\n";
                } else {
                    std::cerr << "Folder could not be created.\n";
                }
            }
            if (!fs::is_directory(outFolder)){
                std::cerr << "Path already exists as file bozo\n";
            }
        } catch (const fs::filesystem_error& e) {
            // Handle errors (e.g., permission denied, invalid path)
            std::cerr << "Filesystem error: " << e.what() << '\n';
        }
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
        try {
            if (!fs::exists(path)) {
                if (fs::create_directory(path)) {
                    std::cout << "Image folder created successfully: " << path << "\n";
                } else {
                    std::cerr << "Folder could not be created.\n";
                }                
            }
            if (!fs::is_directory(path)){
                std::cerr << "Path already exists as file bozo\n";
            }
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Filesystem error: " << e.what() << '\n';
        }
        try {
            std::cout << "rendering image to " << path << "\n";
            cv::Mat image = cv::Mat::zeros(yResolution, xResolution, CV_8UC1);
            cv::rectangle(image, cv::Point(position[0]-100, position[1]-100), cv::Point(position[0]+100, position[1]+100), 255, 2);
            std::string filename = path + "/testImage.png";
            if (!cv::imwrite(filename, image)) {
                std::cerr << "Error: Could not save image to " << filename << std::endl;
            }

            std::cout << "Image saved to " << filename << std::endl;
        }
            catch (const cv::Exception& e) {
            std::cerr << "OpenCV error: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Standard exception: " << e.what() << std::endl;
        }

    }
}