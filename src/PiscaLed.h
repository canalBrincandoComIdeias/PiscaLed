#ifndef PiscaLed_h
#define PiscaLed_h

#include "Arduino.h"

class PiscaLed {
  public:
    PiscaLed(byte pinLED, int tempoPisca = 1000);
    void play(); 
    void stop();
    void loop();
	bool estado();
  private:
    unsigned long delayPisca;
    bool estadoPisca;
    byte pino;
    int  tempo;
};

#endif