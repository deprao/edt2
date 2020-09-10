#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadra.h"

typedef struct quadra{
char cep[20]; /*identificação de quadra*/
double x; /*coordenada x*/
double y; /*coordenada y*/
double w; /*largura da quadra*/
double h; /*altura da quadra*/
char cfill[20]; /*cor de preenchimento da quadra*/
char cstrk[20]; /*cor da borda da quadra*/
char sw[10]; /*espessura da borda da quadra*/
}QuadraStruct;

Quadra criaQuadra(char *cep, double x, double y, double w, double h, char *cfill, char *cstrk, char *sw){
    QuadraStruct *q = (QuadraStruct*)malloc(sizeof(QuadraStruct));
    strcpy(q->cep, cep);
    q->x = x;
    q->y = y;
    q->w = w;
    q->h = h;
    strcpy(q->cfill, cfill);
    strcpy(q->cstrk, cstrk);
    strcpy(q->sw, sw);
    return q;
}

char *getQuadraCep(Quadra quadra){
    QuadraStruct *q = (QuadraStruct*)quadra;
    return q->cep;
}

double getQuadraX(Quadra quadra){
    QuadraStruct *q = (QuadraStruct*)quadra;
    return q->x;
}

double getQuadraY(Quadra quadra){
    QuadraStruct *q = (QuadraStruct*)quadra;
    return q->y;
}

double getQuadraW(Quadra quadra){
    QuadraStruct *q = (QuadraStruct*)quadra;
    return q->w;
}

double getQuadraH(Quadra quadra){
    QuadraStruct *q = (QuadraStruct*)quadra;
    return q->h;
}

char *getQuadraCFill(Quadra quadra){
    QuadraStruct *q = (QuadraStruct*)quadra;
    return q->cfill;
}

char *getQuadraCStroke(Quadra quadra){
    QuadraStruct *q = (QuadraStruct*)quadra;
    return q->cstrk;
}

char *getQuadraSw(Quadra quadra){
    QuadraStruct *q = (QuadraStruct*)quadra;
    return q->sw;
}

void setQuadCStroke(Quadra quadra, char *Cstroke){
    QuadraStruct *q = (QuadraStruct*)quadra;
    strcpy(q->cstrk, Cstroke);
}