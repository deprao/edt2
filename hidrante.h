#ifndef HIDRANTE_H_
#define HIDRANTE_H_

/*Define Hidrante como um ponteiro do tipo void*/
typedef void* Hidrante;

/*Cria um elementro da struct Hidrante_S*/
Hidrante criaHidrante(char *id, double x, double y, char *cfill, char *cstrk, char *sw);

/*Retorna a Id de um elemento de uma lista de hidrantes*/
char *getHidranteId(Hidrante);

/*Retorna X de um elemento de uma lista de hidrantes*/
double getHidranteX(Hidrante);

/*Retorna Y de um elemento de uma lista de hidrantes*/
double getHidranteY(Hidrante);

/*Retorna CFill de um elemento de uma lista de hidrantes*/
char *getHidranteCFill(Hidrante);

/*Retorna CStroke de um elemento de uma lista de hidrantes*/
char *getHidranteCStroke(Hidrante);

char *getHidranteSw(Hidrante hidrante);

#endif