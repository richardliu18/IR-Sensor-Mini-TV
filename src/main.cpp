#include <Arduino.h>
#include <IRremote.hpp>

const int RECV_PIN = 23;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR REciever Ready. Press button on remote");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(IrReceiver.decode()){
    IrReceiver.printIRResultShort(&Serial);

    if(IrReceiver.decodedIRData.decodedRawData != 0){
      Serial.print("Hex Code: 0x");
      Serial.println(IrReceiver.decodedIRData.decodedRawData,HEX);
    
    }
    uint32_t code = IrReceiver.decodedIRData.decodedRawData;

    switch(code){
      case 0xBA45FF00:
      Serial.println("Power button pressed");
      break;

      case 0xE916FF00:
      Serial.println("0 pressed");
      break;
      
      case 0xF30CFF00:
      Serial.println("1 pressed");
      break;
      
      case 0xE718FF00:
      Serial.println("2 pressed");
      break;
      
      case 0xA15EFF00:
      Serial.println("3 pressed");
      break;
      
      case 0xF708FF00:
      Serial.println("4 pressed");
      break;
      
      case 0xE31CFF00:
      Serial.println("5 pressed");
      break;
      
      case 0xA55AFF00:
      Serial.println("6 pressed");
      break;
      
      case 0xBD42FF00:
      Serial.println("7 pressed");
      break;
      
      case 0xAD52FF00:
      Serial.println("8 pressed");
      break;
      
      case 0xB54AFF00:
      Serial.println("9 pressed");
      break;
      

    }
    IrReceiver.resume();
  }
}
