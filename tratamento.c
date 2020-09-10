#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tratamentoGeo(char *arquivoGeo, char *nomeArquivoGeo, char *caminhoGeo, char *diretorio){

        nomeArquivoGeo = (char*)malloc( ( ( strlen(arquivoGeo) )+1 )*sizeof(char) );
        strcpy(nomeArquivoGeo, arquivoGeo);
        nomeArquivoGeo = strtok(nomeArquivoGeo, "."); /*vai retornar somente o nome anterior ao .geo*/ 

        if (diretorio != NULL){/*Se foi passado um argumento de diretório*/
            caminhoGeo = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoGeo) )+3 )* sizeof(char) );
            sprintf(caminhoGeo, "%s/%s", diretorio, arquivoGeo); 
        }
        else{/*Não foram passados argumentos para o diretório*/
            caminhoGeo =  (char*)malloc( ( (strlen(arquivoGeo) )+1 )* sizeof(char) );
            strcpy(caminhoGeo, arquivoGeo);
            /*printf("\n\ncaminho Geo sem argumento de diretorio: %s", caminhoGeo);*/
        }
}

void tratamentoQry(char *arquivoQry, char *nomeArquivoQry, char *caminhoQry, char *diretorio){

    if (diretorio != NULL){/*Se foi passado um argumento de diretório*/
        if(arquivoQry !=  NULL){/*se foi passado um arquivo de qry*/
            caminhoQry = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoQry) )+3 )* sizeof(char) );
            sprintf(caminhoQry, "%s/%s", diretorio, arquivoQry);
            /*printf("\n\ncaminho Qry com argumento de diretorio: %s", caminhoQry);*/
        }
    }
    else{/*Não foram passados argumentos para o diretório*/
        if(arquivoQry != NULL){/*se foi passado um arquivo de qry*/
            caminhoQry = (char*)malloc( ( (strlen(arquivoQry) )+1 )* sizeof(char) );
            strcpy(caminhoQry, arquivoQry);
            /*printf("\n\ncaminho Qry sem argumento de diretorio: %s", caminhoQry);*/
            }
    }

    if (arquivoQry != NULL){
                 char *tratamento = NULL;   
                    nomeArquivoQry = (char*)malloc( ( ( strlen(arquivoQry) )+1 )*sizeof(char) );
                    tratamento = (char*)malloc( ( ( strlen(arquivoQry) )+1 )*sizeof(char) );
                    strcpy(tratamento, arquivoQry);
                    printf("\n%s", tratamento);
                    strcpy(tratamento, strrchr(arquivoQry, '/') ); /*vai retornar o nome após '/' */ 
                    printf("\n%s", tratamento);
                    strcpy(nomeArquivoQry, strtok(tratamento, "/") ); /*vai retornar o que vem antes da '/' */
                    /*printf("\n\nnome Qry formatado: %s", nomeArquivoQry);*/
    }
}