// Project 9: Robo Wave
// The servo arm points wherever you turn the knob (0 to 180 degrees).

#include <Servo.h>

const int SERVO_PIN = 9;
const int KNOB_PIN = A0;

Servo arm;   // our robot arm

void setup() {
  arm.attach(SERVO_PIN);
}

void loop() {
  int knob = analogRead(KNOB_PIN);           // 0 to 1023
  int angle = map(knob, 0, 1023, 0, 180);    // 0 to 180 degrees
  arm.write(angle);
  delay(15);                                 // give the arm time to move
}
