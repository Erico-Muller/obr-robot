// MARVIN
// Magico Altamente Revoltado com Vigaristas Ignorantes Neandertalenses
// pins dos sensores seguidores de linha: 38 e 40
#include <Ultrasonic.h>

#include "./env.h"
#include "./modules/modules.h"

H_Bridge_MC motion;
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

int ir[irQty] = {0, 0};

struct ColorValues {
  short red = 0;
  short green = 0;
  short blue = 0;
  short white = 0;
};

ColorValues color_values[2];

void setup()
{
  Serial.begin(9600);

  pinMode(colorSensor1Pins[0], INPUT);
  pinMode(colorSensor2Pins[0], INPUT);
  for (short i = 1; i < 6; i++)
  {
    pinMode(colorSensor1Pins[i], OUTPUT);
    pinMode(colorSensor2Pins[i], OUTPUT);
  }

  digitalWrite(colorSensor1Pins[1], HIGH);
  digitalWrite(colorSensor1Pins[2], HIGH);
  digitalWrite(colorSensor1Pins[3], LOW);
  digitalWrite(colorSensor2Pins[1], HIGH);
  digitalWrite(colorSensor2Pins[2], HIGH);
  digitalWrite(colorSensor2Pins[3], LOW);

  motion.start(motor1Pins, motor2Pins, motor3Pins, motor4Pins);
  // caso os motores estejam invertidos, invertam a ordem dos parâmetros

  for (short i = 0; i < irQty; i++)
  {
    pinMode(irPins[i], INPUT);
  }
}

void loop()
{
  motion.set_speed(DEFAULT_SPEED);

  //read_color();
  // deal_with_obstacles();
  follow_line();
  /*
  if ((color_values[0].red < color_values[0].blue) &&
    (color_values[0].red < color_values[0].green) &&
    (color_values[0].white < 100))
  {
    Serial.print("1 [Vermelho] ");
  }
  else if ((color_values[0].blue < color_values[0].red) &&
    (color_values[0].blue < color_values[0].green) &&
    (color_values[0].white < 100))
  {
    Serial.print("1 [Azul] ");
  }
  else if ((color_values[0].green < color_values[0].red) &&
    (color_values[0].green < color_values[0].blue) &&
    (color_values[0].white < 100))
  {
    Serial.print("1 [Verde] ");
    motion.rotate_to_right();
  }

  Serial.print("Vermelho: ");
  Serial.print(color_values[0].red);
  Serial.print(" Verde: ");
  Serial.print(color_values[0].green);
  Serial.print(" Azul: ");
  Serial.print(color_values[0].blue);
  Serial.print(" Branco: ");
  Serial.print(color_values[0].white);
  Serial.println();
  Serial.println();

  if ((color_values[1].red < color_values[1].blue) &&
    (color_values[1].red < color_values[1].green) &&
    (color_values[1].white < 100))
  {
    Serial.print("2 [Vermelho] ");
  }
  else if ((color_values[1].blue < color_values[1].red) &&
    (color_values[1].blue < color_values[1].green) &&
    (color_values[1].white < 100))
  {
    Serial.print("2 [Azul] ");
  }
  else if ((color_values[1].green < color_values[1].red) &&
    (color_values[1].green < color_values[1].blue) &&
    (color_values[1].white < 100))
  {
    Serial.print("2 [Verde] ");
    motion.rotate_to_left();
  }

  Serial.print("Vermelho: ");
  Serial.print(color_values[1].red);
  Serial.print(" Verde: ");
  Serial.print(color_values[1].green);
  Serial.print(" Azul: ");
  Serial.print(color_values[1].blue);
  Serial.print(" Branco: ");
  Serial.print(color_values[1].white);
  Serial.println();*/
}

void deal_with_obstacles()
{
  if (ultrasonic.read() <= DETECT_DIST)
  {
    dodge_an_obstacle();
  }
}

void dodge_an_obstacle()
{
  motion.stop();
  delay(SMALL_DELAY);

  motion.rotate_to_left();
  motion.forward();
  delay(SMALL_DELAY);

  motion.rotate_to_right();
  motion.forward();
  delay(SMALL_DELAY);

  motion.rotate_to_right();
  motion.forward();
  delay(SMALL_DELAY);

  motion.rotate_to_left();
  motion.forward();
  delay(SMALL_DELAY);
}

void read_line()
{
  for (short i = 0; i < irQty; i++)
  {
    ir[i] = digitalRead(irPins[i]);
  }
}

void follow_line()
{
  read_line();

  if ((ir[0] && ir[1]) | (!ir[0] && !ir[1]))
  {
    motion.forward();
  }
  else if (!ir[1] | ir[0])
  {
    motion.set_speed(DEFAULT_SPEED - 7, DEFAULT_SPEED + 20, DEFAULT_SPEED - 7, DEFAULT_SPEED + 20);
    motion.left();
  }
  else if (!ir[0] | ir[1])
  {
    motion.set_speed(DEFAULT_SPEED + 20, DEFAULT_SPEED - 7, DEFAULT_SPEED + 20, DEFAULT_SPEED - 7);
    motion.right();
  }
}

void read_color()
{
  // Vermelho
  digitalWrite(colorSensor1Pins[4], LOW);
  digitalWrite(colorSensor1Pins[5], LOW);
  color_values[0].red = pulseIn(colorSensor1Pins[0], digitalRead(colorSensor1Pins[0]) == HIGH ? LOW : HIGH);

  digitalWrite(colorSensor2Pins[4], LOW);
  digitalWrite(colorSensor2Pins[5], LOW);
  color_values[1].red = pulseIn(colorSensor2Pins[0], digitalRead(colorSensor2Pins[0]) == HIGH ? LOW : HIGH);

  // Sem filtro
  digitalWrite(colorSensor1Pins[4], HIGH);
  color_values[0].white = pulseIn(colorSensor1Pins[0], digitalRead(colorSensor1Pins[0]) == HIGH ? LOW : HIGH);

  digitalWrite(colorSensor2Pins[4], HIGH);
  color_values[1].white = pulseIn(colorSensor2Pins[0], digitalRead(colorSensor2Pins[0]) == HIGH ? LOW : HIGH);

  // Azul
  digitalWrite(colorSensor1Pins[4], LOW);
  digitalWrite(colorSensor1Pins[5], HIGH);
  color_values[0].blue = pulseIn(colorSensor1Pins[0], digitalRead(colorSensor1Pins[0]) == HIGH ? LOW : HIGH);

  digitalWrite(colorSensor2Pins[4], LOW);
  digitalWrite(colorSensor2Pins[5], HIGH);
  color_values[1].blue = pulseIn(colorSensor2Pins[0], digitalRead(colorSensor2Pins[0]) == HIGH ? LOW : HIGH);

  // Verde
  digitalWrite(colorSensor1Pins[4], HIGH);
  color_values[0].green = pulseIn(colorSensor1Pins[0], digitalRead(colorSensor1Pins[0]) == HIGH ? LOW : HIGH);

  digitalWrite(colorSensor2Pins[4], HIGH);
  color_values[1].green = pulseIn(colorSensor2Pins[0], digitalRead(colorSensor2Pins[0]) == HIGH ? LOW : HIGH);
}