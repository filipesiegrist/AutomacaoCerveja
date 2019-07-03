/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-29 19:31:16
*/

#ifndef _RECIRCULACAO_LAVAGEM_CPP_
#define _RECIRCULACAO_LAVAGEM_CPP_

#include <Arduino.h>
#include "Botao.h"
#include "Leds.h"
#include "RecirculacaoLavagem.h"

// Flag que indica se ocorreu algum erro no sistema.
// bool erro_de_funcionamento;

RecirculacaoLavagem::RecirculacaoLavagem(Leds &led,bool *gg){
	led=led;
	this->ERROR=gg;
}


// Estados do sistema
void RecirculacaoLavagem::inicio(void){
	led.set_green();
	Serial.println("Inicie a recirculacao e a lavagem. Aperte o botao de acao quando finaliza-las.");
}

void RecirculacaoLavagem::transfere(void){
	led.set_yellow();
	esperaAcaoUsuario(BOTAO_ACAO);
}

void RecirculacaoLavagem::fim(void) {
	led.set_green();
	Serial.println("Fim da Recirculacao e da lavagem.");
}

#endif
