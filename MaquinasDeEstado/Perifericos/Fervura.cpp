/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-29 17:49:14
*/

#ifndef _FERVURA_CPP_
#define _FERVURA_CPP_

#include "Fervura.h"
#include "Controlador.h"
#include "Botoes.h"

#define TEMPO_INICIO = 55 // minutos
#define TEMPO_FIM = 5 // minutos

	// Flag que indica se ocorreu algum erro no sistema.
	// bool erro_de_funcionamento;
	// A implementacao da maquina estados sera nesta funcao:
Fervura::Fervura(){
	Serial.println("Iniciando a fervura.");
	Serial.println("Aquecedor ligado.");
	ligaAquecedor();
	iniciaBotoes();
}

// Estados do sistema
void Fervura::fervendo(void){
  	Serial.println("Aperte o botao on/off quando a mistura ferver.");
  	esperaAcaoUsuario(BOTAO_ACAO);
  	desligaAquecedor();
}

void Fervura::adicione15g(void){
	Serial.println("Adicione 15g de Lupulo e aperte o botao on/off quando finalizar.");
  	esperaAcaoUsuario(BOTAO_ACAO);
}

void Fervura::wait55(void){
	Serial.println("Esperando 55 minutos.");
  	const int tempo = TEMPO_INICIO*60*1000; //converte para ms
  	delay(tempo);
}

void Fervura::add_resto(void){
  Serial.println("Adicione o resto do Lupulo e aperte o botao on/off quando finalizar.");
  	esperaAcaoUsuario(BOTAO_ACAO);
}

void Fervura::wait5(void){
	Serial.println("Esperando 5 minutos.");
  	const int tempo = TEMPO_FIM*60*1000; //converte para ms
  	delay(tempo);
}

void Fervura::fim(void){
	Serial.println("Fim da fervura. Desligando o aquecedor.");
}


#endif
