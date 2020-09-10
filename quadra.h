#ifndef QUADRA_H_
#define QUADRA_H_

/*Define Quadra como um ponteiro void*/
typedef void* Quadra;

/*Cria um elemento do tipo da struct Quadra_S*/
Quadra criaQuadra(char *cep, double x, double y, double w, double h, char *cfill, char *cstrk, char *sw);

/*Retorna Cep de um elemento da lista de Quadras*/
char *getQuadraCep(Quadra);

/*Retorna X de um elemento da lista de Quadras*/
double getQuadraX(Quadra);

/*Retorna Y de um elemento da lista de Quadras*/
double getQuadraY(Quadra);

/*Retorna W de um elemento da lista de Quadras*/
double getQuadraW(Quadra);

/*Retorna H de um elemento da lista de Quadras*/
double getQuadraH(Quadra);

/*Retorna o Cfill de um elemento da lista de Quadras*/
char *getQuadraCFill(Quadra);

/*Retorna o CStroke de um elemento da lista de Quadras*/
char *getQuadraCStroke(Quadra);

/*Retorna a espessura da borda de um elemento da lista de Quadras*/
char *getQuadraSw(Quadra quadra);

/*Atribui uma cor de borda CStroke a um elemento da lista de Quadras*/
void setQuadCStroke(Quadra quadra, char *Cstroke);

#endif