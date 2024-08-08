// MARVIN
// Magico Altamente Revoltado com Vigaristas Ignorantes Neandertalenses
#include <Ultrasonic.h>

#include "./env.h"
#include "./modules/modules.h"

H_Bridge_MC motion1;
H_Bridge_MC motion2;
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

int ir[irQty] = {0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);

  motion1.start(motor1Pins, motor2Pins);
  motion2.start(motor3Pins, motor4Pins);
  // caso os motores estejam invertidos, invertam a ordem dos parâmetros

  for (short i = 0; i < irQty; i++) {
    pinMode(irPins[i], INPUT);
  }
}

void loop() {
  for (short i = 0; i < irQty; i++) {
    d[i] = digitalRead(irPins[i]);
  }

  int distance = ultrasonic.read();

  motion1.set_speed(DEFAULT_SPEED);
  motion2.set_speed(DEFAULT_SPEED, true);

  if (distance <= DETECT_DIST) {
    dodge_an_obstacle();
  }

  if (!ir[2]) {
    motion1.forward();
    motion2.forward();
  } else if (!ir[1]) {
    motion1.right();
    motion2.right();
  } else if (!ir[3]) {
    motion1.left();
    motion2.left();
  }
}

void dodge_an_obstacle() {
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
}
