/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 15:21:09
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 15:21:09
*/

#ifndef _BOMBA_CPP
#define _BOMBA_CPP_

#include <Arduino.h>
#include "Bomba.h"

#define BOMBA 7

Bomba::Bomba() {
  pinMode(BOMBA,OUTPUT);
}

void Bomba::liga() {
  digitalWrite(BOMBA,HIGH);
}
void Bomba::desliga() {
  digitalWrite(BOMBA,LOW);
}

Bomba::~Bomba() {
  digitalWrite(BOMBA,LOW);
}

#endif
