//This file was generated from (Commercial) UPPAAL 4.0.14 (rev. 5615), May 2014

/*
Nunca ocorrer\u00e1 deadlock
[SAFETY]
*/
A[] not deadlock

/*
Quando o processo inicia, a bomba e o fogo sempre estar\u00e3o desligados
[SAFETY
*/
A[](Brassagem.Inicio imply (bomba==false and fogo==false))

/*

*/
//NO_QUERY

/*
Os ingredientes s\u00f3 ser\u00e3o adicionados ap\u00f3s a temperatura ter atingido 70\u00baC.
[SAFETY]

*/
A<>( Brassagem.T70G imply Brassagem.add_ing)

/*
O teste do iodo s\u00f3 ocorrer\u00e1 com o fogo desligado e ap\u00f3s transcorrida uma hora de espera na brassagem.
[SAFETY]
*/
A[](Brassagem.aguarda_iodo imply (Brassagem.time>=60 and fogo==false) )

/*
Uma vez iniciado, eventualmente o teste do iodo ser\u00e1 finalizado;
[LIVENESS]
*/
E<> Brassagem.Iodo_OK

/*

*/
//NO_QUERY

/*
A transfer\u00eancia na lavagem sempre ocorrer\u00e1 com o fogo desligado
[SAFETY]
*/
A[] (Lavagem.Transfere imply  fogo==false)

/*
Eventualmente a lavagem ser\u00e1 finalizada ap\u00f3s a segunda panela ficar cheia. 
[LIVENESS]
*/
E<>(User.panela_cheia and Lavagem.Fim)

/*
Uma vez que a segunda panela fique cheia, a lavagem sempre ser\u00e1 finalizada. 
[LIVENESS]


*/
A[](User.panela_cheia imply Lavagem.Fim)

/*

*/
//NO_QUERY

/*
A fervura nunca terminar\u00e1 em menos de 55min
[SAFETY]
*/
A[] not (Fervura.Fim and Fervura.global_time<=55)

/*
O fogo s\u00f3 ser\u00e1 desligado 5 minutos ap\u00f3s o restante do l\u00fapulo ser adicionado.
[SAFETY]
*/
A<> (Fervura.Fim imply( fogo==false and Fervura.time>=5))

/*
Ap\u00f3s o usu\u00e1rio informar que adicionou os 15 gramas de l\u00fapulo, a mensagem para adicionar o resto aparecer\u00e1.
[LIVENESS]
*/
Fervura.wait55 --> Fervura.add_resto

/*
Depois que o fogo for ligado, eventualmente a mistura ir\u00e1 ferver.
*/
//NO_QUERY
