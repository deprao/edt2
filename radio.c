#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "radio.h"

typedef struct radio{
    char id[20]; /*identificador do objeto*/
    double x; /*coordenada x do objeto*/
    double y; /*coordenada y do objeto*/
    char cfill[20]; /*cor de preenchimento do objeto*/
    char cstrk[20]; /*cor de borda do objeto*/
    char sw[10]; /*espessura da borda do objeto*/
}RadioStruct;

Radio criaRadio(char *id, double x, double y, char *cfill, char *cstrk, char *sw){
    RadioStruct *r = (RadioStruct*)malloc(sizeof(RadioStruct));
    strcpy(r->id, id);
    r->x = x;
    r->y = y;
    strcpy(r->cfill, cfill);
    strcpy(r->cstrk, cstrk);
    strcpy(r->sw, sw);
    return r;
}

char *getRadioId(Radio radio){
    RadioStruct *r = (RadioStruct*)radio;
    return r->id;
}

double getRadioX(Radio radio){
    RadioStruct *r = (RadioStruct*)radio;
    return r->x;
}

double getRadioY(Radio radio){
    RadioStruct *r = (RadioStruct*)radio;
    return r->y;
}

char *getRadioCFill(Radio radio){
    RadioStruct *r = (RadioStruct*)radio;
    return r->cfill;
}

char *getRadioCStroke(Radio radio){
    RadioStruct *r = (RadioStruct*)radio;
    return r->cstrk;
}

char *getRadioSw(Radio radio){
    RadioStruct *r = (RadioStruct*)radio;
    return r->sw;
}