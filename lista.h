#ifndef LISTA_H_
#define LISTA_H_

typedef void *Cidade;

typedef void *listaStruct;

typedef void *tipo;

typedef void *Node;

listaStruct criaLista();

Cidade criaCidade();

Cidade getListaQuadras(Cidade lista);

Cidade getListaRadios(Cidade lista);

Cidade getListaSemaforos(Cidade lista);

Cidade getListaHidrantes(Cidade lista);

Cidade getListaCirculos(Cidade lista);

Cidade getListaLinhas(Cidade lista);

Cidade getListaRetangulos(Cidade lista);

Cidade getListaTexto(Cidade lista);

listaStruct insereElemento(listaStruct lista, tipo elemento);

listaStruct insertBefore(listaStruct lista, tipo elemento, tipo elemento_2);

listaStruct insertAfter(listaStruct lista, tipo elemento, tipo elemento_2);

void removeElemento(listaStruct lista, tipo elemento);

void liberaLista(listaStruct lista);

Node getFirst(listaStruct lista);

Node getLast(listaStruct lista);

Node getPrevious(Node elemento);

Node getNext(Node elemento);

tipo getElemento(Node elemento);

void imprimeLista(listaStruct l, char c);

Node comparaIdH(Cidade listacidade, char *id);

Node comparaIdQ(Cidade listacidade, char *id);

Node comparaIdR(Cidade listacidade, char *id);

Node comparaIdS(Cidade listacidade, char *id);

#endif