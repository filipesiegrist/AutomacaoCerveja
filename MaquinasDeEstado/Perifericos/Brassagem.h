/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:27:30
*/

#ifndef _BRASSAGEM_H_
#define _BRASSAGEM_H_

#include <Arduino.h>
#include "Controlador.h"
#include "Leds.h"
#include "Bomba.h"
#include "Botao.h"

class Brassagem {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;
	// A implementacao da maquina estados sera nesta funcao:
	Brassagem(Leds &led,bool *gg);
	// ~Brassagem();
	// Estados do sistema
	void inicio(void);
	int T70G(int temperatura);
	void add_ing(void);
	void misturar(void);
	void esperar(void);
	bool aguarda_iodo(void);
	int T75G(int temperatura);
	void fim(void);
	// Processo asd;
	Leds &led;
	bool *ERROR;
	Bomba bomba;
	Controlador controlador;
};

#endif
