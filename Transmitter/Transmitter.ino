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
}

void loop() {

   switch6 = digitalRead(6);
   switch7 = digitalRead(7);
   switch8 = digitalRead(8);

   if(switch6 == HIGH){
     controller="0" ;
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx();           //waiting for the whole message to be sent
   }
   if(switch7 == HIGH){
     controller="1" ;
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx();
   }
   if(switch8 == HIGH){
     controller="2" ;
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx(); //
   }
}
