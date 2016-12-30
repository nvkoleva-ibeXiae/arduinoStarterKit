int red = 13;
int yellow = 12;
int green = 11;
int button = 2; // switch is on pin 2
int buttonValue = 0; // switch defaults to 0 or LOW

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button,INPUT);
  digitalWrite(green,HIGH);
}

void loop(){
// read the value of the switch
  buttonValue = digitalRead(button);
// if the switch is HIGH, ie. pushed down - change the lights!
  if (buttonValue == HIGH){
    changeLights();
    delay(15000); // wait for 15 seconds
  }
}

void changeLights(){
// green off, yellow for 3 seconds
  digitalWrite(green, LOW);
  digitalWrite(yellow,HIGH);
  delay(3000);

  // turn off yellow, then turn red on for 5 seconds
  digitalWrite(yellow,LOW);
  digitalWrite(red,HIGH);
  delay(5000);

  // red and yellow on for 2 seconds (red is already on though)
  digitalWrite(yellow,HIGH);
  delay(2000);

  // turn off red and yellow, then turn on green
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
}
