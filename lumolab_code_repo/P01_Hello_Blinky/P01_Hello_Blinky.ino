// Project 1: Hello, Blinky!
// Makes the LED on pin 13 blink: 1 second on, 1 second off, forever.

const int LED_PIN = 13;   // our LED is plugged into pin 13

void setup() {
  pinMode(LED_PIN, OUTPUT);     // pin 13 will SEND power out
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // power ON  -> LED lights up
  delay(1000);                  // wait 1000 milliseconds (1 second)
  digitalWrite(LED_PIN, LOW);   // power OFF -> LED goes dark
  delay(1000);                  // wait 1 second again
}
