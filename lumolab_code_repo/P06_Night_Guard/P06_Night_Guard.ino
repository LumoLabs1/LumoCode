// Project 6: Night Guard
// Turns the light on automatically when the room gets dark.
// Open the Serial Monitor (9600 baud) to watch the light numbers
// and tune DARK_LEVEL for your room.

const int LIGHT_PIN = A0;
const int LED_PIN = 8;
const int DARK_LEVEL = 700;   // bigger = darker. Tune it for your room!

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LIGHT_PIN);   // 0 to 1023 (darker = bigger)
  Serial.println(light);

  if (light > DARK_LEVEL) {
    digitalWrite(LED_PIN, HIGH);       // it's dark - guard on!
  } else {
    digitalWrite(LED_PIN, LOW);        // it's bright - guard sleeps
  }
  delay(100);
}
