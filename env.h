#pragma once

#define DEFAULT_SPEED 50

#define SMALL_DELAY 1000
#define LARGE_DELAY 2500

#define DETECT_DIST 20

#define TRIG_PIN 30
#define ECHO_PIN 31

const int motor1Pins[] = {6, 7};
const int motor2Pins[] = {10, 11};
const int motor3Pins[] = {4, 3};
const int motor4Pins[] = {9, 8};

#define irQty 2
const int irPins[irQty] = {40, 38};

// Out, Led, S0, S1, S2, S3
const int colorSensor1Pins[] = {12, 51, 22, 23, 49, 48};
const int colorSensor2Pins[] = {13, 44, 25, 24, 45, 47};