// Author: Radu Gostian
// Initial Date : 13.03.2023
// not tested

/**
  Alfa steering wheel controls use 3 pins that are connected to the Head Unit
  They connect to the head unit through the grey connector
  Pin 10,11,12
  Pin 12 is GND
  pin 10 represent a ther right/left of the steering wheel
  pin 11 represent a ther right/left of the steering wheel
  When a button is pressed the buttons act like voltage deviders.
            Function  Location  Voltage
  Button 1  Vol+
  Button 2  Vol-
  Button 3  Mute
  Button 4  >>
  Button 5  Next
  Button 6  Back
  Button 7  SRC
  Button 8  ???
*/

#define PINL A1
#define PINR A2
#define OUTPUT A3
#define STEPS 1023
#define __debug__

void setup() {
  #ifdef __debug__
    Serial.begin(38400);
  #endif
}

int out;
int readL;
int readR;

void loop() {
  readL = analogRead(PINL);
  readR = analogRead(PINR);
  if(readL){
    out = readL/3;
  } else{
    out = readR/3 + STEPS/2;
  }
  analogWrite(OUTPUT, out);
  
  #ifdef __debug__
    Serial.print("Output: ");
    Serial.println(out);
  #endif
  
  delay(50);
}
