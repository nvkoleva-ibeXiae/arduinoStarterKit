// Includes & declarations
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Global variables
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  // Start lcd & declare the tilt switch as an input
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);

  // Print welcome message
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

void loop() {
  // Get switch state from board
  switchState = digitalRead(switchPin);

  // Check if switch state has changed & if it has generate a random reply from 1-8
  if (switchState != prevSwitchState){
    if (switchState == LOW){
      reply = random(8);

      // Reset LCD screen & begin new message
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says:");
      lcd.setCursor(0, 1);

      // Switch cases; chosen depending on generated random reply
      switch(reply){
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;
      }
    }
  }

  // Set the current state as the previous state
  prevSwitchState = switchState;
}
