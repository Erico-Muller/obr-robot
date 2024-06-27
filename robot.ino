// Magico Altamente Revoltado com Vigaristas Ignorantes Neandertalenses
#include <Ultrasonic.h>

#include "./env.h"
#include "./modules/modules.h"

MC motion;
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);

  motion.init(motorLeftPins, motorRightPins);
  // caso os motores estejam invertidos, invertam a ordem dos parâmetros
}

void loop() {
  motion.speed(80);
  motion.forward();

  int distance = ultrasonic.read();

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= DETECT_DIST) {
    motion.stop();
    delay(SMALL_DELAY);

    motion.to_left();
    motion.forward();
    delay(SMALL_DELAY);

    motion.to_right();
    motion.forward();
    delay(SMALL_DELAY);

    motion.to_right();
    motion.forward();
    delay(SMALL_DELAY);

    motion.to_left();
    motion.forward();
    delay(SMALL_DELAY);
  }
}
