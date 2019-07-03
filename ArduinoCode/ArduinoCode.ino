#include <Botao.h>
#include <SensorTemperatura.h>
#include <RecirculacaoLavagem.h>
#include <Bomba.h>
#include <Controlador.h>
#include <Fervura.h>
#include <Brassagem.h>
#include <Leds.h>

SensorTemperatura MAX;

bool verifica(bool ERROR,Leds &RGB){
  int temperatura = MAX.leitura();
  if(ERROR==true || temperatura==100 || temperatura==20){
    Serial.print("Temperatura: ");
    Serial.println(temperatura);
    Serial.println("Fatal Error !!!");
    Serial.println("O programa encontrou um erro na operação");
    Serial.println("O processo deve ser reiniciado");
    Serial.println("Aperte o botão ON/OFF para resetar o programa");
    RGB.set_red();
    esperaAcaoUsuario(BOTAO_ON_OFF);
    ERROR=false;
    return true;
  }
  return false;
}
void clear(void){
  delay(1000);
  for(int i = 0; i <= 40; i++)Serial.println(" ");
}


bool processos(void){
  clear();
  Serial.println("NOVO PROCESSO");
  Leds RGB;
  bool ERROR=false;
  iniciaBotoes();
  //inicia Brassagem
  Brassagem Processo1(RGB,&ERROR);
  if(verifica(ERROR,RGB))return false;
  Processo1.inicio();
  if(verifica(ERROR,RGB))return false;
  Processo1.T70G(70);
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo1.add_ing();
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo1.misturar();
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo1.esperar();
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo1.aguarda_iodo();
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo1.T75G(75);
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo1.fim();
  if(verifica(ERROR,RGB))return false;
  //inicia Recirculacao & Lavagem
  RecirculacaoLavagem Processo2(RGB,&ERROR);
  Processo2.inicio();
  if(verifica(ERROR,RGB))return false;
  Processo2.transfere();
  if(verifica(ERROR,RGB))return false;
  clear();
  //inicia Fervura
  Fervura Processo3(RGB,&ERROR);
  if(verifica(ERROR,RGB))return false;
  Processo3.fervendo();
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo3.adicione15g();
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo3.wait55();
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo3.add_resto();
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo3.wait5();
  if(verifica(ERROR,RGB))return false;
  clear();
  Processo3.fim();
  if(verifica(ERROR,RGB))return false;
  Serial.println("Cerveja concluida com Sucesso !!");
  Serial.println("Aperte o botão ON/OFF para resetar o programa");
  RGB.set_green();
  esperaAcaoUsuario(BOTAO_ON_OFF);
}
void setup() {
  Serial.begin(9600);
}

void loop() {
  processos();
}
