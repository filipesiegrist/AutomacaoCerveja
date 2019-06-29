/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:20:49
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:20:49
*/

#ifndef _SENSOR_TEMPERATURA_H_
#define _SENSOR_TEMPERATURA_H_

#include <Arduino.h>

// Pino de entrada
#define ENTRADA_SENSOR A0

// Temperaturas de referencia para o mapeamento do sinal do sensor
#define TEMPERATURA_MINIMA_POSSIVEL 45
#define TEMPERATURA_MAXIMA_POSSIVEL 85

class SensorTemperatura {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;

	int temperatura_objetivo;
	// Se o sensor ultrapassar essas temperaturas, ocorrera um erro.
	int temperatura_minima;
	int temperatura_maxima;

	SensorTemperatura(int);
	SensorTemperatura(int, int, int);

	// Estados do sistema
	int leitura(void);
	bool chegou_objetivo(void);
	bool passou_do_limite_maximo(void);
	bool passou_do_limite_minimo(void);
	void fim(void);


	~SensorTemperatura();

};

#endif
