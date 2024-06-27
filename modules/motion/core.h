#pragma once

#include "./motor.h"

// Motion Core
class MC {
public:
  virtual void start(const int insMotorL[2], const int insMotorR[2]) = 0;
  virtual void set_speed(int speed) = 0;
  virtual void forward() = 0;
  virtual void backward() = 0;
  virtual void stop() = 0;
  virtual void left() = 0;
  virtual void right() = 0;
  virtual void rotate_to_left() = 0;
  virtual void rotate_to_right() = 0;
};
