// Project 11: Parking Buddy
// Green = plenty of room, yellow + beeps = getting close, red + alarm = STOP!
// Open the Serial Monitor (9600 baud) to see the distance.

const int TRIG_PIN = 7;
const int ECHO_PIN = 6;
const int GREEN_PIN = 4;
const int YELLOW_PIN = 3;
const int RED_PIN = 2;
const int BUZZER_PIN = 8;

const int NEAR_CM = 30;    // closer than this: slow down
const int CLOSE_CM = 10;   // closer than this: STOP!

long readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);          // send a 10-microsecond "click"
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long echo = pulseIn(ECHO_PIN, HIGH, 30000);   // wait up to 30 ms for the echo
  if (echo == 0) {
    return 999;                          // no echo: nothing nearby
  }
  // 58 microseconds of echo = 1 cm. The +29 rounds to the NEAREST cm.
  return (echo + 29) / 58;
}

void setLights(int green, int yellow, int red) {
  digitalWrite(GREEN_PIN, green);
  digitalWrite(YELLOW_PIN, yellow);
  digitalWrite(RED_PIN, red);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long cm = readDistanceCm();
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println(" cm");

  if (cm < CLOSE_CM) {
    setLights(LOW, LOW, HIGH);           // STOP!
    tone(BUZZER_PIN, 1000);              // continuous alarm
    delay(100);
  } else if (cm < NEAR_CM) {
    setLights(LOW, HIGH, LOW);           // careful...
    tone(BUZZER_PIN, 1000, 50);          // short beep
    delay(300);
  } else {
    setLights(HIGH, LOW, LOW);           // all clear
    noTone(BUZZER_PIN);
    delay(100);
  }
}
