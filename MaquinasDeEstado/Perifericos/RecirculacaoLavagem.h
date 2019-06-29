/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:27:30
*/

#ifndef _RECIRCULACAO_LAVAGEM_H_
#define _RECIRCULACAO_LAVAGEM_H_

class RecirculacaoLavagem {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;

	// Estados do sistema
	void inicio(void);
	void transfere(void);

};

#endif
