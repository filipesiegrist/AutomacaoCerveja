/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:24:35
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:24:35
*/

#ifndef _LEDS_H_
#define _LEDS_H_
// #include <Arduino.h>
// Pinos de saida
#define LED_VERDE    8
#define LED_AMARELO  9
#define LED_VERMELHO 10

class Leds {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;
	// A implementacao da maquina estados sera nesta funcao:
	Leds();
	// Estados do sistema
	void reset(void);
	void set_red(void);
	void set_yellow(void);
	void set_green(void);

	~Leds();
};

#endif
