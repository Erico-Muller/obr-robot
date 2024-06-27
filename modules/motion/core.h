#ifndef core_h
#define core_h

#include "./motor.h"

// Motion Core
class MC {
  Motor motorL, motorD;

public:
  void init(const int insMotor1[2], const int insMotor2[2]) {
    motorL.pinout(insMotor1);
    motorD.pinout(insMotor2);

    Serial.println("Robot initialized");
  }

  void speed(int speed) {
    motorL.speed(speed);
    motorD.speed(speed);
  }

  void forward() {
    motorL.forward();
    motorD.forward();
  }

  void backward() {
    motorL.backward();
    motorD.backward();
  }

  void stop() {
    motorL.stop();
    motorD.stop();
  }

  void left() {
    motorL.stop();
    motorD.forward();
  }

  void right() {
    motorL.forward();
    motorD.stop();
  }

  void to_left() {
    motorL.backward();
    motorD.forward();
    delay(500);
  }

  void to_right() {
    motorL.forward();
    motorD.backward();
    delay(500);
  }
};

#endif