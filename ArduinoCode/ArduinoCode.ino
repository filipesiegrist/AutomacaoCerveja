#include <SensorTemperatura.h>
#include <Controlador.h>
#include <Leds.h>
#include <Bomba.h>
#include <Botao.h>


void setup() {
  Serial.begin(9600);
  Serial.println("Comecou.");
  //Controlador controlador_brassagem(70);
  // put your setup code here, to run once:
  //controlador_brassagem.controla_temperatura();
  //controlador_brassagem.esquenta(80);
  iniciaBotoes();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Bomba bomba_mistura;
  esperaAcaoUsuario(BOTAO_ACAO);
  bomba_mistura.liga();
  esperaAcaoUsuario(BOTAO_ON_OFF);
  bomba_mistura.desliga();
  
}
