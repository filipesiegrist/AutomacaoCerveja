/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:20:49
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:20:49
*/

#ifndef _SENSOR_TEMPERATURA_H_
#define _SENSOR_TEMPERATURA_H_

// Pino de entrada
#define ENTRADA_SENSOR A0

class SensorTemperatura {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;

	// A implementacao da maquina estados sera nesta funcao:
	SensorTemperatura();

	// Estados do sistema
	void inicio(void);
	void ligar(void);
	int leitura(void);
	void desligar(void);
	void fim(void);

	
	~SensorTemperatura();
	
};

#endif