#include <Arduino.h>

int currentChannel = 1;
bool interactButton = false;


void TV_LOGIC(uint32_t code){


    interactButton = false;

   switch(code){
     case 0xBA45FF00:
     Serial.println("Power button pressed");
     currentChannel=-1;
     break;

     case 0xE916FF00:
     Serial.println("0 pressed");
     currentChannel=0;
     break;
    
     case 0xF30CFF00:
     Serial.println("1 pressed");
     currentChannel=1;
     break;
    
     case 0xE718FF00:
     Serial.println("2 pressed");
     currentChannel=2;
     break;
    
     case 0xA15EFF00:
     Serial.println("3 pressed");
     currentChannel=3;
     break;
    
     case 0xF708FF00:
     Serial.println("4 pressed");
     currentChannel=4;
     break;
    
     case 0xE31CFF00:
     Serial.println("5 pressed");
     currentChannel=5;
     break;
    
     case 0xA55AFF00:
     Serial.println("6 pressed");
     currentChannel=6;
     break;
    
     case 0xBD42FF00:
     Serial.println("7 pressed");
     currentChannel=7;
     break;
    
     case 0xAD52FF00:
     Serial.println("8 pressed");
     currentChannel=8;
     break;
    
     case 0xB54AFF00:
     Serial.println("9 pressed");
     currentChannel=9;
     break;

     case 0xBF40FF00:
     Serial.println("Play/pause pressed");
     interactButton = true;
     break;
    
   }
}

int getCurrentChannel(){
    return currentChannel;
}
bool getInteractButton(){
  return interactButton;
}
