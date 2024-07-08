#include <Wire.h>
#include <RTClib.h>
#include "SevSeg.h"

SevSeg sevseg; 
RTC_DS1307 rtc;

bool mode = false;
int time;
int buttonstate = LOW;
int lastbuttonstate = LOW;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
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


rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}


}

void loop() {
  
  DateTime now = rtc.now();


  sevseg.refreshDisplay(); 
  sevseg.setNumber(time);

if(mode == true){
  if(now.hour()>12){
  time = ((now.hour()-12)*100)+(now.minute());
  }
  if(now.hour() <= 12){
  time = (now.hour()*100)+(now.minute());
  }
  }
if(mode == false){

    time = ((now.minute())*100)+(now.second());

  }


delay(5);
Serial.println(count);
if(analogRead(A0) == 1023){
  buttonstate = HIGH;
}
else
{
  buttonstate=LOW;
}


 if (buttonstate == LOW && lastbuttonstate == HIGH) {
  if(mode = true){
    mode = false;
    
  }
  if(mode = false){
    mode = true;
    
  }
  count++;
 }
 lastbuttonstate = buttonstate;
}









