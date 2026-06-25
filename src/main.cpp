#include <Arduino.h>
#include <IRremote.hpp>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


const int RECV_PIN = 23;


int currentChannel = 1;


void setup() {
 // put your setup code here, to run once:
 Serial.begin(115200);
 IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
 Serial.println("IR REciever Ready. Press button on remote");
 

if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  Serial.println("OLED failed to start");
}

display.clearDisplay();
display.setTextColor(SSD1306_WHITE);


display.setTextSize(2);
display.setCursor(10, 20);
display.println("Mini TV");
display.display();

delay(1000);

}


void UpdateDisplay(int channel){


 display.clearDisplay();
 display.setCursor(0, 10);
 display.setTextSize(2);
 display.println("Channel:");


 display.setTextSize(3);
 display.setCursor(0, 35);
 display.println(channel);


 display.display();


}


void TV_LOGIC(uint32_t code){


   switch(code){
     case 0xBA45FF00:
     Serial.println("Power button pressed");
     currentChannel=1;
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
    
   }
}


void loop(){
 // put your main code here, to run repeatedly:
 if(IrReceiver.decode()){
   IrReceiver.printIRResultShort(&Serial);


   if(IrReceiver.decodedIRData.decodedRawData != 0){
     Serial.print("Hex Code: 0x");
     Serial.println(IrReceiver.decodedIRData.decodedRawData,HEX);
  
   }
   uint32_t code = IrReceiver.decodedIRData.decodedRawData;


   if(code!=0){
     TV_LOGIC(code);
   }


   IrReceiver.resume();


   UpdateDisplay(currentChannel);
 }
}

