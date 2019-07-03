/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 11:56:07
*/

#ifndef _BOTAO_H_
#define _BOTAO_H_

#define BOTAO_ON_OFF 11
#define BOTAO_ACAO 12

void iniciaBotoes();

void esperaAcaoUsuario(int botao);

// Retorna verdadeiro se apertou o primeiro botao,
// False se apertou o segundo.
bool esperaApertoDeUmBotao(int botao_1, int botao_2);

#endif
