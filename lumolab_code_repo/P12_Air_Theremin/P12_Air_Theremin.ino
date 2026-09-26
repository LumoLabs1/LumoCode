// Project 12: Air Theremin
// Wave your hand over the sensor: closer = higher note, farther = lower note.

const int TRIG_PIN = 7;
const int ECHO_PIN = 6;
const int BUZZER_PIN = 8;

const int MIN_CM = 5;       // closest hand position we use
const int MAX_CM = 50;      // farthest hand position we use
const int HIGH_HZ = 1000;   // note when your hand is closest
const int LOW_HZ = 200;     // note when your hand is farthest

long readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long echo = pulseIn(ECHO_PIN, HIGH, 30000);
  if (echo == 0) {
    return 999;
  }
  // 58 microseconds of echo = 1 cm. The +29 rounds to the NEAREST cm.
  return (echo + 29) / 58;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long cm = readDistanceCm();
  if (cm >= MIN_CM && cm <= MAX_CM) {
    int pitch = map(cm, MIN_CM, MAX_CM, HIGH_HZ, LOW_HZ);   // closer = higher
    tone(BUZZER_PIN, pitch);
    Serial.print("cm: ");
    Serial.print(cm);
    Serial.print("  note: ");
    Serial.print(pitch);
    Serial.println(" Hz");
  } else {
    noTone(BUZZER_PIN);                  // no hand in range: silence
  }
  delay(30);
}
