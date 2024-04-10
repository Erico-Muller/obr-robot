#ifndef motor_h
#define motor_h

#include "Arduino.h"

#include "../../module.h"

class Motor : public OutputModule {
protected:
  int motorSpeed = 255;
  int pins[2];

public:
  Motor(int instancePins[2]) {
    pins[0] = instancePins[0];
    pins[1] = instancePins[1];

    pinMode(pins[0], OUTPUT);
    pinMode(pins[1], OUTPUT);
  }

  void speed(int newSpeed); //?
  void forward();
  void backward();
  void stop();
};

#endif
