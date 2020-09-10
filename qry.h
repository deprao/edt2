#ifndef QRYCUSTOM_H_
#define QRYCUSTOM_H_
#include<stdio.h>
#include"lista.h"

/*Função que remove quadras inteiramente internas à um círculo de raio r e centro coincidente ao do equipamento urbano id*/
void delQuadras(Cidade listaCidade, FILE *txt, int htag, char *id, double r);

/*Função que remove uma quadra ou equipamento urbano, de acordo com seu cep ou id*/
void delUrb(Cidade listaCidade, FILE *txt, char *cid);

/*Função que muda a cor das bordas das quadras inteiramente contidas em um círculo de centro (x,y) e raio r, para uma cor cstrk*/
void colorBorder(Cidade listaCidade, FILE *txt, double x, double y, double r, char *cstrk);

/*Procedimento que escreve em um relatório .txt as coordenadas e a espécie de uma quadra ou equipamento urbano, de acordo com o cep ou id*/
void coord(Cidade listaCidade, FILE *txt, char *cid);

/*Procedimento que calcula  e retorna em um arquivo .txt as áreas e a área total das quadras contidas em um retângulo com ponto de âncora (x,y), largura w e altura h*/
void rectArea(Cidade listaCidade, FILE *txt, double x, double y, double w, double h);

#endif