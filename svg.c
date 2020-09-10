#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include"formaC.h"
#include"formaR.h"
#include"formaT.h"
#include"formaL.h"
#include"quadra.h"
#include"radio.h"
#include"semaforo.h"
#include"hidrante.h"

void desenhaSemaforo(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double w, h;
    w =  8;
    h =  20;
    fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n"
    , x, y, w, h, cfill, cstrk, sw );
}

void desenhaRadio(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double r;
    r = 6;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, cfill, cstrk, sw);
}

void desenhaQuadra(FILE *saida, double x, double y, double w, double h, char *cfill, char *cstrk, char *sw){
    fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n"
    , x, y, w, h, cfill, cstrk, sw );
}

void desenhaHidrante(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double r;
    r = 6;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, cfill, cstrk, sw);
}

void desenhaTexto(FILE *saida, double x, double y, char *corb, char *corp, char *text){
    fprintf(saida, "<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\">%s</text>\n",
     x, y, corb, corp, text);
}

void desenhaRetangulo(FILE *saida, double x, double y, double w, double h, double rx, double ry, char *corp, char *corb, char *rw){
     fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" rx=\"%lf\" ry=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\"/>\n",
     x, y, w, h, rx, ry, corb, corp, rw);
}

void desenhaLinha(FILE *saida, double x1, double x2, double y1, double y2, char *corb){
    fprintf(saida, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" />\n",
      x1, y1, x2, y2, corb);
}

void desenhaCirculo(FILE *saida, double x, double y, double r, char *corp, char *corb, char *cw){
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\"  fill=\"%s\" stroke-width=\"%s\" />\n",
    x, y, r, corb, corp, cw);
}

void svgen(Cidade listaCidade,char *out){
    FILE *svg;
    Node listQ = getListaQuadras(listaCidade), listS = getListaSemaforos(listaCidade);
    Node listRb = getListaRadios(listaCidade), listH = getListaHidrantes(listaCidade);
    Node listC =  getListaCirculos(listaCidade), listR = getListaRetangulos(listaCidade);
    Node listT = getListaTexto(listaCidade), listL = getListaLinhas(listaCidade);

    Node Q = getFirst(listQ), S = getFirst(listS), Rb = getFirst(listRb), H = getFirst(listH);
    Node C = getFirst(listC), R = getFirst(listR), T = getFirst(listT), L = getFirst(listL);

    tipo q, s, rb, h, c, r, t, l;

    svg = fopen(out,"w");
    if(svg==NULL){
        perror("nao foi possivel operar arquivo svg");
        exit(1);
    }

    fprintf(svg,"<svg>\n");
    while(Q!=NULL){
        q = getElemento(Q);
        desenhaQuadra(svg,getQuadraX(q),getQuadraY(q),getQuadraW(q),getQuadraH(q),getQuadraCFill(q),getQuadraCStroke(q),getQuadraSw(q));
        Q = getNext(Q);
    }
    while(S!=NULL){
        s = getElemento(S);
        desenhaSemaforo(svg,getSemaforoX(s),getSemaforoY(s),getSemaforoCFill(s),getSemaforoCStroke(s),getSemaforoSw(s));
        S = getNext(S);
    }
    while(Rb!=NULL){
        rb = getElemento(Rb);
        desenhaRadio(svg,getRadioX(rb),getRadioY(rb),getRadioCFill(rb),getRadioCStroke(rb),getRadioSw(rb));
        Rb = getNext(Rb);
    }
    while(H!=NULL){
        h = getElemento(H);
        desenhaHidrante(svg,getHidranteX(h),getHidranteY(h),getHidranteCFill(h),getHidranteCStroke(h),getHidranteSw(h));
        H = getNext(H);
    }
    while(C!=NULL){
        c = getElemento(C);
        desenhaCirculo(svg,getCirculoX(c),getCirculoY(c),getCirculoR(c),getCirculoCorp(c),getCirculoCorb(c),getCirculoSw(c));
        C = getNext(C);
    }
    while(R!=NULL){
        r = getElemento(R);
        desenhaRetangulo(svg,getRetanguloX(r),getRetanguloY(r),getRetanguloW(r),getRetanguloH(r),getRetanguloRX(r),getRetanguloRY(r),getRetanguloCorp(r),getRetanguloCorb(r),getRetanguloSw(r));
        R = getNext(R);
    }
    while(T!=NULL){
        t = getElemento(T);
        desenhaTexto(svg,getTextoX(t),getTextoY(t),getTextoCorb(t),getTextoCorp(t),getTextoText(t));
        T = getNext(T);
    }
    while(L!=NULL){
        l = getElemento(L);
        desenhaLinha(svg,getLinhaX(l),getLinhaX2(l),getLinhaY(l),getLinhaY2(l),getLinhaCor(l));
        L = getNext(L);
    }
    fprintf(svg,"\n<svg>");
    fclose(svg);
}