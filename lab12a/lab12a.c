/***********************************************************
 * Autor: Samuel Toyoshi Ishida
 * RA: 160250
 * Laboratorio 12a: CUT++
 *
 ***********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMEARQ 101
#define MAX_CAMPO 501

typedef char* string;

/* Prototipo das funcoes utilizadas pela main */
void gera_csv_reduzido(char fnamein[], char fnameout[]);

void gera_csv_reduzido(char fnamein[], char fnameout[])
{
    FILE *in, *out;
    char campo[MAX_CAMPO], c;
    int contChar, contCol=0, i, *vet, n, j;
    string *linha;


    /*lendo os arquivos*/
    in = fopen(fnamein,"r");
    out = fopen(fnameout,"w");



    /*leitura da entrada padrao*/
    scanf("%d",&n);

    /*alocao do vet*/
    vet = malloc(n*sizeof(int));

    for(i=0; i<n; i++)
        scanf("%d",&vet[i]);
    /*fim da leitura*/



    linha = malloc((sizeof(string)));
    contChar = 0;

    /*le a primeira linha do in char por char*/
    while(c != '\n')
    {
        /*le o caracter do arquivo in*/
        c = fgetc(in);

        /*o ultimo campo nao tem virgula, mas um '\n', por isso a condicao extra*/
        if(c != ',' && c != '\n')
        {
            campo[contChar] = c;
            contChar++;
        }
        else
        {
            /*realoca a linha aumentando seu tamanho devido ao aumento de colunas*/
            linha = realloc(linha,(sizeof(string)*(contCol+1)));

            /*aloca o vetor de char*/
            linha[contCol] = malloc(sizeof(char)*(contChar+2));

            /*indica o final da string com NULL*/
            campo[contChar] = '\0';

            /*copia a string campo para linha[contCol]*/
            strcpy(linha[contCol],campo);

            /*ajusta os valores*/
            contCol++;
            contChar = 0;
        }

    }
    /*fim da leitura*/

    /*imprime saida da primeira linha*/
    for(i=0; i<n-1; i++)
        fprintf(out,"%s,",linha[vet[i]-1]);

    fprintf(out,"%s\n",linha[vet[i]-1]);
    /*fim da saida*/


    /*desaloca memoria*/
    for(i=0; i<contCol; i++)
        free(linha[i]);

    free(linha);
    /*fim da desalocacao*/



    /*realoca a linha*/
    linha = malloc(contCol*sizeof(string));

    for(i=0; i<contCol; i++)
        linha[i] = malloc(MAX_CAMPO*sizeof(char));
    /*fim da realocacao*/




    /*faz uma primeira leitura do c*/
    c = fgetc(in);

    /*inicia as contadoras*/
    i=0;
    j=0;

    /*le char por char a linha e seleciona o que sera impresso no out*/
    while(c != EOF)/*equanto o arquivo nao acabar*/
    {
        if(c == ',')/*se for uma virgula*/
        {
            linha[i][j] = '\0';/*fim da string*/
            i++;/*proxima coluna*/
            j=0;/*reseta a string*/
        }
        else if(c == '\n')/*se for um '\n'*/
        {
            linha[i][j] = '\0';/*fim da string*/

            /*imprime saida da n-esima linha*/
            for(j=0; j<n-1; j++)
                fprintf(out,"%s,",linha[vet[j]-1]);

            fprintf(out,"%s\n",linha[vet[j]-1]);
            /*fim da saida*/

            /*nova linha*/
            j=0;
            i=0;
        }
        else/*caso for um caracter qualquer*/
            linha[i][j++] = c;/*atribua a string e passe para o proximo caracter*/

        /*le o proximo caracter*/
        c = fgetc(in);
    }



    /*desaloca memoria*/
    for(i=0; i<contCol; i++)
        free(linha[i]);

    free(linha);
    /*fim da desalocacao*/



    /*fecha arquivos*/
    fclose(in);
    fclose(out);
}


int main(int argc, char *argv[]) {
    char fnamein[MAX_NOMEARQ], fnameout[MAX_NOMEARQ];

    /*lendo os argumentos*/
    strcpy(fnamein, argv[1]);
    strcpy(fnameout, argv[2]);

    gera_csv_reduzido(fnamein, fnameout);

    /*fim do programa*/
    return 0;
}

