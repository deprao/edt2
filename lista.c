#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "formaC.h"
#include "formaL.h"
#include "formaR.h"
#include "formaT.h"
#include "hidrante.h"
#include "quadra.h"
#include "radio.h"
#include "semaforo.h"

typedef struct no{
    void *elemento;
    struct no *ant;
    struct no *prox;
}No;

typedef struct lista{
    No *primeiro;
    No *ultimo;
}Lista;

typedef struct listacidade{
    listaStruct listaQuadras;
    listaStruct listaRadios;
    listaStruct listaSemaforos;
    listaStruct listaHidrantes;
    listaStruct listaCirculos;
    listaStruct listaLinhas;
    listaStruct listaRetangulos;
    listaStruct listaTexto;
}listaCidade;

listaStruct criaLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}

Cidade criaCidade(){
    listaCidade *lista;
    lista = (listaCidade*)malloc(sizeof(listaCidade));

    lista->listaQuadras = criaLista();
    lista->listaRadios = criaLista();
    lista->listaSemaforos = criaLista();
    lista->listaHidrantes = criaLista();
    lista->listaCirculos = criaLista();
    lista->listaLinhas = criaLista();
    lista->listaRetangulos = criaLista();
    lista->listaTexto = criaLista();

    return lista;
}

Cidade getListaQuadras(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaQuadras;
}

Cidade getListaRadios(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaRadios;
}

Cidade getListaSemaforos(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaSemaforos;
}

Cidade getListaHidrantes(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaHidrantes;
}

Cidade getListaCirculos(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaCirculos;
}

Cidade getListaLinhas(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaLinhas;
}

Cidade getListaRetangulos(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaRetangulos;
}

Cidade getListaTexto(Cidade lista){
    listaCidade *list = (listaCidade*)lista;
    return list->listaTexto;
}

listaStruct insereElemento(listaStruct lista, tipo elemento){
    Lista *list = (Lista*)lista;
    
    No* node = (No*)malloc(sizeof(No));
    node->elemento = elemento;
        if(list->primeiro == NULL){ /*se a lista esta vazia*/
            node->ant = NULL; /*o anterior aponta para null*/
            list->primeiro = node; /*o primeiro elemento da lista é node*/
        }
        else{ /*senao*/
            list->ultimo->prox = node; /*o prox do ultimo elemento adicionado aponta para o novo node*/
            node->ant = list->ultimo; /*o ponteiro de anterior aponta pro ultimo elemento adicionado*/
        }

        node->prox = NULL;
        list->ultimo = node;
    return list; 
}

listaStruct insertBefore(listaStruct lista, tipo elemento, tipo elemento_2){
    Lista *list = (Lista*)lista;

    No* node = (No*)malloc(sizeof(No));
    node->elemento = elemento;

    No* inicio = list->primeiro;
    No *aux_1;
    No *aux_2;

        while (inicio != NULL){
                    if(inicio == elemento_2){
                            if(inicio == list->primeiro){
                                aux_1 = inicio;
                                aux_1->ant = node;
                                node->prox = aux_1;
                                node->ant = NULL;
                                list->primeiro = node;
                                return list; 
                            }
                        else if(inicio!= list->primeiro){
                                aux_1 = inicio;
                                aux_2 = inicio->ant;
                                node->ant = aux_2;
                                node->prox = aux_1;
                                aux_1->ant = node;
                                aux_2->prox = node;
                                return list; 
                        }
                    }
                    inicio = inicio->prox;
        }
    return NULL;
}

listaStruct insertAfter(listaStruct lista, tipo elemento, tipo elemento_2){
     Lista *list = (listaStruct)lista;
    
         No* node = (No*)malloc(sizeof(No));
         node->elemento = elemento;
         
         No *inicio = list->primeiro;
         No *aux_1; 
         No *aux_2;
            while(inicio != NULL){
                if(inicio == elemento_2){
                        if(inicio == list->ultimo){
                            aux_1 = inicio;
                            aux_1->prox = node;
                            node->prox = NULL;
                            node->ant = aux_1;
                            list->ultimo = node;
                            return list; 
                        }
                        else if(inicio!= list->ultimo){
                            aux_1 = inicio;
                            aux_2 = inicio->prox;
                            aux_1->prox = node;
                            aux_2->ant = node;
                            node->ant = aux_1;
                            node->prox = aux_2;
                            return list; 
                        }
                }
                inicio = inicio->prox;
            }
    return NULL;
}

void removeElemento(listaStruct l, tipo elemento){
    Lista* lista = (Lista*) l;
    No *aux, *aux2;
    aux = lista->primeiro;
    
    while (aux!=NULL){
        if(aux->elemento == elemento){
            if (aux==lista->primeiro){
                lista->primeiro = aux->prox;
                lista->primeiro->ant = NULL;
            }
            if(aux==lista->ultimo){
                lista->ultimo = aux->ant;
                lista->ultimo->prox = NULL;
            }

            aux2 = aux->prox;
            aux2->ant = aux->ant;

            if(aux->ant!=NULL){
                aux->ant->prox = aux2;
            }
            
            free(aux->elemento);
            free(aux);
            break;
         }
        aux = aux->prox;
    }  
}

void liberaLista(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->primeiro;
    No *aux;
        while(node != NULL){
            aux = node->prox;
                free(node->elemento);
                free(node);
            node = aux;
        }
    free(lista);
}


Node getFirst(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->primeiro;
        if(list->primeiro == NULL){
            return NULL;
        }
        
    return node;
}

Node getLast(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->ultimo;
        if(list->ultimo == NULL){
            return NULL;
        }
        
    return node;
}

Node getPrevious(Node elemento){
    No* node = (No*)elemento;

    return node->ant;
}

Node getNext(Node elemento){
    No* node = (No*)elemento;

    return node->prox;
}

tipo getElemento(Node elemento){
    No *node = (No*)elemento;

    return node->elemento; 
}

void imprimeLista(listaStruct l, char c){
    Lista *list = (Lista*)l;
    No *node = list->primeiro;
        while(node != NULL){
            if(c == 'r'){
                printf("%s, %lf, %lf, %s, %s\n", getRadioId(getElemento(node)), getRadioX(getElemento(node)), getRadioY(getElemento(node)), getRadioCFill(getElemento(node)), getRadioCStroke(getElemento(node)));
            }
            else if(c == 'h'){
                printf("%s, %lf, %lf, %s, %s\n", getHidranteId(getElemento(node)), getHidranteX(getElemento(node)), getHidranteY(getElemento(node)), getHidranteCFill(getElemento(node)), getHidranteCStroke(getElemento(node)));
            }
            else if(c == 'q'){
                printf("%s, %lf, %lf, %lf, %lf,%s, %s\n", getQuadraCep(getElemento(node)), getQuadraX(getElemento(node)), getQuadraY(getElemento(node)),  getQuadraW(getElemento(node)),  getQuadraH(getElemento(node)), getQuadraCFill(getElemento(node)), getQuadraCStroke(getElemento(node)));
            }
            else if(c == 's'){
                printf("%s, %lf, %lf, %s, %s\n", getSemaforoId(getElemento(node)), getSemaforoX(getElemento(node)), getSemaforoY(getElemento(node)), getSemaforoCFill(getElemento(node)), getSemaforoCStroke(getElemento(node)));
            }
            else if(c == 'c'){
                printf("%d, %lf, %lf, %lf, %s, %s\n", getCirculoId(getElemento(node)), getCirculoR(getElemento(node)), getCirculoX(getElemento(node)), getCirculoY(getElemento(node)), getCirculoCorb(getElemento(node)), getCirculoCorp(getElemento(node)));
            }
            else if(c == 'a'){
                printf("%d, %lf, %lf, %lf, %lf, %s, %s\n", getRetanguloId(getElemento(node)), getRetanguloW(getElemento(node)), getRetanguloH(getElemento(node)), getRetanguloX(getElemento(node)), getRetanguloY(getElemento(node)), getRetanguloCorb(getElemento(node)), getRetanguloCorp(getElemento(node)));
            }
            else if(c == 't'){
                printf("%d, %lf, %lf, %s, %s, %s\n", getTextoId(getElemento(node)), getTextoX(getElemento(node)), getTextoY(getElemento(node)), getTextoCorb(getElemento(node)), getTextoCorp(getElemento(node)), getTextoText(getElemento(node)));
            }
            node = node->prox;
        }
}

int tamanhoLista(listaStruct lista){
 Lista *list = (Lista*)lista;
 int tamanho = 0;
    No *node = list->primeiro;
        while(node != NULL){
            tamanho += 1;
            node = node->prox;
        }
    return tamanho;
}

Node comparaIdH(Cidade listacidade, char *id){
    listaStruct listH = getListaHidrantes(listacidade);
    Node no = getFirst(listH);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getHidranteId(elemento), id) == 0){
                    return elemento;
                }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}

Node comparaIdQ(Cidade listacidade, char *id){
    listaStruct listQ = getListaQuadras(listacidade);
    Node no = getFirst(listQ);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getQuadraCep(elemento), id) == 0){
                    return elemento;
                }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}

Node comparaIdR(Cidade listacidade, char *id){
    listaStruct listR = getListaRadios(listacidade);
    Node no = getFirst(listR);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getRadioId(elemento), id) == 0){
                    return elemento;
            }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}

Node comparaIdS(Cidade listacidade, char *id){
    listaStruct listS = getListaSemaforos(listacidade);
    Node no = getFirst(listS);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getSemaforoId(elemento), id) == 0){
                    return elemento;
                }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}