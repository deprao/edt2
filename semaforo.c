#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semaforo.h"

typedef struct semaforo{
char id[20]; /*identificador do objeto*/
double x; /*coordenada x*/
double y; /*coordenada y*/
char cfill[20]; /*cor de preenchimento do objeto*/
char cstrk[20]; /*cor da borda do objeto*/
char sw[10]; /*espessura da borda de semaforo*/
}SemaforoStruct;

Semaforo criaSemaforo(char *id, double x, double y, char *cfill, char *cstrk, char *sw){
    SemaforoStruct *s = (SemaforoStruct*)malloc(sizeof(SemaforoStruct));
    strcpy(s->id, id);
    s->x = x;
    s->y = y;
    strcpy(s->cfill, cfill);
    strcpy(s->cstrk, cstrk);
    strcpy(s->sw, sw);
    return s;
}

char *getSemaforoId(Semaforo semaforo){
    SemaforoStruct *s = (SemaforoStruct*)semaforo;
    return s->id;
}

double getSemaforoX(Semaforo semaforo){
    SemaforoStruct *s = (SemaforoStruct*)semaforo;
    return s->x;
}

double getSemaforoY(Semaforo semaforo){
    SemaforoStruct *s = (SemaforoStruct*)semaforo;
    return s->y;
}

char *getSemaforoCFill(Semaforo semaforo){
    SemaforoStruct *s = (SemaforoStruct*)semaforo;
    return s->cfill;
}

char *getSemaforoCStroke(Semaforo semaforo){
    SemaforoStruct *s = (SemaforoStruct*)semaforo;
    return s->cstrk;
}

char *getSemaforoSw(Semaforo semaforo){
    SemaforoStruct *s = (SemaforoStruct*)semaforo;
    return s->sw;
}