/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 11:56:07
*/

#ifndef _BRASSAGEM_CPP_
#define _BRASSAGEM_CPP_

#include "Brassagem.h"
#define TEMPO_IODO 3000 // 15 minutos


// Flag que indica se ocorreu algum erro no sistema.
// bool erro_de_funcionamento;
// A implementacao da maquina estados sera nesta funcao:
Brassagem::Brassagem(Leds &led,bool *gg){
  led=led;

  this->ERROR=gg;
}
// Estados do sistema
void Brassagem::inicio(void){
  Serial.println("Aguardando inicialização");
  Serial.println("Aperte o botão ON/OFF para prosseguir");
  led.set_yellow();
  esperaAcaoUsuario(BOTAO_ON_OFF);
  led.reset();
  return;
}
int Brassagem::T70G(int temperatura){
  Serial.println("Aguardando temperatura >= 70");
  led.set_green();
  bomba.liga();
  int temp=controlador.esquenta(temperatura);
  bomba.desliga();
  led.reset();
  return temp;
}
void Brassagem::add_ing(void){
  Serial.println("Adicione ingredientes !!");
  Serial.println("Aperte o botão AÇÃO para prosseguir");
  led.set_yellow();
  esperaAcaoUsuario(BOTAO_ACAO);
  led.reset();
  return;
}
void Brassagem::misturar(void){
  Serial.println("Misture os ingredientes !!");
  Serial.println("Aperte o botão AÇÃO para prosseguir");
  led.set_yellow();
  esperaAcaoUsuario(BOTAO_ACAO);
  led.reset();
  return;
}
void Brassagem::esperar(void){
  Serial.println("Aguarde 60 mins");
  led.set_green();
  controlador.controla_temperatura(66);
  led.reset();
  return;
}
bool Brassagem::aguarda_iodo(void){
  int tentativas=0;
  bool sair=false;
  led.set_green();
  Serial.println("Teste do Iodo! aguarda 15 mins");
  do{
    tentativas++;
    led.set_green();
    delay(TEMPO_IODO);
    led.set_yellow();
    Serial.println("Teste do iodo OK?");
    Serial.println("Aperte botão ON/OFF para Sim");
    Serial.println("Aperte botão AÇÃO para Não");
    if(esperaApertoDeUmBotao(BOTAO_ON_OFF,BOTAO_ACAO)){
        sair=true;
    }else{
      if(tentativas>2){
        *ERROR=true;
        // Serial.println(*ERROR);
        break;
      }
      Serial.println("Aguarde 15 mins");
    }
  }while(sair==false);
  led.reset();
  return true;
}
int Brassagem::T75G(int temperatura){
  Serial.println("Aguardando temperatura >= 75");
  led.set_green();
  bomba.liga();
  int temp=controlador.esquenta(temperatura);
  bomba.desliga();
  led.reset();
  return temp;
}
void Brassagem::fim(void){
	Serial.println("Fim da brassagem.");
  return;
}
#endif
