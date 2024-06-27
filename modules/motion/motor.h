#pragma once

class Motor {
protected:
  int speed = 255; // min: 0; max: 255
  int pins[2];

public:
  void set_speed(int value) { speed = value; }

  virtual void start(const int ins[2]) = 0;
  virtual void forward() = 0;
  virtual void backward() = 0;
  virtual void stop() = 0;
};
