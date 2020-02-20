// set up four notes to correspond to 4 buttons
// numbers are C, D, E, F frequecies
int notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read button input and print to terminal
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  // decide which note to play based on button input
  // use tone function to get note to play and send to piezo
  if (keyVal == 1023){
    tone(8, notes[0]);
  } else if (keyVal >= 990 && keyVal <= 1010){
      tone(8, notes[1]);
  } else if (keyVal >= 505 && keyVal <= 516){
      tone(8, notes[2]);
  } else if (keyVal >= 5 && keyVal <= 10){
      tone(8, notes[3]);
  } else noTone(8);
}
