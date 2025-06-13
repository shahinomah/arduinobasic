const int buzzerPin = 11;  // Passive buzzer connected to D11

// Notes frequency (C4 to B4)
int melody[] = {
  262, 294, 330, 349, 392, 440, 494, 523
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4
};

void setup() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    delay(noteDuration * 1.30);  // Pause between notes
    noTone(buzzerPin);           // Stop the tone
  }
}

void loop() {
  // Melody plays once in setup
}
