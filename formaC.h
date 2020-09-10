#ifndef FORMAC_C_
#define FORMAC_C_

/*Define Circulo como um ponteiro do tipo void*/
typedef void* Circulo;

/*Cria um elemento do tipo Circulo e retorna o seu endereço*/
Circulo criaCirculo(int id, double r, double x, double y, char *corb, char *corp, char *cw);

/*Recebe o endereço de uma lista de circulos e retorna o Id do elemento*/
int getCirculoId(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna o R do elemento*/
double getCirculoR(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna o X do elemento*/
double getCirculoX(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna o Y do elemento*/
double getCirculoY(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna a Corb do elemento*/
char *getCirculoCorb(Circulo);

/*Recebe o endereço de uma lista de circulos e retorna a Corp do elemento*/
char *getCirculoCorp(Circulo);

/*Recebe o endereço de uma lista de círculos e retorna a espessura da borda do elemento*/
char *getCirculoSw(Circulo circulo);

#endif