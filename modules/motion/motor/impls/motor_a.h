#ifndef motor_a_h
#define motor_a_h

#include "Arduino.h"

#include "../motor.h"

class MotorA : public Motor {
public:
  MotorA(int instancePins[2]) : Motor(instancePins) {}
};

void Motor::speed(int newSpeed) { motorSpeed = newSpeed; }

void Motor::forward() {
  analogWrite(pins[0], motorSpeed);
  digitalWrite(pins[1], LOW);
}

void Motor::backward() {
  digitalWrite(pins[0], LOW);
  analogWrite(pins[1], motorSpeed);
}

void Motor::stop() {
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], LOW);
}

#endif
