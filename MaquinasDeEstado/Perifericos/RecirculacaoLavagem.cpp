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
#include "RecirculacaoLavagem.h"

// Flag que indica se ocorreu algum erro no sistema.
// bool erro_de_funcionamento;

// Estados do sistema
void RecirculacaoLavagem::inicio(void){
	Serial.println("Inicie a recirculacao e a lavagem. Aperte o botao de acao quando finaliza-las.");
}

void RecirculacaoLavagem::transfere(void){
	esperaAcaoUsuario(BOTAO_ACAO);
}

void RecirculacaoLavagem::fim(void) {
	Serial.println("Fim da Recirculacao e da lavagem.");
}

#endif
