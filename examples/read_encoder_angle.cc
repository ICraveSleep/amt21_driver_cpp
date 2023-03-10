//
// Created by ICraveSleep on 07-Feb-23.
//

#include "amt21_driver.h"

int main() {
  std::string usb_port = "/dev/ttyUSB0";  // The port the USB to RS485 adapter is connected to
  AMT21BaudRate baud_rate = AMT21BaudRate::k115200;
  AMT21Resolution encoder_resolution = AMT21Resolution::k14Bit;
  AMT21TurnType turn_type = AMT21TurnType::kSingleTurn;

  Amt21Driver driver = Amt21Driver("/dev/ttyUSB0", encoder_resolution, baud_rate, turn_type);

  // Open the USB port connection
  bool opened = driver.Open();
  if(!opened){
    std::cout << "No access to usb port. Please give read and write access" << std::endl;
    return 0;
  }

  // Get the encoder value as the position the capacitive disk is in
  uint16_t encoder_value;
  encoder_value = driver.GetEncoderPosition();
  std::cout << "Encoder Position: " << encoder_value << std::endl;

  // Get the encoder value in radians
  float angle_in_rad;
  angle_in_rad = driver.GetEncoderAngle();
  std::cout << "Angle: " << angle_in_rad << std::endl;

  // Get the encoder value in degrees
  float angle_in_deg;
  angle_in_deg = driver.GetEncoderAngleDeg();
  std::cout << "Angle: " << angle_in_deg << std::endl;

  // Close the USB port connection
  driver.Close();

  return 0;
}
