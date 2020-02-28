// Includes & declarations
#include <Servo.h>
Servo myServo;

// Variable to pin declarations
const int piezo = A0;
const int switchPin = 2;
const int yellowLED = 3;
const int greenLED = 4;
const int redLED = 5;

int knockVal;
int switchVal;

// Quiet and load value definitions
const int quietKnock = 10;
const int loudKnock = 100;

// Lock check values
boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  // Attach servo to pin 9
  myServo.attach(9);
  // Assign outputs and inputs
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);

  // Light green led until locked
  digitalWrite(greenLED, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  if(locked == false){
    // Get state of switch (whether pressed or not)
    switchVal = digitalRead(switchPin);

    // Switch button is pressed - lock
    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }

  if(locked == true){
    // Listen to piezo for knocks
    knockVal = analogRead(piezo);

    // Wait for 3 knocks
    if(numberOfKnocks < 3 && knockVal > 0){
      if(checkForKnock(knockVal) == true){
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    if(numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLED,HIGH);
      digitalWrite(redLED,LOW);
      Serial.println("The box is unlocked!");
    }
  }
}

// Check if a knock is valid based on its volume
boolean checkForKnock(int value){
  if(value > quietKnock && value < loudKnock){
    digitalWrite(yellowLED,HIGH);
    delay(50);
    digitalWrite(yellowLED,LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  } else{
      Serial.print("Bad knock value ");
      Serial.println(value);
      return false;
  }
}
