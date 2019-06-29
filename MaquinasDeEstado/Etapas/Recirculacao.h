/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:27:30
*/

#ifndef _RECIRCULACAO_H_
#define _RECIRCULACAO_H_

class Recirculacao {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;

	// A implementacao da maquina estados sera nesta funcao:
	Recirculacao();

	// Estados do sistema
	void inicio(void);
	void inicio_sedimento(void);
	void sedimento_ok(void);
	void fim(void);


	~Recirculacao();

};

#endif
