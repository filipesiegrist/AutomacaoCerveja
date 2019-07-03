/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:27:30
*/

#ifndef _RECIRCULACAO_LAVAGEM_H_
#define _RECIRCULACAO_LAVAGEM_H_

#include "Leds.h"

class RecirculacaoLavagem {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;
	RecirculacaoLavagem(Leds &led)
	// Estados do sistema
	void inicio(void);
	void transfere(void);
	void fim(void);

	Leds &led;

};

#endif
