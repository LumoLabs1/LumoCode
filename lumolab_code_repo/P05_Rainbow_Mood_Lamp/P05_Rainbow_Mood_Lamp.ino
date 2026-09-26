// Project 5: Rainbow Mood Lamp
// Turn the knob to travel around the colour wheel:
// red -> green -> blue -> back to red.

const int RED_PIN = 6;
const int GREEN_PIN = 5;
const int BLUE_PIN = 3;
const int KNOB_PIN = A0;
// Set to true if your RGB LED's longest leg must go to 5V (see the tips).
const bool COMMON_ANODE = false;

void setColor(int red, int green, int blue) {
  if (COMMON_ANODE) {              // common-anode LEDs work "upside down"
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  }
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  int knob = analogRead(KNOB_PIN);          // 0 to 1023
  int hue = map(knob, 0, 1023, 0, 767);     // 3 stretches of 256 steps

  if (hue < 256) {
    setColor(255 - hue, hue, 0);            // red fades to green
  } else if (hue < 512) {
    setColor(0, 511 - hue, hue - 256);      // green fades to blue
  } else {
    setColor(hue - 512, 0, 767 - hue);      // blue fades back to red
  }
  delay(20);
}
