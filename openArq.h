#ifndef OPENARQ_H_
#define OPENARQ_H_

#include "lista.h"

void openGeo(Cidade listacidade, char *nomeGeo, char *saidaSvg);

void openQry(Cidade listacidade, char *entradaQry, char *saidaQry);

char *trataNome(char nome[]);

void tratamento(char path[], char outPath[], char paramGeo[], char paramQry[]);

#endif