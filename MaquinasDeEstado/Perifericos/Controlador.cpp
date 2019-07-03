/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:21:45
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-29 17:09:35

*/

#ifndef _CONTROLADOR_CPP_
#define _CONTROLADOR_CPP_

#include <Arduino.h>

#include "Controlador.h"
#include "SensorTemperatura.h"

#define TRUE 1


void atuacao(int pino, int saida) {
	analogWrite(pino, saida);
}

int Controlador::desvio_de_temperatura(int temperatura_medida) {
	return temperatura_referencia - temperatura_medida;
}

float Controlador::calcula_duty_cicle(int temperatura_medida) {
	return (float) Kp*desvio_de_temperatura(temperatura_medida);
}
float Controlador::saida_duty_cicle(int temperatura_medida) {
	int saida = calcula_duty_cicle(temperatura_medida);
	if (saida > 1) saida = 1;
	else if (saida < 0) saida = 0;
	return saida;
}
Controlador::Controlador(void) {
	sensor.temperatura_objetivo = TEMPERATURA;
	temperatura_referencia = TEMPERATURA;
	pinMode(AQUECEDOR, OUTPUT);
}
int Controlador::controla_temperatura(int temperatura_in) {
	sensor.temperatura_objetivo = temperatura_in;
	temperatura_referencia = temperatura_in;
	int tempo_inicial = millis();
	int tempo_atual = millis();
	int delta_t = tempo_atual - tempo_inicial;
	int temperatura;
	while (delta_t < TEMPO_BRASSAGEM) {
		delay(20);
		temperatura = sensor.leitura();
		float duty_cycle = saida_duty_cicle(temperatura);
		Serial.println(temperatura);
		// Serial.println(duty_cycle);
		int saida = map(duty_cycle, 0, 1, 0, 255);
		atuacao(AQUECEDOR, saida);
		tempo_atual = millis();
		delta_t = tempo_atual - tempo_inicial;
	}
	// Serial.println(temperatura);
	atuacao(AQUECEDOR, 0);
	return temperatura;
}

int Controlador::esquenta(int temperatura_in) {
	sensor.temperatura_objetivo = temperatura_in;
	temperatura_referencia = temperatura_in;
	int temperatura = sensor.leitura();
	while (temperatura < temperatura_in) {
		delay(20);
		temperatura = sensor.leitura();
		float duty_cycle = saida_duty_cicle(temperatura);
		Serial.println(temperatura);
		// Serial.println(duty_cycle);
		int saida = map(duty_cycle, 0, 1, 0, 255);
		atuacao(AQUECEDOR, saida);

	}
	Serial.println(temperatura);
	atuacao(AQUECEDOR, 0);
	return temperatura;
}

Controlador::~Controlador() {
		analogWrite(AQUECEDOR, 0);
}

bool ligaAquecedor() {
	analogWrite(AQUECEDOR,1023);
	return true;
}
bool desligaAquecedor() {
	analogWrite(AQUECEDOR,0);
	return true;
}

#endif
