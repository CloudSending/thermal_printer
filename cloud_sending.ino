/*
image.h is created by processing app in Adafruit's Thermal library.
 Image size shoud be:
 UNO - W384px x H400?
 MEGA - W384px 
 
 */
#include "SoftwareSerial.h"
#include "Adafruit_Thermal.h"
#include "mission_paper1.h"
#include "mission_paper2.h"
#include <avr/pgmspace.h>

int rxPin = 5;  // This is the green wire
int txPin = 6;  // This is the yellow wire

Adafruit_Thermal printer(rxPin, txPin);

void setup(){
  Serial.begin(19200);
}

void loop() {
  if(Serial.available()){
    int incoming = Serial.read();
    Serial.println(incoming);
    if(incoming == 0 || incoming == 48){
      printer.begin();
      printer.println("Cloud Sending");
      printer.printBitmap(mission_paper2_width, mission_paper1_height, mission_paper1_data);
      printer.printBitmap(mission_paper2_width, mission_paper2_height, mission_paper2_data);    
      printer.println("Thank you for your support!");
      printer.feed(1);
Serial.println("done");
      printer.sleep();      // Tell printer to sleep
      printer.wake();       // MUST call wake() before printing again, even if reset
      printer.setDefault(); // Restore printer to defaults
        
    }
  }
}

