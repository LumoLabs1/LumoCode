// Project 10: Joystick Turret
// Move the stick left and right to aim.
// Click the stick down to fire the "laser" LED.

#include <Servo.h>

const int SERVO_PIN = 9;
const int STICK_X = A0;     // joystick left-right
const int FIRE_PIN = 2;     // joystick click
const int LASER_PIN = 7;    // red LED "laser"

Servo turret;

void setup() {
  turret.attach(SERVO_PIN);
  pinMode(FIRE_PIN, INPUT_PULLUP);
  pinMode(LASER_PIN, OUTPUT);
}

void loop() {
  int x = analogRead(STICK_X);          // 0 to 1023 (about 512 in the middle)
  int angle = map(x, 0, 1023, 0, 180);
  turret.write(angle);

  if (digitalRead(FIRE_PIN) == LOW) {        // stick clicked
    digitalWrite(LASER_PIN, HIGH);
  } else {
    digitalWrite(LASER_PIN, LOW);
  }
  delay(15);
}
