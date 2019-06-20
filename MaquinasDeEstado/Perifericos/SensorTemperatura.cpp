/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:20:49
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 15:43:16
*/

#ifndef _SENSOR_TEMPERATURA_CPP_
#define _SENSOR_TEMPERATURA_CPP_

#include "SensorTemperatura.h"

SensorTemperatura::passou_do_limite_maximo(void) {
	return (bool) leitura() > temperatura_maxima;
}

SensorTemperatura::passou_do_limite_minimo(void) {
	return (bool) leitura() < temperatura_minima;
}

#endif