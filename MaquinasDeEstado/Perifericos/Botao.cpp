/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 11:56:07
*/

#ifndef _BOTAO_CPP_
#define _BOTAO_CPP_

#include "Botao.h"
#include <Arduino.h>

void iniciaBotoes() {
  pinMode(BOTAO_ACAO,INPUT);
  pinMode(BOTAO_ON_OFF,INPUT);
}

void esperaAcaoUsuario(int botao) {
  int valor = digitalRead(botao);
  while (valor == LOW) {
    valor = digitalRead(botao);
    delay(10);
  }
}

#endif
