/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 11:56:07
*/

#ifndef _BRASSAGEM_CPP_
#define _BRASSAGEM_CPP_

#include "Brassagem.h"
#define TEMPO_IODO 5000


// Flag que indica se ocorreu algum erro no sistema.
// bool erro_de_funcionamento;
// A implementacao da maquina estados sera nesta funcao:
Brassagem::Brassagem(Leds &led){
  led=led;
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
void Brassagem::T70G(void){
  Serial.println("Aguardando temperatura >= 70");
  led.set_green();
  bomba.liga();
  controlador.esquenta(70);
  bomba.desliga();
  led.reset();
  return;
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
  controlador.temperatura_referencia = TEMPERATURA;
  controlador.controla_temperatura();
  led.reset();
  return;
}
void Brassagem::aguarda_iodo(void){
  bool sair=false;
  led.set_green();
  Serial.println("Teste do Iodo! aguarda 15 mins");
  do{
      led.set_green();
      delay(TEMPO_IODO);
      led.set_yellow();
      Serial.println("iodo OK? BOTAO_ON_OFFBOTAO_ACAO");
      Serial.println("Aperte BOTAO_ON_OFF para Sim");
      Serial.println("Aperte BOTAO_ACAO para Não");
      if(esperaApertoDeUmBotao(BOTAO_ON_OFF,BOTAO_ACAO)){
          sair=true;
      }else{
          Serial.println("Aguarde 15 mins");
      }
  }while(sair==false);
  led.reset();
  return;
}
void Brassagem::T75G(void){
  Serial.println("Aguardando temperatura >= 75");
  led.set_green();
  bomba.liga();
  controlador.esquenta(75);
  bomba.desliga();
  led.reset();
  return;
}
void Brassagem::fim(void){
	Serial.println("Fim da brassagem.");
  return;
}
#endif
