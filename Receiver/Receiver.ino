#include <VirtualWire.h>
#include "Control.h"

ControlClass control = ControlClass();

void setup() {

  control.SETUP();
  
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(8);
  vw_setup(4000); // Bits per sec
  pinMode(7, OUTPUT);
  vw_rx_start();
}

void loop() {
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) {
    
     if(buf[0]=='0') {
        control.forward();
     }
     if(buf[0]=='1') {
        control.backward();
     }
     if(buf[0]=='2') {
        control.release();
     }
     if(buf[0]=='3') {
        control.turnLeft();
     }
     if(buf[0]=='4') {
        control.turnRight();
     }
 
  } //if
} //loop
