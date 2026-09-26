// Project 2: Traffic Light Boss
// Green for 3 seconds, yellow for 1 second, red for 3 seconds. Repeat!

const int RED_PIN = 10;
const int YELLOW_PIN = 9;
const int GREEN_PIN = 8;

// Turns each light on (HIGH) or off (LOW) in one go.
void setLights(int red, int yellow, int green) {
  digitalWrite(RED_PIN, red);
  digitalWrite(YELLOW_PIN, yellow);
  digitalWrite(GREEN_PIN, green);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  setLights(LOW, LOW, HIGH);   // GO!
  delay(3000);
  setLights(LOW, HIGH, LOW);   // slow down...
  delay(1000);
  setLights(HIGH, LOW, LOW);   // STOP!
  delay(3000);
}
