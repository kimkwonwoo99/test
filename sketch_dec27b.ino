#include <Bounce2.h>
#include<MsTimer2.h>
int buttonL = 2;
int buttonR = 3;
int ledL = 9;
int ledR = 10;

Bounce debouncerL = Bounce();
Bounce debouncerR = Bounce();

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonL, INPUT_PULLUP);
  pinMode(buttonR, INPUT_PULLUP);
  pinMode(ledL, OUTPUT);
  pinMode(ledR, OUTPUT);
  debouncerL.attach(buttonL);
  debouncerR.attach(buttonR);
  debouncerL.interval(5); 
  debouncerR.interval(5);
  Serial.begin(9600);
  MsTimer2::set(10,aa);
  MsTimer2::start();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  debouncerL.update(); 
  debouncerR.update();
  if(debouncerL.fell()){
    digitalWrite(ledL, HIGH);
  }
  if(debouncerL.rose()){
    digitalWrite(ledL, LOW);
  }
  if(debouncerR.fell()){
    digitalWrite(ledR, HIGH);
  }
  if(debouncerR.rose()){
    digitalWrite(ledR, LOW);
  }
}

void aa(){
  if(digitalRead(buttonL)==0){
    Serial.println("L Pressed");
  }
  else if(digitalRead(buttonR)==0){
    Serial.println("R Pressed");
  }  
}
 
