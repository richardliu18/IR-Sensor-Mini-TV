#include <Arduino.h>
#include <display.h>
#include <ir_sensor.h>
#include <tv_logic.h>

const int RECV_PIN = 23;

uint32_t code;

void setup() {
 // put your setup code here, to run once:
  Serial.begin(115200);

  initDisplay();

  initIRsensor(RECV_PIN);

}

void loop(){
 // put your main code here, to run repeatedly:
  
  code = updateIRsensor();
  
  TV_LOGIC(code);
  
  updateDisplay(getCurrentChannel());

}


