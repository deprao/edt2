#ifndef FORMAT_C_
#define FORMAT_C_

/*define Texto como um ponteiro do tipo void*/
typedef void* Texto;

/*cria um elemento do tipo texto, e retorna um ponteiro para o elemento criado*/
Texto criaTexto(int id, double x, double y, char *corb, char *corp, char *text);

/*recebe o endereço de um elemento da lista e retorna o Id do elemento*/
int getTextoId(Texto texto);

/*recebe o endereço de um elemento da lista e retorna o X do elemento*/
double getTextoX(Texto);

/*recebe o endereço de um elemento da lista e retorna o Y do elemento*/
double getTextoY(Texto);

/*recebe o endereço de um elemento da lista e retorna o Corb do elemento*/
char *getTextoCorb(Texto);

/*recebe o endereço de um elemento da lista e retorna o Corp do elemento*/
char *getTextoCorp(Texto);

/*recebe o endereço de um elemento da lista e retorna o Texto do elemento*/
char *getTextoText(Texto);

#endif