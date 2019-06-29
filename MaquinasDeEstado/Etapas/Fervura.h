/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 10:27:30
*/

#ifndef _FERVURA_H_
#define _FERVURA_H_

class Fervura {
public:
	// Flag que indica se ocorreu algum erro no sistema.
	bool erro_de_funcionamento;

	// A implementacao da maquina estados sera nesta funcao:
	Fervura();

	// Estados do sistema
	void fervendo();
	void adicione15g(void);
	void wait55(void);
	void add_resto(void);
	void wait5(void);

	~Fervura();
};

#endif
