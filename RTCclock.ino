#include <Wire.h>
#include <RTClib.h>
#include "SevSeg.h"

SevSeg sevseg; 
RTC_DS1307 rtc;

int mode = 1;
int time;

int buttonstate = LOW;
int lastbuttonstate = LOW;


void setup() {
  // put your setup code here, to run once:
pinMode(1, INPUT);
 byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);




  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}


}

void loop() {
  
  DateTime now = rtc.now();


  sevseg.refreshDisplay(); 
  sevseg.setNumber(time);

if(mode = 1){
  if(now.hour()>12){
  time = ((now.hour()-12)*100)+(now.minute());
  }
  if(now.hour() <= 12){
  time = (now.hour()*100)+(now.minute());
  }
  }
if(mode = -1){

    time = ((now.minute())*100)+(now.second());

  }
if (buttonstate == HIGH && lastbuttonstate == LOW) {
    Serial.println("Button bumped!");
    mode = mode*-1;
  }
lastbuttonstate = buttonstate;
delay(5);
}









