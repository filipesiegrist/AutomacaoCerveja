/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:20:11
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:20:21
*/

#ifndef _PROCESSO_H_
#define _PROCESSO_H_

class Processo {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;

	// A implementacao da maquina estados sera nesta funcao:
	Processo();

	// Estados do sistema
	void brassagem(void);
	void recirculacao(void);
	void fervura(void);

	~Processo();
};

#endif


