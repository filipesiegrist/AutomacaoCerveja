#include <Botao.h>
#include <SensorTemperatura.h>
#include <RecirculacaoLavagem.h>
#include <Bomba.h>
#include <Controlador.h>
#include <Fervura.h>
#include <Brassagem.h>
#include <Leds.h>


void setup() {
  Serial.begin(9600);
  Leds RGB;
  iniciaBotoes();
  Brassagem Processo1(RGB);
  Processo1.inicio();
  Processo1.T70G();
  delay(1000);
  Processo1.add_ing();
  delay(1000);
  Processo1.misturar();
  delay(1000);
  Processo1.esperar();
  delay(1000);
  Processo1.aguarda_iodo();
  delay(1000);
  Processo1.T75G();
  delay(1000);
  Processo1.fim();
  
  RecirculacaoLavagem Processo2;
  delay(500);
  Processo2.inicio();
  delay(500);
  Processo2.transfere();
  delay(500);
  Fervura Processo3;
  Processo3.fervendo();
  delay(500);
  Processo3.adicione15g();
  delay(500);
  Processo3.wait55();
  delay(500);
  Processo3.add_resto();
  delay(500);
  Processo3.wait5();
  delay(500);
  Processo3.fim();
  

  
  

  
  


  

}

void loop() {

  
}
