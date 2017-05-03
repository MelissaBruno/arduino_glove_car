#include <VirtualWire.h>
char *controller;         //Char being transmitted

int switch6 = 6;
int switch7 = 7;
int switch8 = 8;

void setup() {
   vw_set_ptt_inverted(true);
   vw_set_tx_pin(12);
   vw_setup(4000);// speed of data transfer Kbps

   pinMode(6, INPUT);
   pinMode(7, INPUT);
   pinMode(8, INPUT);
}

void loop() {

   switch6 = digitalRead(6);
   switch7 = digitalRead(7);
   switch8 = digitalRead(7);

   if(switch6 == HIGH){
     controller="0" ;
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx();
   }
   if(switch7 == HIGH){
     controller="1" ;
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx(); // Wait until the whole message is gone
   }
   if(switch8 == HIGH){
     controller="2" ;
     vw_send((uint8_t *)controller, strlen(controller));
     vw_wait_tx(); // Wait until the whole message is gone
   }
}
