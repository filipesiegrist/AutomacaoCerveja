/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:21:45
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-29 12:00:34
*/

#ifndef _CONTROLADOR_CPP_
#define _CONTROLADOR_CPP_

#include <Arduino.h>

#include "Controlador.h"
#include "SensorTemperatura.h"

int Controlador::desvio_de_temperatura(int temperatura_medida) {
	return temperatura_referencia - temperatura_medida;
}

int Controlador::calcula_duty_cicle(int temperatura_medida) {
	return Kp*desvio_de_temperatura(temperatura_medida);
}
int Controlador::saida_duty_cicle(int temperatura_medida) {
	int saida = calcula_duty_cicle(temperatura_medida);
	if (saida > 1) saida = 1;
	else if (saida < 0) saida = 0;
	return saida;
}
Controlador(int temp_objetivo) {
	pinMode(AQUECEDOR, OUTPUT);
	sensor.temperatura_objetivo = temp_objetivo;
	temperatura_referencia = temp_objetivo;
}
void Controlador::controla_temperatura() {

}

void Controlador::~Controlador() {
	// Desliga o aquecedor
	digitalWrite(AQUECEDOR,LOW);
}

#endif
