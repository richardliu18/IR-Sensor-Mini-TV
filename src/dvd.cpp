#include <Arduino.h>
#include <display.h>
#include <Adafruit_GFX.h>

int dvdX = random(0,93);
int dvdY = random(0,53);

int dvdVX = random(0,2) ? 1 : -1;
int dvdVY = random(0,2) ? 1 : -1;

const int dvdWidth = 36;
const int dvdHeight = 12;

void drawDVD(){
    display.setTextSize(2);
    display.setCursor(dvdX, dvdY);
    display.println("DVD");
}

void updateDVD(){

    dvdX += dvdVX;
    dvdY += dvdVY;

    if(dvdX <=0 || dvdX+dvdWidth >=128){
        dvdVX *= -1;
    }
    if(dvdY<=0 || dvdY+dvdHeight >=64){
        dvdVY *= -1;
    }

    if((dvdX <=0 || dvdX+dvdWidth >=128) && (dvdY<=0 || dvdY+dvdHeight >=64)){

        for(int i = 0; i<4; i++){
        display.invertDisplay(true);
        delay(50);
        display.invertDisplay(false);
        delay(50);
        }
    }

}

void showDVD(){

    updateDVD();
    drawDVD();

}