#ifndef RADIANCE_SRC_MICROCONTROLLER_H_
#define RADIANCE_SRC_MICROCONTROLLER_H_

#include "datahandler.h"
#include "controls/heatercontrol.h"

namespace RADIANCE {
  // Controls the RADIANCE software. Encapsulates the command
  // functions of the Rasperry Pi 3.
  class Microcontroller {
  public:

    // Setup and configure sensors
    Microcontroller();

    // Step one frame
    void UpdateFrameCounter();

    // Start the system (infinite) loop
    void StartLoop();

    // Process the measured data and then write the heater output
    void SetThermalControl(DataHandler::frame_data_type frame_data);

  private:
    // Keeps track of frame number.
    // Used for determining if a picture needs to be taken
    // Resets every 60th frame
    int frame_counter = 0;

    // Minimum and maximum heater temperatures
    const float kMinHeaterTemp = 1;
    const float kMaxHeaterTemp = 3;

    // Used to handle input/output of data from reading the sensors to storage
    DataHandler data_handler_;

    // Initialize the heater controls. The argument is the PWM pin number
    HeaterControl battery_heater_ = HeaterControl(1);
    HeaterControl spectrometer_heater_ = HeaterControl(1);
  };

} // namespace RADIANCE
#endif //RADIANCE_SRC_MICROCONTROLLER_H_
