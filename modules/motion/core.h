#pragma once

#include "./motor.h"

// Motion Core
class MC {
public:
  virtual void start(const int insMotor1[2], const int insMotor2[2], const int insMotor3[2], const int insMotor4[2]) = 0;
  virtual void set_speed(int spd1, int spd2, int spd3, int spd4) = 0;
  virtual void forward() = 0;
  virtual void backward() = 0;
  virtual void stop() = 0;
  virtual void left() = 0;
  virtual void right() = 0;
  virtual void rotate_to_left() = 0;
  virtual void rotate_to_right() = 0;
  virtual void fixed_to_left() = 0;
  virtual void fixed_to_right() = 0;
  virtual void diagonal_FL() = 0;
  virtual void diagonal_FR() = 0;
  virtual void diagonal_BL() = 0;
  virtual void diagonal_BR() = 0;
};
