// Project 4: Reaction Race
// Wait for the light, then press as fast as you can.
// Open the Serial Monitor (9600 baud) to see your time!

const int BUTTON_PIN = 2;
const int LED_PIN = 8;
// Leave pin A0 EMPTY: its electrical "noise" makes each game different.
const int SEED_PIN = A0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(SEED_PIN));
  Serial.println("Reaction Race! Press the button when the light turns on.");
}

void loop() {
  Serial.println("Get ready...");
  unsigned long waitTime = random(2000, 5000);   // 2 to 5 seconds
  unsigned long start = millis();

  while (millis() - start < waitTime) {
    if (digitalRead(BUTTON_PIN) == LOW) {        // pressed too early? cheeky!
      Serial.println("Too soon! Wait for the light.");
      while (digitalRead(BUTTON_PIN) == LOW) { } // wait until you let go
      delay(1000);
      return;                                    // start a new round
    }
  }

  digitalWrite(LED_PIN, HIGH);                   // GO!
  unsigned long lightOn = millis();
  while (digitalRead(BUTTON_PIN) == HIGH) { }    // wait for the press
  unsigned long reaction = millis() - lightOn;
  digitalWrite(LED_PIN, LOW);

  Serial.print("Your time: ");
  Serial.print(reaction);
  Serial.println(" ms");

  while (digitalRead(BUTTON_PIN) == LOW) { }     // wait until you let go
  delay(2000);
}
