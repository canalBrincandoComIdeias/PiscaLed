/*
 *   AUTOR:   BrincandoComIdeias
 *   LINK:    https://www.youtube.com/brincandocomideias ; https://cursodearduino.net/
 *   COMPRE:  https://www.arducore.com.br/
 *   SKETCH:  Exemplo Biblioteca Pisca Led
 *   DATA:    04/09/2019
*/

#include <PiscaLed.h>

//DEFINE O PINO DO LED QUE SERÁ INSTACIADO
#define pinLed LED_BUILTIN

//INSTANCIANDO OBJETO LED
PiscaLed led(pinLed);

char comando;
char comandoAnt;
bool troca = false;

void setup() {
  // INICIA A COMUNICAÇÃO SERIAL
  Serial.begin(9600);
  
  Serial.println("----------------------------------");
  Serial.println("  Exemplo de uso da PiscaLed.h");
  Serial.println(" Digite 'P' maiusculo para Piscar");
  Serial.println("Digite 'p' minusculo para Desligar");
  Serial.println("----------------------------------");

}

void loop() {
  led.loop();

  if(Serial.available()){    
    
    comando = Serial.read();
    
    if ( comandoAnt != comando) {      
      troca = true;
      comandoAnt = comando;
    }    
    
  }

  if (troca == true){
    if (comando == 'P') {
      led.play();
      troca = false ;
      Serial.println("Led Piscando");
    }  
    
    if ( comando == 'p') {
      led.stop();
      troca = false;
      Serial.println("Led Apagado");  
    }
  }
}