// MARVIN
// Magico Altamente Revoltado com Vigaristas Ignorantes Neandertalenses
#include <Ultrasonic.h>

#include "./env.h"
#include "./modules/modules.h"

H_Bridge_MC motion1;
H_Bridge_MC motion2;
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

const int pins[5] = {42, 40, 38, 36, 34};
int d[5] = {0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);

  motion1.start(motor1Pins, motor2Pins);
  motion2.start(motor3Pins, motor4Pins);
  // caso os motores estejam invertidos, invertam a ordem dos parâmetros

  for (short i = 0; i < 5; i++) {
    pinMode(pins[i], INPUT);
  }
}

void loop() {
  for (short i = 0; i < 5; i++) {
    d[i] = digitalRead(pins[i]);
  }

  motion1.set_speed(41);
  motion2.set_speed(41, true);
  // motion1.forward();
  // motion2.forward();

  if (!d[2]) {
    motion1.forward();
    motion2.forward();
  } else if (!d[1]) {
    motion1.right();
    motion2.right();
  } else if (!d[3]) {
    motion1.left();
    motion2.left();
  } else {
    motion1.stop();
    motion2.stop();
  }

  /*int distance = ultrasonic.read();

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= DETECT_DIST) {
    motion1.stop();
    motion2.stop();
    delay(SMALL_DELAY);

    motion1.rotate_to_left();
    motion2.rotate_to_left();
    motion1.forward();
    motion2.forward();
    delay(SMALL_DELAY);

    motion1.rotate_to_right();
    motion2.rotate_to_right();
    motion1.forward();
    motion2.forward();
    delay(SMALL_DELAY);

    motion1.rotate_to_right();
    motion2.rotate_to_right();
    motion1.forward();
    motion2.forward();
    delay(SMALL_DELAY);

    motion1.rotate_to_left();
    motion2.rotate_to_left();
    motion1.forward();
    motion2.forward();
    delay(SMALL_DELAY);
  }*/
}
