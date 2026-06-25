#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "display.h"
#include <fish.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);



void initDisplay(){
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
        Serial.println("Display Offline");
    }

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10,20);
    display.setTextSize(2);
    display.println("Mini TV");
    display.display();
}

void updateDisplay(int channel){

    switch(channel){
        case -1:
        display.clearDisplay();
        break;

        case 0:
        showFish();
        display.display();
        break;

        case 1:
        display.clearDisplay();
        display.println("Channel: 1");
        break;
    }
 


}