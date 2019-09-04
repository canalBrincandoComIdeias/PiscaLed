#include "PiscaLed.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

PiscaLed::PiscaLed(byte pinLED, int tempoPisca) {
  pinMode(pinLED, OUTPUT);
  pino = pinLED;
  tempo = tempoPisca;
  estadoPisca = false;
}

void PiscaLed::play() {
  estadoPisca = true;
  delayPisca = millis();
}

void PiscaLed::stop() {
  estadoPisca = false;
  digitalWrite(pino, LOW); 
}

void PiscaLed::loop() {

  if (estadoPisca) {

     if ((millis() - delayPisca) < tempo )  {
        digitalWrite(pino, LOW);   
     } else if ((millis() - delayPisca) < (tempo * 2) ) {
        digitalWrite(pino, HIGH);
     } else {
        delayPisca = millis();
     }
     
  } else {
    digitalWrite(pino, LOW); 
  }
}

bool PiscaLed::estado(){
	return estadoPisca;
}