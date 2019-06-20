/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:21:45
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:21:45
*/

#ifndef _CONTROLADOR_H_
#define _CONTROLADOR_H_

// Constante de controle
#define Kp 1

//Pino de atuacao PWM
#define AQUECEDOR 4

class Controlador {
private:

	// Calcula a diferenca entre a temperatura medida e a temperatura de referencia
	int desvio_de_temperatura(int temperatura_medida);
	// Calcula o duty cicle necessario realizar a atuacao necessaria
	int calcula_duty_cicle(int temperatura_medida);
	// Satura o duty cicle entre 0 e 1.
	int saida_duty_cicle(int temperatura_medida);
public:
	int temperatura_referencia;

	// A implementacao da maquina estados sera nesta funcao:
	Controlador();

	// Estados do sistema
	void inicio(void);
	// Instancia um sensor, um atuador e gera saidas de duty cicles conforme as leituras mudam.
	void controla_temperatura();
	void fim(void);

	
	~Controlador();
	
};

#endif