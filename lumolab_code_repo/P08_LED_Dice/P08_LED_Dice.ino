// Project 8: LED Dice
// Press the button to roll. The number of lit LEDs is your roll (1 to 6).

const int LED_PINS[] = {2, 3, 4, 5, 6, 7};   // LED 1 to LED 6
const int BUTTON_PIN = 8;
const int SEED_PIN = A0;                      // leave this pin EMPTY

void showNumber(int n) {
  for (int i = 0; i < 6; i++) {
    if (i < n) {
      digitalWrite(LED_PINS[i], HIGH);
    } else {
      digitalWrite(LED_PINS[i], LOW);
    }
  }
}

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(SEED_PIN));
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    for (int spin = 0; spin < 10; spin++) {     // the dice "tumbles"
      showNumber(random(1, 7));
      delay(60);
    }
    int roll = random(1, 7);                    // 1 to 6 (7 is never picked)
    showNumber(roll);
    Serial.print("You rolled: ");
    Serial.println(roll);
    while (digitalRead(BUTTON_PIN) == LOW) { }  // wait until you let go
    delay(50);
  }
}
