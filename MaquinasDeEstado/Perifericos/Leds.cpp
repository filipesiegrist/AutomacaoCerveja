/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:24:35
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 16:30:02
*/

#ifndef _LEDS_CPP_
#define _LEDS_CPP_

#include <Arduino.h>

#include "Leds.h"

// A implementacao da maquina estados sera nesta funcao:
Leds::Leds(){
    pinMode(LED_VERMELHO, OUTPUT); 
    pinMode(LED_VERDE   , OUTPUT); 
    pinMode(LED_AMARELO , OUTPUT);
    reset();
}

void Leds::reset(void){
    digitalWrite(LED_VERMELHO ,LOW); 
    digitalWrite(LED_VERDE    ,LOW); 
    digitalWrite(LED_AMARELO  ,LOW);
    return;
}
void Leds::set_red(void){
    reset();
    digitalWrite(LED_VERMELHO ,HIGH);
    return;
}
void Leds::set_yellow(void){
    reset();
    digitalWrite(LED_AMARELO  ,HIGH);
    return;
}
void Leds::set_green(void){
    reset();
    digitalWrite(LED_VERDE    ,HIGH);
    return;
}

Leds::~Leds(){
    reset();
}
#endif