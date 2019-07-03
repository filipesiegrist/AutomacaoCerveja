/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:20:49
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 16:30:11
*/

#ifndef _SENSOR_TEMPERATURA_CPP_
#define _SENSOR_TEMPERATURA_CPP_

#include <Arduino.h>
#include "SensorTemperatura.h"


#define LIMITE_MINIMO_BRASSAGEM 60
#define LIMITE_MAXIMO_BRASSAGEM 70

SensorTemperatura::SensorTemperatura() {
	temperatura_objetivo = TEMPERATURA_PADRAO;
}


int SensorTemperatura::leitura(void) {
  int valor_sensor = analogRead(ENTRADA_SENSOR);
  // map it to the range of the analog out:
  return map(valor_sensor, 0, 1023, TEMPERATURA_MINIMA_POSSIVEL, TEMPERATURA_MAXIMA_POSSIVEL);
}

bool SensorTemperatura::passou_do_limite_maximo(void) {
	return (bool) leitura() > LIMITE_MAXIMO_BRASSAGEM;
}

bool SensorTemperatura::passou_do_limite_minimo(void) {
	return (bool) leitura() < LIMITE_MINIMO_BRASSAGEM;
}

bool SensorTemperatura::chegou_objetivo(void) {
	return (bool) leitura() >= temperatura_objetivo;
}

#endif
