#pragma once

#include "../motor.h"

class H_Bridge_Motor : public Motor {
public:
  void start(const int ins[2]) override {
    pins[0] = ins[0];
    pins[1] = ins[1];

    pinMode(pins[0], OUTPUT);
    pinMode(pins[1], OUTPUT);
  }

  void forward() override {
    analogWrite(pins[0], speed);
    digitalWrite(pins[1], LOW);
  }

  void backward() override {
    digitalWrite(pins[0], LOW);
    analogWrite(pins[1], speed);
  }

  void stop() override {
    digitalWrite(pins[0], LOW);
    digitalWrite(pins[1], LOW);
  }
};
