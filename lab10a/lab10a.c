/**********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 10a - LSCrypto
************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct alfabeto{
    char letra;
    int num;
};/*registro para contagem dos caracteres*/

typedef struct alfabeto alfabeto;

/*verifica se a letra é minuscula*/
int letraMin(char in)
{
    if ( in >= 'a' && in <= 'z' )
        return 1;

    return 0;
}

/*verifica se a letra é maiscula*/
int letraMai(char in)
{
    if ( in >= 'A' && in <= 'Z' )
        return 1;

    return 0;
}

/*função de comparacao para o qsort()*/
int compareNum(const void *p1, const void *p2)
{
    const alfabeto *a = p1;
    const alfabeto *b = p2;

    if(a->num < b->num) return 1;/*b antes de a*/
    else if(a->num == b->num)
    {
        if( a->letra < b->letra )
            return -1;/*a antes de b*/
        else if(a->letra > b->letra)
            return 1;
        else
            return 0;
    }

    return -1;/*a antes de b*/
}

/*função para buscar o indice no vetor cont dado o numero de contagem dele*/
int buscaNum(alfabeto *search, alfabeto *in)
{
    int i;

    for(i=0; i<26; i++)
        if(search[i].num == in->num && search[i].letra == in->letra)/*se achou o elemento*/
            return i;/*retorna o indice*/

    return -1;
}


int main()
{
    alfabeto cont[26], search[26];
    int i, j, n, aux;
    char texto[15][502], in;/*500 caracteres + '\n' + '\0'*/

    scanf("%d",&n);

    for(i=0; i<26; i++)
    {
        cont[i].letra = search[i].letra = i+'A';
        cont[i].num = search[i].num = 0;
    }

    fflush(stdin);/*limpa o buffer*/

    /*entrada do texto*/

    for(i=0; i<n; i++)
    {
        for(j=0; j<500 && in != '\n'; j++)
        {
            in = fgetc(stdin);

            /*faz a contagem dos caracteres*/
            if( letraMin(in) )
            {
                cont[(int)(in-'a')].num++;
                search[(int)(in-'a')].num++;
            }
            else if( letraMai(in) )
            {
                cont[(int)(in-'A')].num++;
                search[(int)(in-'A')].num++;
            }

            texto[i][j] = in;
        }

        texto[i][j] = '\0';/*coloca o caracter null no final da linha para indicar o fim */
        in = '\0';/*in com '\n' para o for*/
    }

    /*fim da entrada*/

    qsort(cont,26,sizeof(alfabeto),compareNum);/*ordena*/

    for(i=0; i<n; i++)
    {
        for(j=0; texto[i][j] != '\0'; j++)
        {
            in = texto[i][j];

            if( letraMin(in) )
            {
                aux = buscaNum(cont,&search[(int)(in-'a')]);

                if(aux%2)/*se for impar*/
                    texto[i][j] = cont[ (aux-1)%26 ].letra;/*copia o de tras*/
                else
                    texto[i][j] = cont[ (aux+1)%26 ].letra;/*copia o da frente*/

                texto[i][j] += ('a' - 'A');/*muda pra minuscula*/
            }

            else if( letraMai(in) )
            {
                aux = buscaNum(cont,&search[(int)(in-'A')]);
                if(aux%2)/*se for impar*/
                    texto[i][j] = cont[ (aux-1)%26 ].letra;/*copia o de tras*/
                else
                    texto[i][j] = cont[ (aux+1)%26 ].letra;/*copia o da frente*/
            }
        }
    }

    for(i=0; i<n; i++)
        printf("%s",texto[i]);

    /*fim do programa*/

    printf("\n");

    return 0;
}
