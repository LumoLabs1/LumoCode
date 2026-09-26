// Project 3: Secret Doorbell Light
// The LED lights up only while the button is pressed.

const int BUTTON_PIN = 2;   // button between pin 2 and GND
const int LED_PIN = 8;      // LED (through its resistor) on pin 8

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // HIGH normally, LOW when pressed
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {   // LOW = pressed
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
