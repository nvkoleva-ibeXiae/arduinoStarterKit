int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT); //red
  pinMode(4, OUTPUT); //red
  pinMode(3, OUTPUT); //green
  pinMode(2, INPUT);  //switch
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW){
    //switch not pressed
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else{
    //switch pressed
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    //waits quarter of a second
    delay(250);

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250);
  }
}
