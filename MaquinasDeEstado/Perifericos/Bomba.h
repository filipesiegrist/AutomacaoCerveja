/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 15:21:09
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 15:21:09
*/

#ifndef _BOMBA_H_
#define _BOMBA_H_

#include <Arduino.h>

#define BOMBA 7

class Bomba {
public:
  Bomba();
  void liga();
  void desliga();
  ~Bomba();
};

#endif
