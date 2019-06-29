/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:21:45
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-29 11:44:46
*/

#ifndef _CONTROLADOR_CPP_
#define _CONTROLADOR_CPP_

#include "Controlador.h"

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
Controlador() {

}
void Controlador::inicio(void) {

}
void Controlador::controla_temperatura() {

}
void Controlador::fim(void) {

}

#endif
