// Includes & Instances
import processing.serial.*;
Serial myPort;

// Variables
PImage logo;
int bgcolor = 0;

// Setup
void setup(){
  colorMode(HSB, 255);
  logo = loadImage("https://www.arduino.cc/en/pub/skins/arduinoWide/img/logo.png");
  size(170, 116);
  println("Available serial ports: ");
  println(Serial.list()[2]);
  myPort = new Serial(this, Serial.list()[0], 9600);
}

void draw(){
  if(myPort.available() > 0){
    bgcolor = myPort.read();
    println(bgcolor);
  }
  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}
