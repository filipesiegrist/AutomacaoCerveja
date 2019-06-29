/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:21:45
* @Last Modified by:   filipe-ufsc
<<<<<<< Updated upstream
* @Last Modified time: 2019-06-20 16:19:10
=======
* @Last Modified time: 2019-06-29 12:43:30
>>>>>>> Stashed changes
*/

#ifndef _CONTROLADOR_CPP_
#define _CONTROLADOR_CPP_

#include "Controlador.h"

int Controlador::desvio_de_temperatura(int temperatura_medida) {

}

int Controlador::calcula_duty_cicle(int temperatura_medida) {

}
int Controlador::saida_duty_cicle(int temperatura_medida) {

}
Controlador() {

}
void Controlador::inicio(void) {

}
void Controlador::controla_temperatura() {
<<<<<<< Updated upstream

=======
	int tempo_inicial = millis();
	int tempo_atual = millis();
	int delta_t = tempo_atual - tempo_inicial;
	while (delta_t < TEMPO_BRASSAGEM) {
		delay(20);
		int temperatura = sensor.leitura();
		int duty_cicle = saida_duty_cicle(temperatura);
		int saida = map(duty_cicle, 0, 1, 0, 1023);
		analogWrite(AQUECEDOR, saida);
		tempo_atual = millis();
		delta_t = tempo_atual - tempo_inicial;
	}
>>>>>>> Stashed changes
}
void Controlador::fim(void) {

}

#endif
