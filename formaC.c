#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formaC.h"

typedef struct formaCirculo{
  int id; /*id do circulo*/   
  double r;  /*raio*/
  double x; /*pos x*/
  double y; /*pos y*/
  char corb[20]; /*cor da borda*/
  char corp[20]; /*cor de preenchimento*/
  char cw[10]; /*espessura*/
}CirculoStruct; 

Circulo criaCirculo(int id, double r, double x, double y, char *corb, char *corp, char *cw){
    CirculoStruct *c =(CirculoStruct*)malloc(sizeof(CirculoStruct));
    c->id = id;
    c->r = r;
    c->x = x;
    c->y = y;
    strcpy(c->corb, corb);
    strcpy(c->corp, corp);
    strcpy(c->cw, cw);
    return c;
}

int getCirculoId(Circulo circulo){
    CirculoStruct *c = (CirculoStruct*)circulo;
    return c->id;
}

double getCirculoR(Circulo circulo){
    CirculoStruct *c = (CirculoStruct*)circulo;
    return c->r;
}

double getCirculoX(Circulo circulo){
    CirculoStruct *c = (CirculoStruct*)circulo;
    return c->x;
}

double getCirculoY(Circulo circulo){
    CirculoStruct *c = (CirculoStruct*)circulo;
    return c->y;
}

char *getCirculoCorb(Circulo circulo){
    CirculoStruct *c = (CirculoStruct*)circulo;
    return c->corb;
}

char *getCirculoCorp(Circulo circulo){
    CirculoStruct *c = (CirculoStruct*)circulo;
    return c->corp;
}

char *getCirculoSw(Circulo circulo){
    CirculoStruct *c = (CirculoStruct*)circulo;
    return c->cw;
}
