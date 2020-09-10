#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hidrante.h"

typedef struct hidrante{
char id[20]; /*numero identificador do objeto*/
double x; /*coordenada x*/
double y; /*coordenada y*/
char cfill[20]; /*cor de preenchimento do objeto*/
char cstrk[20]; /*cor da borda do objeto*/
char sw[10]; /*espessura do objeto*/
}HidranteStruct;

Hidrante criaHidrante(char *id, double x, double y, char *cfill, char *cstrk, char *sw){
    HidranteStruct *h =(HidranteStruct*)malloc(sizeof(HidranteStruct));
    strcpy(h->id, id);
    h->x = x;
    h->y = y;
    strcpy(h->cfill, cfill);
    strcpy(h->cstrk, cstrk);
    strcpy(h->sw, sw);
    return h;
}

char *getHidranteId(Hidrante hidrante){
    HidranteStruct *h = (HidranteStruct*)hidrante;
    return h->id;
}

double getHidranteX(Hidrante hidrante){
    HidranteStruct *h = (HidranteStruct*)hidrante;
    return h->x;
}

double getHidranteY(Hidrante hidrante){
    HidranteStruct *h = (HidranteStruct*)hidrante;
    return h->y;
}

char *getHidranteCFill(Hidrante hidrante){
    HidranteStruct *h = (HidranteStruct*)hidrante;
    return h->cfill;
}

char *getHidranteCStroke(Hidrante hidrante){
    HidranteStruct *h = (HidranteStruct*)hidrante;
    return h->cstrk;
}

char *getHidranteSw(Hidrante hidrante){
    HidranteStruct *h = (HidranteStruct*)hidrante;
    return h->sw;
}