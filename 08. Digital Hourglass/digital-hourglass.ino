// tilt switch for restarting counting when flipped
const int switchPin = 8;

// store last time LED was changed
unsigned int previousTime = 0;

// store current & previous states to check if tilt switch position has changed
int switchState = 0;
int prevSwitchState = 0;

// first position of an LED
int led = 2;

// set interval, in this case 5000 ms = 5 s, every time interval passed, an LED is turned on
long interval = 5000;

void setup() {
  // assign LEDs to pins
  for (int i = 2; i < 8; i++){
    pinMode(i, OUTPUT);
  }

  // set tilt switch as input
  pinMode(switchPin, INPUT);
}

void loop() {
  // current amount of time arduino has been running
  unsigned long currentTime = millis();

  // check if board has been running long enough to turn on an LED
  // if so, set current time to prev time and set an LED to HI
  if (currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;

    // decide what to do when all LEDs are on - could flash or output sound
    // not implemented at this time
    if (led == 7){
    }
  }

  // possibly update the current state if tilt switch has moved
  switchState = digitalRead(switchPin);

  // if in a different state, turn off all LEDs and start counting from beginning
  if (switchState != prevSwitchState){
    for (int i = 2; i < 8; i++){
      digitalWrite(i, LOW);
    }

    led = 2;

    previousTime = currentTime;
  }

  // set previous state to current and come out of loop
  prevSwitchState = switchState;
}
