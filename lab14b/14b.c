/*********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 14b - Liber8
**********************************************/

#include <stdio.h>
#include <stdlib.h>


void limpa_memoria(char **mapa, int linhas);
void imprime_mapa(char **mapa, int linhas);
void le_mapa(char **mapa,int linhas);

/*funcao que converte um numero em char para int*/
int charToInt(char c)
{
    return c-'0';
}

/*funcao para desalocar o mapa*/
void limpa_memoria(char **mapa, int linhas)
{
    int i;

    for(i=0; i<linhas; i++)
        free(mapa[i]);

    free(mapa);
}

/*funcao para imprimir o mapa*/
void imprime_mapa(char **mapa, int linhas)
{
    int i;

    for(i=0; i<linhas; i++)
        printf("%s\n",mapa[i]);
}

/*funcao para fazer a leitura do mapa*/
void le_mapa(char **mapa,int linhas)
{
    int i;

    for(i=0; i<linhas; i++)
        scanf("%s",mapa[i]);
}

/*funcao que marca as explosoes no mapa*/
void explode(char **mapa, int x, int y, int raio, int linhas, int colunas)
{
    int i, j;

    mapa[x][y] = 'B';
	
	/*verifica o raio em volta da bomba atual e se achar outra bomba, chama a funcao de novo*/
    for(i = (x-raio>0)?(x-raio):(0); i<x+raio+1 && i < linhas; i++)
    {/*na atribuicao do i e do j, eh verificado se o a posicao menos o raio nao sai do mapa*/
        for(j = (y-raio>0)?(y-raio):(0); j<y+raio+1 && j < colunas; j++)
        {
			if(mapa[i][j] == '.')
                mapa[i][j] = 'x';/*marca a explosao*/
				
            else if(mapa[i][j] != 'B' && mapa[i][j] != 'x')/*se for outra bomba*/
                explode(mapa,i,j,charToInt(mapa[i][j]),linhas,colunas);/*marca as explosoes dessa bomba*/
        }
    }
}

int main()
{
    int linhas, colunas, x, y, i;
    char **mapa;

    scanf("%d %d %d %d",&linhas,&colunas,&x,&y);

    /*aloca o mapa*/
    mapa = malloc(linhas*sizeof(char*));

    for(i=0; i<linhas; i++)
        mapa[i] = malloc((colunas+1)*sizeof(char));
    /*fim da alocacao*/

    le_mapa(mapa, linhas);

    explode(mapa, x-1, y-1, charToInt(mapa[x-1][y-1]), linhas, colunas);

    imprime_mapa(mapa, linhas);

    limpa_memoria(mapa, linhas);

    /*fim do programa*/
    return 0;
}
