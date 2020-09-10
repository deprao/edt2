#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formaC.h"
#include "formaL.h"
#include "formaR.h"
#include "formaT.h"
#include "hidrante.h"
#include "lista.h"
#include "quadra.h"
#include "radio.h"
#include "semaforo.h"
#include "openArq.h"

int main (int argc, char *argv[]){

    char *arquivoGeo = NULL; /*nome do arquivo .geo*/
    char *arquivoQry = NULL; /*nome do arquivo .qry*/
    char *diretorio = NULL; /*diretorio do arquivo .geo e .qry*/
    char *pastaSaida = NULL; /*nome do arquivo de saida*/

    for (int i = 0; i<argc; i++){ /* Função para captar os caracteres do terminal */
          if ( strcmp(argv[i], "-e") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos em -e");
                    exit(1);
                }
                diretorio = (char*)malloc( ( ( strlen (argv[i]) )+1 )*sizeof(char) );
                strcpy(diretorio, argv[i]);
            }

            else if ( strcmp(argv[i], "-f") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -f");
                    exit(1);
                }
                arquivoGeo = (char*)malloc( ( ( strlen (argv[i]) )+1)*sizeof(char) );
                strcpy(arquivoGeo, argv[i]);
            }

            else if ( strcmp(argv[i], "-q") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -q");
                    exit(1);
                }
                arquivoQry = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(arquivoQry, argv[i]);
            }

            else if ( strcmp(argv[i], "-o") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -o");
                    exit(1);
                }
                pastaSaida = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(pastaSaida, argv[i]);
            }
    }

    tratamento(diretorio, pastaSaida, arquivoGeo, arquivoQry);

    free(arquivoGeo);
    free(arquivoQry);
    free(diretorio);
    free(pastaSaida);
}