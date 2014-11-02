#include <stdio.h>

/**********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 08a - Amigos dos amigos
************************************************/

#define MAX 100
#define TRUE 1
#define FALSE 0

int main()
{
    int i, j, numU, u, matriz[MAX][MAX], sugestao[MAX]={FALSE};

    /*******************************************************
        i, j = auxiliares
        numU = numero de usuarios
        u = usuario
        matriz = matriz de entrada
        sugestao = vetor que guarda os amigos sugeridos
    ********************************************************/

    /*leitura da entrada*/

    scanf("%d %d", &numU, &u);

    for(i=0; i<numU; i++)
        for(j=0; j<numU; j++)
            scanf("%d",&matriz[i][j]);

    /*fim da leitura*/

    for(i=0; i<numU; i++)
        if(!matriz[i][u])/*se nao sao amigos*/
            for(j=0; j<numU; j++)
                if(matriz[u][j] && matriz[i][j])/*se há pelo menos um amigo em comum*/
                {
                    sugestao[i] = TRUE;/*o usuario é uma sugestao de amigo*/
                    break;/*não é necessario continuar verificando*/
                }

    for(i=0; i<numU; i++)/*verifica se houve sugestoes*/
        if(sugestao[i])
            break;

    /*saida final*/

    if(i == numU){/*se todo o vetor sugestao é falso*/
        printf("Sem sugestao de novos amigos");
    }
    else{
        printf("Sugestao de amigos:");
        for(i=0; i<numU; i++)
            if(sugestao[i])/*se o usuario i for sugestao, imprima i*/
                printf(" %d",i);
    }

    printf("\n");

    /*fim da saida*/

    /*fim do programa*/

    return 0;
}

