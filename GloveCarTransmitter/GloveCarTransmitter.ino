#include <VirtualWire.h>
char const* controller;         //Array that is to be transmitted

int switch6 = 6;
int switch7 = 7;
int switch8 = 8;

void setup() {
   vw_set_tx_pin(12);
   vw_setup(4000);

   pinMode(6, INPUT);
   pinMode(7, INPUT);
   pinMode(8, INPUT);
   Serial.begin(9600);
}

void loop() {

   switch6 = digitalRead(6);
   switch7 = digitalRead(7);
   switch8 = digitalRead(8);

   int flexval = analogRead(A5);
   int turnval = analogRead(A4);
   Serial.println(flexval);
    
   if(flexval<40){
     controller="0" ;
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx();           //waiting for the whole message to be sent
   }else if(flexval>70){
     controller="2" ;
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx();
   }else if(turnval < 45){
      controller="3" ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); 
   }else if(turnval > 58){
      controller="4" ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); 
   }else{
      controller="1" ; //Stand By
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); 
   }
   
}
