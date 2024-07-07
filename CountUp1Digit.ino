#include "SevSeg.h"
SevSeg sevseg; 
int num = 0;
void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
 
 num++;
 
 if(num > 9)
{
num = 0;

}


        sevseg.setNumber(num);
        sevseg.refreshDisplay();       
        delay(1000); 
}