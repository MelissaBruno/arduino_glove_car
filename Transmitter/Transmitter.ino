/*
 * Class for transmitting commands based on the values of flex sensors.
 */
#include <VirtualWire.h>
char const* controller;

int flexval = 0;
int turnval = 0;

void setup() {
   vw_set_tx_pin(12);      //Transmitter pin
   vw_setup(4000);         //Initialized the library, bits/sec

   Serial.begin(9600);
}

void loop() {

   flexval = analogRead(A5);
   turnval = analogRead(A4);
   Serial.println(flexval);
   
   /* Different commmands are sent depending on the values of the
    * flex sensors. vw_wait_tx() waits for the entire message to be sent.
    */
   if(flexval<40){
     controller="0";
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx();
   }else if(flexval>70){
     controller="2";
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx();
   }else if(turnval < 45){
      controller="3";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); 
   }else if(turnval > 58){
      controller="4";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); 
   }else{
      controller="1";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); 
   }
   
}
