/*
* @Author: Filipe Ernesto Siegrist Gonçalves
* @Date:   2019-06-20 10:27:30
* @Last Modified by:   filipe-ufsc
* @Last Modified time: 2019-06-20 11:56:07
*/

#ifndef _BRASSAGEM_CPP_
#define _BRASSAGEM_CPP_

// Flag que indica se ocorreu algum erro no sistema.
// bool erro_de_funcionamento;
// A implementacao da maquina estados sera nesta funcao:
Brassagem::Brassagem(void){

}
// Estados do sistema
void Brassagem::inicio(bool resistencia){
  Serial.println("Aguardando inicialização");
  set_yellow();
  esperaAcaoUsuario(BOTAO_ON_OFF);
  reset();
  return;
}
void Brassagem::T70G(void){
  Serial.println("Aguardando temperatuda >= 70");
  led.set_green();
  bomba::liga();
  esquenta(70);
  bomba::desliga();
  reset();
  return;
}
void Brassagem::add_ing(void){
  Serial.println("Adicione ingredientes");
  set_yellow();
  esperaAcaoUsuario(BOTAO_ON_OFF);
  reset();
  return;
}
void Brassagem::misturar(void){
  Serial.println("Adicione ingredientes");
  set_yellow();
  esperaAcaoUsuario(BOTAO_ON_OFF);
  reset();
  return;
}
void Brassagem::esperar(void){

  return;
}
void Brassagem::aguarda_iodo(void){

  return;
}
void Brassagem::iodo_ok(void){

  return;
}
void Brassagem::T75G(void){

  return;
}
void Brassagem::fim(void){

  return;
}

Brassagem::~Brassagem(){

}


#endif
