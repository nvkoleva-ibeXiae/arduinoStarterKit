// Color Mixing Lamp
// Objective: Use 3 photosensors with restrictive gels covering them
// to control which color comes through and subsequently change LED output
// color; also adjust LED brighness based on how strong light source is

// note: both input & output order differs from book guide

// 4-input LED Outputs
const int redLEDPin = 11;
const int blueLEDPin = 10;
const int greenLEDPin = 9;

// 3 photosensor LED Inputs
const int redSensorPin = A0;
const int blueSensorPin = A1;
const int greenSensorPin = A2;

// 4-input LED Output Variables
int redValue = 0;
int blueValue = 0;
int greenValue = 0;

// 3 photosensor LED Input Variables
int redSensorValue = 0;
int blueSensorValue = 0;
int greenSensorValue = 0;


void setup() {
  Serial.begin(9600);

  // Configure outputs to respective pins
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);

}

void loop() {
  // Set input values to declared variables
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);

  // Print obtained values to screen
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);

  // Adjust LED's brightness (convert sensor's reading betw 0-1023 to value betw 0-255)
  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;

  // Print mapped brightness values
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);

  // Set 4-input LED brightness levels
  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);
  analogWrite(greenLEDPin, greenValue);
}
