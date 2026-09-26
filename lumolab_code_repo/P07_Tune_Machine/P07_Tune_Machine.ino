// Project 7: Tune Machine
// Four buttons, four notes. Hold a button to play its note.

const int BUTTON_C = 2;
const int BUTTON_D = 3;
const int BUTTON_E = 4;
const int BUTTON_G = 5;
const int BUZZER_PIN = 8;

// Notes are measured in hertz (vibrations per second).
const int NOTE_C4 = 262;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_G4 = 392;

int currentNote = 0;       // 0 means "silent"

void setup() {
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
  pinMode(BUTTON_E, INPUT_PULLUP);
  pinMode(BUTTON_G, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int newNote = 0;
  if (digitalRead(BUTTON_C) == LOW) {
    newNote = NOTE_C4;
  } else if (digitalRead(BUTTON_D) == LOW) {
    newNote = NOTE_D4;
  } else if (digitalRead(BUTTON_E) == LOW) {
    newNote = NOTE_E4;
  } else if (digitalRead(BUTTON_G) == LOW) {
    newNote = NOTE_G4;
  }

  // Only change the sound when a different key is pressed.
  if (newNote != currentNote) {
    if (newNote == 0) {
      noTone(BUZZER_PIN);
    } else {
      tone(BUZZER_PIN, newNote);
    }
    currentNote = newNote;
  }
}
