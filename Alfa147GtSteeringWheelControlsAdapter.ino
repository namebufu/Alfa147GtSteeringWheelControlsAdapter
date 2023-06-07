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

#include <Adafruit_MCP4725.h> // MCP4725 library from adafruit

#define PINL A3
#define PINR A2
#define OUTPUT 10
#define STEPS 512
#define __debug__

Adafruit_MCP4725 MCP4725;

void setup() {
 // MCP4725.begin(0x62);
//we use hardware pulldowns
#ifdef __debug__
  Serial.begin(9600);
  Serial.println("Start Debugging");
  Serial.println("Init MCP4725");
  
   Serial.println("Started MCP4725");
#endif
  MCP4725.begin(0x60);
  MCP4725.setVoltage(0, true);
}


int out;
int readL;
int readR;

void loop() {
  readL = analogRead(PINL);
  readR = analogRead(PINR);
#ifdef __debug__
  Serial.print("OutputL: ");
  Serial.println(readL);
  Serial.print("OutputR: ");
  Serial.println(readR);
#endif
  if (readL) {
    out = readL / 2;
  } else if (readR) {
    out = readR / 2 + STEPS;
  } else {
    out = 0;
  }
  
  MCP4725.setVoltage(out*4, false);


  delay(250);
}
