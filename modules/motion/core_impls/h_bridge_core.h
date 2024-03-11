#pragma once

#include "../core.h"
#include "../motor_impls/h_bridge_motor.h"

#define ROTATE_DELAY 500

class H_Bridge_MC : public MC {
private:
  H_Bridge_Motor motorFL, motorFR, motorBL, motorBR;

public:
  void start(const int insMotor1[2], const int insMotor2[2], const int insMotor3[2], const int insMotor4[2]) override {
    motorFL.start(insMotor1);
    motorFR.start(insMotor2);
    motorBL.start(insMotor3);
    motorBR.start(insMotor4);

    Serial.println("Robot initialized");
  }

  void set_speed(int spd1, int spd2 = 0, int spd3 = 0, int spd4 = 0) override {
    if (spd2 == 0 && spd3 == 0 && spd4 == 0) {
      motorFL.set_speed(spd1);
      motorFR.set_speed(spd1);
      motorBL.set_speed(spd1);
      motorBR.set_speed(spd1);
    } else {
      motorFL.set_speed(spd1);
      motorFR.set_speed(spd2);
      motorBL.set_speed(spd3);
      motorBR.set_speed(spd4);
    }
  }

  void forward() override {
    motorFL.forward();
    motorFR.forward();
    motorBL.forward();
    motorBR.forward();
  }

  void backward() override {
    motorFL.backward();
    motorFR.backward();
    motorBL.backward();
    motorBR.backward();
  }

  void stop() override {
    motorFL.stop();
    motorFR.stop();
    motorBL.stop();
    motorBR.stop();
  }

  void left() override {
    motorFL.forward();
    motorFR.backward();
    motorBL.forward();
    motorBR.backward();
  }

  void right() override {
    motorFL.backward();
    motorFR.forward();
    motorBL.backward();
    motorBR.forward();
  }

  void rotate_to_left() override {
    motorFL.forward();
    motorFR.backward();
    motorBL.forward();
    motorBR.backward();
    delay(ROTATE_DELAY);
  }

  void rotate_to_right() override {
    motorFL.backward();
    motorFR.forward();
    motorBL.backward();
    motorBR.forward();
    delay(ROTATE_DELAY);
  }

  void fixed_to_left() override {
    motorFL.forward();
    motorFR.backward();
    motorBL.backward();
    motorBR.forward();
  };

  void fixed_to_right() override {
    motorFL.backward();
    motorFR.forward();
    motorBL.forward();
    motorBR.backward();
  };

  void diagonal_FL() override {
    motorFL.forward();
    motorFR.stop();
    motorBL.stop();
    motorBR.forward();
  };

  void diagonal_FR() override {
    motorFL.stop();
    motorFR.forward();
    motorBL.forward();
    motorBR.stop();
  };

  void diagonal_BL() override {
    motorFL.stop();
    motorFR.backward();
    motorBL.backward();
    motorBR.stop();
  };

  void diagonal_BR() override {
    motorFL.backward();
    motorFR.stop();
    motorBL.stop();
    motorBR.backward();
  };
};
