#ifndef FORMAR_C_
#define FORMAR_C_

typedef void* Retangulo;

Retangulo criaRetangulo(int id, double w, double h, double x, double y, double rx, double ry, char *corb, char *corp, char *rw);

int getRetanguloId(Retangulo);

double getRetanguloW(Retangulo);

double getRetanguloH(Retangulo);

double getRetanguloX(Retangulo);

double getRetanguloY(Retangulo);

double getRetanguloRX(Retangulo retangulo);

double getRetanguloRY(Retangulo retangulo);

char *getRetanguloCorb(Retangulo);

char *getRetanguloCorp(Retangulo);

char *getRetanguloSw(Retangulo retangulo);

#endif