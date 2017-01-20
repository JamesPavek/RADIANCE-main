#include "camera.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <fstream>
#include <thread>
#include <chrono>
#include "../include/raspicam/raspicam_still.h"

namespace RADIANCE{
  Camera::Camera() {}
  Camera::~Camera() {}

  void Camera::Initialize() {

    // Initialize camera library
    if (!raspicam_still_.open()) {
      std::cout<<"Error opening camera"<<std::endl;
    }

    // Configure the image
    raspicam_still_.setCaptureSize(640,480);
    raspicam_still_.setEncoding(raspicam::RASPICAM_ENCODING_JPEG);

    // Let the camera stabilize
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  }

  // Reads and writes the camera image
  unsigned char* Camera::ReadImage() {
    // Allocate image buffer
    image_data=new unsigned char[raspicam_still_.getImageBufferSize()];

    // Retrieve the image in rgb format
    raspicam_still_.grab_retrieve(image_data,raspicam_still_.getImageBufferSize());

    return image_data
  }
  
}
