#include <Ultrasonic.h>

#define TRIG_PIN 2
#define ECHO_PIN 3

#define DETECT_DIST 5

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = ultrasonic.read();

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  delay(100);
}
