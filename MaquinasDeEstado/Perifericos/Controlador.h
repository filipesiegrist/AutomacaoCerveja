/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:21:45
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:21:45
*/

#ifndef _CONTROLADOR_H_
#define _CONTROLADOR_H_

#include <Arduino.h>

#include "SensorTemperatura.h"

// Constante de controle
#define Kp 1

//Pino de atuacao PWM
#define AQUECEDOR A1
#define TEMPO_BRASSAGEM 5000
#define TEMPERATURA  66


class Controlador {
private:
	// Sensor com os dados de entrada
	SensorTemperatura sensor;

	// Calcula a diferenca entre a temperatura medida e a temperatura de referencia
	int desvio_de_temperatura(int temperatura_medida);
	// Calcula o duty cicle necessario realizar a atuacao necessaria
	float calcula_duty_cicle(int temperatura_medida);
	// Satura o duty cicle entre 0 e 1.
	float saida_duty_cicle(int temperatura_medida);
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;

	// Quem instanciar essa classe, tera que definir esta temperatura de referencia
	int temperatura_referencia;

	// A implementacao da maquina estados sera nesta funcao:
	Controlador(void);

	// Estados do sistema
	// Instancia um sensor, um atuador e gera saidas de duty cicles conforme as leituras mudam.
	int controla_temperatura(int temperatura_in);
	void esquenta(int temperatura);

	~Controlador();
};


// Para utilizar apenas ligando e desligando a resistencia:
bool ligaAquecedor();
bool desligaAquecedor();

#endif
