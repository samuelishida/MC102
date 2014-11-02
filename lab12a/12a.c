/***********************************************************
 * Autor: Leonardo Beretta Alvetti
 * RA: 156191
 * Laboratorio 12a: CUT++
 *
 ***********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMEARQ 101
#define TAM_MAX 501

/* Prototipo das funcoes utilizadas pela main */
void gera_csv_reduzido(char fnamein[], char fnameout[]);

int main(int argc, char *argv[]) {
    char fnamein[MAX_NOMEARQ], fnameout[MAX_NOMEARQ];

    strcpy(fnamein, argv[1]);
    strcpy(fnameout, argv[2]);

    gera_csv_reduzido(fnamein, fnameout);

    return 0;
}

void gera_csv_reduzido(char fnamein[], char fnameout[]) {
    FILE *arq_in, *arq_out;
    int *campos_pedidos, i, j;
    char **arquivo, c;
    int num_campos_pedidos, num_campos = 0, pos_imp, k;
    /* Le o numero de campos desejados */
    scanf("%d", &num_campos_pedidos);
    /* Aloca memoria para as posicoes do vetor campos */
    campos_pedidos = malloc(num_campos_pedidos * sizeof(int));

    /* Le quais campos quer que estejam no arquivo de saida */
    for(i = 0; i < num_campos_pedidos; i++)
        scanf(" %d", &campos_pedidos[i]);

    /* Abre os arquivos */
    arq_in = fopen(fnamein, "r");
    arq_out = fopen(fnameout, "w");


    if((arq_in != NULL) && (arq_out != NULL)) {
        /* Descobrindo numero de campos(colunas) */
        fscanf(arq_in, "%c", &c);
        while(c != '\n') {
            if(c == ',')
                num_campos++;
            fscanf(arq_in, "%c", &c);
        }

        /* ajusta o numero de campos */
        num_campos++;
        /* Aloca dinamicamente uma matriz que recebera o arquivo */
        arquivo = malloc(num_campos * sizeof(char *));
        for(i = 0; i < num_campos; i++)
            arquivo[i] = malloc(TAM_MAX * sizeof(char));
        rewind(arq_in);
        /* Le as linhas do arquivo e depois seleciona as desejadas */
        i = 0;
        j = 0;

        printf("%d\n",num_campos);

        c = fgetc(arq_in);

        while(c != EOF) {
                if(c == ',') {
                arquivo[i][j] = '\0';
                i++;
                j = 0;
            }

            /* Casso seja o m da linha, printa no arquivo de saida e vai
             * proximo registro*/
            else if(c == '\n') {
                /* Imprime o primeiro campo separadamente */
                arquivo[i][j] = '\0';
                pos_imp = campos_pedidos[0];
                fprintf(arq_out, "%s", arquivo[pos_imp -1]);
                printf("%s", arquivo[pos_imp - 1]);

                for(k = 1; k < num_campos_pedidos; k++) {
                    pos_imp = campos_pedidos[k];
                    fprintf(arq_out, ", %s", arquivo[pos_imp - 1]);
                }
                fprintf(arq_out,"\n");

                i = 0;
                j = 0;
            }

            else{
                arquivo[i][j] = c;
                j++;
            }


            c = fgetc(arq_in);
        }
    }

    /* fechou os arquivos? */
    fclose(arq_in);
    fclose(arq_out);
    /*Desaloca memoria*/
    free(campos_pedidos);
    for(i = 0; i < num_campos; i++)
        free(arquivo[i]);
    free(arquivo);
}
