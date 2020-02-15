//libraries
#include <Servo.h>

//objects
Servo myServo;

//var declarations
int const potenPin = A0;
int potenVal;
int angle;

//setup
void setup() {
  myServo.attach(9);

  Serial.begin(9600);
}

//loop
void loop() {
  //read potentiometer value and print for user check
  potenVal = analogRead(potenPin);
  Serial.print("potenVal: ");
  Serial.print(potenVal);

  //map potentiometer values to servo motor values, to sync rotation of pot to rotation of servo
  //and print angle
  angle = map(potenVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  //write angle for servo to rotate to and add delay to allow it enough time
  myServo.write(angle);
  delay(15);
}
