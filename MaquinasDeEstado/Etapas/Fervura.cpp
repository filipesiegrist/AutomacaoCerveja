/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-29 17:14:09
*/

#ifndef _FERVURA_CPP_
#define _FERVURA_CPP_

#include "Fervura.h"
#include "../Controlador.h"

	// Flag que indica se ocorreu algum erro no sistema.
	// bool erro_de_funcionamento;
	// A implementacao da maquina estados sera nesta funcao:
Fervura::Fervura(){
	Serial.println("Iniciando a fervura.");
	Serial.println("Aquecedor ligado.");
	ligaAquecedor();
}

// Estados do sistema
void Fervura::fervendo(void){

  return;
}

void Fervura::adicione15g(void){

  return;
}

void Fervura::wait55(void){

  return;
}

void Fervura::add_resto(void){

  return;
}

void Fervura::wait5(void){

  return;
}

void Fervura::fim(void){

  return;
}

Fervura::Fervura(){

}

#endif
