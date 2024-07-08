#include "SevSeg.h"
SevSeg sevseg; 



float mills = 0;
int mins = 59;
int hours = 12;
int secs = 0;


void setup(){
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);




  pinMode(1,INPUT);
  Serial.begin(9600);
}

void loop(){
    sevseg.refreshDisplay(); 
    sevseg.setNumber(mills);
    

mills++;
secs = mills/100;

if (mills>6000)
{
mins++;
mills = 0;

}


if (mins > 59){
hours++;
mins = 0;
}


if (hours > 12){
hours = 1;
}

// Serial.println(" ");
// Serial.print(hours);
// Serial.print(":");
// Serial.print(mins);
// Serial.print(":");
// Serial.print(mills/100);
Serial.println(mills/100);


delay(1);
}