/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:20:11
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:20:21
*/

#ifndef _PROCESSO_H_
#define _PROCESSO_H_
// #include <Arduino.h>
#include <iostream>
#include <string>
using namespace std;

#include "./Etapas/Brassagem.h"
#include "./Etapas/Fervura.h"
#include "./Etapas/Recirculacao.h"
#include "./Perifericos/Bomba.h"
#include "./Perifericos/Controlador.h"
#include "./Perifericos/Leds.h"

class Processo {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;
	bool resistencia;
	bool bomba;

	// A implementacao da maquina estados sera nesta funcao:
	Processo(void);

	// Estados do sistema
	Brassagem brassagem;
	Recirculacao recirculacao;
	Fervura fervura;

	~Processo();
};

#endif
