#ifndef RADIANCE_SRC_DATAHANDLER_H_
#define RADIANCE_SRC_DATAHANDLER_H_

#include "sensors/spectrometer.h"
#include "sensors/internaltemperaturesensor.h"
#include "sensors/externaltemperaturesensor.h"
#include "sensors/humiditysensor.h"
#include "sensors/attitudesensor.h"
#include "sensors/camera.h"

namespace RADIANCE {
  // DataHandler encapsulates the data transfer process
  // The read functions set the data in the science data struct
  class DataHandler{
  public:

    // Setup and configure sensors
    void Initialize();
    
    // Reads a measurement from each sensor and places it into the
    // science data struct.
    // Inputs: 
    // frame_counter: Used to determine whether a picture is needed
    void ReadSensorData(int frame_counter);

    // Writes the science data struct to storage
    // Inputs: 
    // frame_counter: Used to determine a picture needs to be written
    void WriteMeasurementsToStorage(int frame_counter);

  private:
    // Reads spectrum data into frame data
    void ReadSpectrum();

    // Reads engineering data into frame data
    void ReadInternalTemperature();
    void ReadExternalTemperature();
    void ReadHumidity();
    void ReadAttitude();

    // Reads camera data into frame data
    void ReadCamera();

    // Structure type to hold all the sensor data for each frame
    struct frame_data_type {
      float* spectrum;
      float humidity;
      float upper_battery_temperature;
      float lower_battery_temperature;
      float storage_temperature;
      float external_temperature;
      float attitude;
      unsigned char* image;
    };

    // Holds the science data for each frame
    frame_data_type frame_data;

    // Sensor data members
    Spectrometer spectrometer_;
    HumiditySensor humidity_sensor_;
    InternalTemperatureSensor upper_battery_temperature_sensor_;
    InternalTemperatureSensor lower_battery_temperature_sensor_;
    InternalTemperatureSensor storage_temperature_sensor_;
    ExternalTemperatureSensor external_temperature_sensor_;
    AttitudeSensor attitude_sensor_;
    Camera camera_;

  };

} // namespace RADIANCE
#endif //RADIANCE_SRC_DATAHANDLER_H_
