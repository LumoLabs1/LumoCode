// Project 14: Room Guardian (grand finale!)
// Counts visitors who come closer than 50 cm, beeps hello,
// and shows everything on the screen.

#include <LiquidCrystal.h>

const int LCD_RS = 12;
const int LCD_E = 11;
const int LCD_D4 = 5;
const int LCD_D5 = 4;
const int LCD_D6 = 3;
const int LCD_D7 = 2;
const int TRIG_PIN = 7;
const int ECHO_PIN = 6;
const int BUZZER_PIN = 8;

const int NEAR_CM = 50;          // closer than this = someone is here

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

int visitors = 0;
// Our "memory": is someone standing here right now?
bool someoneThere = false;

long readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long echo = pulseIn(ECHO_PIN, HIGH, 30000);
  if (echo == 0) {
    return 999;                  // no echo: nothing in range
  }
  // 58 microseconds of echo = 1 cm. The +29 rounds to the NEAREST cm.
  return (echo + 29) / 58;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Room Guardian");
  delay(1000);
  lcd.clear();
}

void loop() {
  long cm = readDistanceCm();

  if (cm < NEAR_CM && !someoneThere) {             // someone just arrived!
    someoneThere = true;
    visitors++;
    tone(BUZZER_PIN, 880, 150);                    // "ding!"
  } else if (cm >= NEAR_CM + 10 && someoneThere) { // they walked away
    someoneThere = false;
  }

  lcd.setCursor(0, 0);
  lcd.print("Visitors: ");
  lcd.print(visitors);
  lcd.print("   ");                                // wipe leftover digits
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  if (cm == 999) {
    lcd.print("---");
  } else {
    lcd.print(cm);
  }
  lcd.print(" cm  ");
  delay(200);
}
