void setup() {
  // Start serial communication - replicate in Processing
  Serial.begin(9600);
}

void loop() {
  // Send information over serial connection
  Serial.write(analogRead(A0)/4);

  // Allow time for ADC
  delay(1);
}
