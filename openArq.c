#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formaC.h"
#include "formaL.h"
#include "formaR.h"
#include "formaT.h"
#include "hidrante.h"
#include "quadra.h"
#include "radio.h"
#include "semaforo.h"
#include "lista.h"
#include "openArq.h"
#include "svg.h"
#include "qry.h"

void openGeo(Cidade listacidade, char *nomeGeo, char *saidaSvg)
{
    FILE *arq; 

    char comando[3];
    char cfillQ[20];
    char cstrkQ[20];
    char cstrkH[20];
    char cfillH[20];
    char cstrkR[20];
    char cfillR[20];
    char cstrkS[20];
    char cfillS[20];
    char corb[20];
    char corp[20];
    char text[50];
    char id[20];
    char cep[20];
    int id_forma;
    int i = 1000;
    int nq = 1000;
    int nh = 1000;
    int ns = 1000;
    int nr = 1000;
    int cont_i = 0;
    int cont_nq = 0;
    int cont_nh = 0;
    int cont_ns = 0;
    int cont_nr = 0;
    double r;
    double x;
    double y;
    double w;
    double h;
    char sw[10];
    char cw[10];
    char rw[10];

    tipo elemento;

    arq = fopen(nomeGeo, "r");

        if(arq == NULL){
            printf("Erro ao abrir o arquivo Geo!!");
            system("pause");
            exit(1);
        }


       while(fscanf(arq, "%s", comando) != EOF){
                if(strcmp(comando, "nx") == 0){
                    fscanf(arq, "%d %d %d %d %d\n", &i, &nq, &nh, &ns, &nr);
                }

                else if((strcmp(comando, "c") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %s %s", &id_forma, &r, &x, &y, corb, corp); 
                    elemento = criaCirculo(id_forma, r, x, y, corb, corp, cw);
                    insereElemento(getListaCirculos(listacidade), elemento);
                    cont_i += 1;
                }

                else if((strcmp(comando, "r") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %lf %s %s", &id_forma, &w, &h, &x, &y, corb, corp); 
                    elemento = criaRetangulo(id_forma, w, h, x, y, 0, 0, corb, corp, rw);
                    insereElemento(getListaRetangulos(listacidade), elemento);
                    cont_i += 1;
                }

                else if(strcmp(comando, "t") == 0){
                    fscanf(arq, "%d %lf %lf %s %s %s", &id_forma, &x, &y, corb, corp, text); 
                    elemento = criaTexto(id_forma, x, y, corb, corp, text);
                    insereElemento(getListaTexto(listacidade), elemento);
                }

                else if((strcmp(comando, "q") == 0) && cont_nq < nq){
                    fscanf(arq, "%s %lf %lf %lf %lf", cep, &x, &y ,&w ,&h);
                    elemento = criaQuadra(cep, x, y, w, h, cfillQ, cstrkQ, sw);
                    insereElemento(getListaQuadras(listacidade), elemento);
                    cont_nq += 1;
                }

                else if((strcmp(comando, "h") == 0) && cont_nh < nh){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaHidrante(id, x, y, cfillH, cstrkH, sw);
                    insereElemento(getListaHidrantes(listacidade), elemento);
                    cont_nh += 1;
                }

                else if((strcmp(comando, "s") == 0) && cont_ns < ns){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaSemaforo(id, x, y, cfillS, cstrkS, sw);
                    insereElemento(getListaSemaforos(listacidade), elemento);
                    cont_ns += 1;
                }

                else if((strcmp(comando, "rb") == 0) && cont_nr < nr){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaRadio(id, x, y, cfillR, cstrkR, sw);
                    insereElemento(getListaRadios(listacidade), elemento);
                    cont_nr += 1;
                }

                else if(strcmp(comando, "ch") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillH, cstrkH);
                }

                else if(strcmp(comando, "cr") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillR, cstrkR);
                }

                else if(strcmp(comando, "cs") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillS, cstrkS);
                }

                else if(strcmp(comando, "cq") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillQ, cstrkQ);
                }

                else if(strcmp(comando, "sw") == 0){
                    fscanf(arq, "%s %s", cw, rw);
                }
            } 
   fclose(arq);
svgen(listacidade, saidaSvg); 
}

void openQry(Cidade listacidade, char *entradaQry, char *saidaQry){

    FILE *entrada, *saidaTxt;

    char comando[6];
    char teste[20];
    char id[20];
    char cStrk[20];
    double r;
    double x;
    double y;
    double w;
    double h;

    char *saidaSvgQry = malloc(strlen(saidaQry)+5);
    char *saidaTxtQry = malloc(strlen(saidaQry)+5);

    sprintf(saidaTxtQry, "%s.txt", saidaQry);
    sprintf(saidaSvgQry, "%s.svg", saidaQry);

    entrada = fopen(entradaQry, "r");
    saidaTxt = fopen(saidaTxtQry, "w+");

    if(entrada == NULL){
            printf("Erro ao abrir o arquivo entrada!!");
            system("pause");
            exit(1);
        }

    if(saidaTxt == NULL){
            printf("Erro ao abrir o arquivo saidaTxtQry!!");
            system("pause");
            exit(1);
    }


        while(fscanf(entrada, "%s", comando)!=EOF){

            if(strcmp(comando, "dq") == 0){
                fscanf(entrada, "%s", teste);

                    if(strcmp(teste, "#") == 0){
                        fscanf(entrada, "%s %lf", id, &r);
                            delQuadras(listacidade, saidaTxt, 1, id, r);
                    }
                    else{
                        strcpy(id, teste);
                        fscanf(entrada, "%lf", &r);
                            delQuadras(listacidade, saidaTxt, 0, id, r);
                    }
            }

            else if(strcmp(comando, "del") == 0){
                fscanf(entrada, "%s", id);
                   delUrb(listacidade, saidaTxt, id);
            }

            else if(strcmp(comando, "cbq") == 0){
                fscanf(entrada, "%lf %lf %lf %s", &x, &y, &r, cStrk);
                    colorBorder(listacidade, saidaTxt, x, y, r, cStrk);
            }

            else if(strcmp(comando, "crd?") == 0){
                fscanf(entrada, "%s", id);
                    coord(listacidade, saidaTxt, id);
            }

            else if(strcmp(comando, "car") == 0){
                fscanf(entrada, "%lf %lf %lf %lf", &x, &y, &w, &h); 
                    rectArea(listacidade, saidaTxt, x, y, w, h);
            }
        
        }
        

    fclose(saidaTxt);
    fclose(entrada);
    svgen(listacidade, saidaSvgQry);
    free(saidaSvgQry);
    free(saidaTxtQry);
}

char *trataNome(char nome[]){
    char *aux = strrchr(nome, '/');
        if(aux == NULL){
            return strtok(nome, ".");
        }
    return strtok(&aux[1], ".");
}

void tratamento(char path[], char outPath[], char paramGeo[], char paramQry[]){
    char *geoArq = NULL;
    char *qryArq = NULL;
    char *nomeArq = NULL;
    char *nomeQry = NULL;
    char *saida = NULL;
    char *saidaGeo = NULL;
    char *saidaQry = NULL;
    if (path != NULL) {
        if(path[strlen(path) - 1] != '/'){
            geoArq = (char *)malloc((strlen(paramGeo)+strlen(path)+2)*sizeof(char));
    	    sprintf(geoArq,"%s/%s",path,paramGeo);
        }
		else{
            geoArq = (char *)malloc((strlen(paramGeo)+strlen(path)+1)*sizeof(char));
    	    sprintf(geoArq,"%s%s",path,paramGeo);
        }
        if (paramQry != NULL){
            qryArq = (char *)malloc((strlen(paramQry)+strlen(path)+2)*sizeof(char));
            sprintf(qryArq,"%s/%s",path,paramQry);
        }
	} else {
		geoArq = (char *)malloc((strlen(paramGeo)+1)*sizeof(char));
    	strcpy(geoArq, paramGeo);
        if(paramQry != NULL){
            qryArq = (char *)malloc((strlen(paramQry)+1)*sizeof(char));
            strcpy(qryArq, paramQry);
        }
	}
    nomeArq = trataNome(paramGeo);

    if (outPath[strlen(outPath) - 1] == '/'){
        saida = (char*)malloc((strlen(nomeArq) + strlen(outPath) + 1)*sizeof(char));
        sprintf(saida,"%s%s",outPath,nomeArq);
    }
    else{
        saida = (char*)malloc((strlen(nomeArq) + strlen(outPath) + 2)*sizeof(char));
        sprintf(saida,"%s/%s",outPath,nomeArq);
    }
    saidaGeo = (char*)malloc((strlen(saida) + 5)*sizeof(char));
    sprintf(saidaGeo,"%s.svg",saida);
    
    Cidade listaCidade = criaCidade();

    openGeo(listaCidade, geoArq,saidaGeo);

    if (paramQry != NULL){
        nomeQry = trataNome(paramQry);
        saidaQry = (char*)malloc((strlen(outPath) + strlen(saida) + 2)*sizeof(char));
        sprintf(saidaQry,"%s-%s",saida,nomeQry);
        openQry(listaCidade,qryArq,saidaQry);
        free(saidaQry);
        free(qryArq); 
    }
    free(geoArq);
    free(saida);
    free(saidaGeo);

    liberaLista(getListaCirculos(listaCidade));
    liberaLista(getListaRadios(listaCidade));
    liberaLista(getListaHidrantes(listaCidade));
    liberaLista(getListaQuadras(listaCidade));
    liberaLista(getListaSemaforos(listaCidade));
    liberaLista(getListaTexto(listaCidade));
    liberaLista(getListaLinhas(listaCidade));
    liberaLista(getListaRetangulos(listaCidade));

    free(listaCidade);
}