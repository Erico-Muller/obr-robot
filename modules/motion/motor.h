#ifndef motor_h
#define motor_h

class Motor {
  int spd = 255; // min: 0; max: 255
  int pins[2];

public:
  void pinout(const int ins[2]) {
    pins[0] = ins[0];
    pins[1] = ins[1];

    pinMode(pins[0], OUTPUT);
    pinMode(pins[1], OUTPUT);
  }

  void speed(int in1) {
    spd = in1;
  }

  void forward() {
    analogWrite(pins[0], spd);
    digitalWrite(pins[1], LOW);
  }

  void backward() {
    digitalWrite(pins[0], LOW);
    analogWrite(pins[1], spd);
  }

  void stop() {
    digitalWrite(pins[0], LOW);
    digitalWrite(pins[1], LOW);
  }
};

#endif