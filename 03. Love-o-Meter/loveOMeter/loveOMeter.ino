const int sensorPin = A0;
const float baselineTemp = 16.0;

void setup() {
  //open connection (serial port) between Arduino and computer to see analog input values
  Serial.begin(9600);

  //iterate through pins for LEDs, saves lines
  for(int pinNumber = 2; pinNumber <=4; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  //read temp sensor
  int sensorVal = analogRead(sensorPin);

  //print command to connected computer
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  //convert ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

  //print command to connected computer
  Serial.print(" , Volts: ");
  Serial.print(voltage);

  Serial.print(" , degrees C: ");
  //convert voltage to temperature in degrees
  float temperature = (voltage - 0.5) * 100;
  //ln prints on a new line (\n)
  Serial.println(temperature);

  if(temperature < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1);
}
