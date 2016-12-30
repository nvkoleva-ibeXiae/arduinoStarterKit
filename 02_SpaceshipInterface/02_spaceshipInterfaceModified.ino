//This program takes the Spaceship Interface and blinks the green LED indefinitely while switch is not pressed
//When the switch is pressed the two LEDs blink in turn before blinking together 5 times, then taking a turn again

int switchState = 0;

void setup() {
  //3 LEDs, 1 pushbutton
  pinMode(5, OUTPUT); //red
  pinMode(4, OUTPUT); //red
  pinMode(3, OUTPUT); //green
  pinMode(2, INPUT);  //switch
}

void loop() {
  //PB state is read as HI or LOW
  switchState = digitalRead(2);

  //not pressed - green LED blinks indefinitely
  if (switchState == LOW){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    while(1){
      digitalWrite(3, HIGH);
      delay(250);
      
      digitalWrite(3, LOW);
      delay(250);
      break;
    }
  }
  //pressed - red LEDs sequence and blinking, green off
  else{
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);

    delay(250);

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);

    delay(250);

    //two red LEDs blink together 5 times
    for(int i = 0; i <=4; ++i){
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      delay(250);
      
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      delay(250);
    }

    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250);

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250);
  }

}
