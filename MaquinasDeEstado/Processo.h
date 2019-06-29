/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:20:11
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:20:21
*/

#ifndef _PROCESSO_H_
#define _PROCESSO_H_
#include <Arduino.h>

#include "/Etapas/Brassagem.h"
#include "/Etapas/Fervura.h"
#include "/Etapas/Recirculacao.h"
#include "/Perifericos/Bomba.h"
#include "/Perifericos/Controlador.h"
#include "/Perifericos/Leds.h"


class Processo {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;
	bool resistencia=false;
	bool bomba=false;

	// A implementacao da maquina estados sera nesta funcao:
	Processo();

	// Estados do sistema
	class brassagem(void);
	class recirculacao(void);
	class fervura(void);

	~Processo();
};

#endif
