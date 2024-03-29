/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-29 19:30:36
*/

#ifndef _FERVURA_CPP_
#define _FERVURA_CPP_

#include <Arduino.h>

#include "Fervura.h"
#include "Controlador.h"
#include "Botao.h"
#include "Leds.h"

#define TEMPO_INICIO 8000 // 55 minutos
#define TEMPO_FIM 3000 // 5 minutos

	// Flag que indica se ocorreu algum erro no sistema.
	// bool erro_de_funcionamento;
	// A implementacao da maquina estados sera nesta funcao:
Fervura::Fervura(Leds &led,bool *gg) {
	led=led;
	this->ERROR=gg;
	led.set_green();
	Serial.println("Iniciando a fervura.");
	Serial.println("Aquecedor ligado.");
	ligaAquecedor();
	iniciaBotoes();
}

// Estados do sistema
void Fervura::fervendo(void) {
	led.set_yellow();
  Serial.println("Aperte o botao de acao quando a mistura ferver.");
  esperaAcaoUsuario(BOTAO_ACAO);
	led.set_green();
  desligaAquecedor();
	Serial.println("Aquecimento desligado.");
}

void Fervura::adicione15g(void) {
	led.set_yellow();
	Serial.println("Adicione 15g de Lupulo e aperte o botao de acao quando finalizar.");
  esperaAcaoUsuario(BOTAO_ACAO);
	led.set_green();
}

void Fervura::wait55(void) {
	led.set_green();
	Serial.println("Esperando 55 minutos.");
  int tempo = TEMPO_INICIO; //converte para ms
  delay(tempo);
}

void Fervura::add_resto(void) {
	led.set_yellow();
  Serial.println("Adicione o resto do Lupulo e aperte o botao de acao quando finalizar.");
  esperaAcaoUsuario(BOTAO_ACAO);
	led.set_green();
}

void Fervura::wait5(void) {
	led.set_green();
	Serial.println("Esperando 5 minutos.");
  int tempo = TEMPO_FIM; //converte para ms
  delay(tempo);
}

void Fervura::fim(void) {
	led.set_green();
	Serial.println("Fim da fervura.");
	delay(1000);
}


#endif
