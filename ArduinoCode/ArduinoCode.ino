#include <SensorTemperatura.h>
#include <Controlador.h>
#include <Leds.h>
#include <Bomba.h>


void setup() {
  Serial.begin(9600);
  Serial.println("Comecou.");
  //Controlador controlador_brassagem(70);
  // put your setup code here, to run once:
  //controlador_brassagem.controla_temperatura();
  //controlador_brassagem.esquenta(80);
  Bomba bomba_mistura;
  bomba_mistura.liga();
  delay(8000);
  bomba_mistura.desliga();
  delay(5000);
  bomba_mistura.liga();
  delay(5000);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
