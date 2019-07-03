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

const byte ledLookupTable[] = {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,11,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,23,23,24,24,25,26,26,27,28,28,29,30,30,31,32,32,33,34,35,35,36,37,38,38,39,40,41,42,42,43,44,45,46,47,47,48,49,50,51,52,53,54,55,56,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,73,74,75,76,77,78,79,80,81,82,84,85,86,87,88,89,91,92,93,94,95,97,98,99,100,102,103,104,105,107,108,109,111,112,113,115,116,117,119,120,121,123,124,126,127,128,130,131,133,134,136,137,139,140,142,143,145,146,148,149,151,152,154,155,157,158,160,162,163,165,166,168,170,171,173,175,176,178,180,181,183,185,186,188,190,192,193,195,197,199,200,202,204,206,207,209,211,213,215,217,218,220,222,224,226,228,230,232,233,235,237,239,241,243,245,247,249,251,253,255};

void ligaLed(int pino, int saida) {
	analogWrite(pino, ledLookupTable[saida]);
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
}
void Controlador::controla_temperatura(int temperatura_in) {
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
		// Serial.println(temperatura);
		// Serial.println(duty_cycle);
		int saida = map(duty_cycle, 0, 1, 0, 1023);
		ligaLed(AQUECEDOR, saida);
		tempo_atual = millis();
		delta_t = tempo_atual - tempo_inicial;
	}
	Serial.println(temperatura);
	analogWrite(AQUECEDOR, 0);
}

void Controlador::esquenta(int temperatura_in) {
	sensor.temperatura_objetivo = temperatura_in;
	temperatura_referencia = temperatura_in;
	int temperatura = sensor.leitura();
	while (temperatura < temperatura_in) {
		delay(20);
		temperatura = sensor.leitura();
		float duty_cycle = saida_duty_cicle(temperatura);
		// Serial.println(temperatura);
		// Serial.println(duty_cycle);
		int saida = map(duty_cycle, 0, 1, 0, 1023);
		ligaLed(AQUECEDOR, saida);
	}
	Serial.println(temperatura);
	analogWrite(AQUECEDOR, 0);
}

Controlador::~Controlador() {
		analogWrite(AQUECEDOR, 0);
}

void ligaAquecedor() {
	analogWrite(AQUECEDOR,1023);
}
void desligaAquecedor() {
	analogWrite(AQUECEDOR,0);
}

#endif
