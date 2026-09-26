// Project 13: Secret Message Board
// Press the button to show the next secret message on the screen.

#include <LiquidCrystal.h>

const int LCD_RS = 12;
const int LCD_E = 11;
const int LCD_D4 = 5;
const int LCD_D5 = 4;
const int LCD_D6 = 3;
const int LCD_D7 = 2;
const int BUTTON_PIN = 8;

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// Change these to your own secret messages (16 letters max!)
const char* MESSAGES[] = {
  "Lumo's Lab!",
  "You built this!",
  "Keep inventing!",
  "Hello, maker :)"
};
const int MESSAGE_COUNT = 4;
int current = 0;

void showMessage(int i) {
  lcd.clear();
  lcd.setCursor(0, 0);          // column 0, top row
  lcd.print(MESSAGES[i]);
  lcd.setCursor(0, 1);          // column 0, bottom row
  lcd.print("Message ");
  lcd.print(i + 1);
  lcd.print(" of ");
  lcd.print(MESSAGE_COUNT);
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lcd.begin(16, 2);             // 16 columns, 2 rows
  showMessage(current);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    // After the last message, go back to the first one.
    current = (current + 1) % MESSAGE_COUNT;
    showMessage(current);
    while (digitalRead(BUTTON_PIN) == LOW) { } // wait until you let go
    delay(50);
  }
}
