#pragma once

#include "../core.h"
#include "../motor_impls/h_bridge_motor.h"

#define ROTATE_DELAY 500

class H_Bridge_MC : public MC {
private:
  H_Bridge_Motor motorL, motorR;

public:
  void start(const int insMotor1[2], const int insMotor2[2]) override {
    motorL.start(insMotor1);
    motorR.start(insMotor2);

    Serial.println("Robot initialized");
  }

  void set_speed(int speed) override {
    motorL.set_speed(speed);
    motorR.set_speed(speed);
  }

  void forward() override {
    motorL.forward();
    motorR.forward();
  }

  void backward() override {
    motorL.backward();
    motorR.backward();
  }

  void stop() override {
    motorL.stop();
    motorR.stop();
  }

  void left() override {
    motorL.stop();
    motorR.forward();
  }

  void right() override {
    motorL.forward();
    motorR.stop();
  }

  void rotate_to_left() override {
    motorL.backward();
    motorR.forward();
    delay(ROTATE_DELAY);
  }

  void rotate_to_right() override {
    motorL.forward();
    motorR.backward();
    delay(ROTATE_DELAY);
  }
};
