/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:20:49
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 15:48:31
*/

#ifndef _SENSOR_TEMPERATURA_CPP_
#define _SENSOR_TEMPERATURA_CPP_

#include "SensorTemperatura.h"

SensorTemperatura::SensorTemperatura(int objetivo) {
	temperatura_objetivo = objetivo;
}

SensorTemperatura::SensorTemperatura(int objetivo, int minima, int maxima) {
	temperatura_objetivo = objetivo;
	temperatura_maxima = maxima;
	temperatura_minima = minima;
}

SensorTemperatura::passou_do_limite_maximo(void) {
	return (bool) leitura() > temperatura_maxima;
}

SensorTemperatura::passou_do_limite_minimo(void) {
	return (bool) leitura() < temperatura_minima;
}

#endif