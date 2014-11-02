/*********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio Fruit Crush Saga - Part III
**********************************************/

#include <stdio.h>
#include <stdbool.h>

#define MAX 50

/*remove as frutas e ajusta o tabuleiro*/
void remFrutas(char tab[][MAX+1], int x, int y, int linhas)
{
    int i;
    bool flag = true;

    /*percorre a coluna ate a segunda linha ou ate a linha anterior a um gelo*/
    for(i=x; i>0 && flag; i--)
    {
        if(tab[i-1][y] == '*')
        {
            tab[i][y] = '.';
            flag = false;/*termina o loop*/
        }

        else/*efeito gravidade*/
            tab[i][y] = tab[i-1][y];
    }

    /*se nao tiver achado um gelo, a primeira linha vira um ponto*/
    if(tab[0][y] != '*' && flag)
        tab[0][y] = '.';
}

/*funcao que realiza uma busca em profundidade recursiva procurando o char aux e incrementando o score*/
void colocaX(char tab[][MAX+1], char aux, int linhas, int colunas, int x, int y, int *score)
{
    *score = *score + 1;
    tab[x][y] = 'X';

    /*verifica se ha caracteres aux adjacentes nao visitados*/
    if(y+1 < colunas && tab[x][y+1] == aux)
        colocaX(tab,aux,linhas,colunas,x,y+1,score);

    if(y > 0 && tab[x][y-1] == aux)
        colocaX(tab,aux,linhas,colunas,x,y-1,score);

    if(x+1 < linhas && tab[x+1][y] == aux)
        colocaX(tab,aux,linhas,colunas,x+1,y,score);

    if(x > 0 && tab[x-1][y] == aux)
        colocaX(tab,aux,linhas,colunas,x-1,y,score);

    /*caso nao haja mais caracteres aux adjacentes nao vistados,
      acabe a funcao e retorne para a ultima chamada na pilha*/
    return;
}

int main()
{
    int m, n, i, j, x, y, sumScore=0, num, score;
    char tab[MAX][MAX+1], aux; /*MAX+1 devido do caracter '\0'*/

    /*******************************************
        m = numero de linhas;
        n = numero de colunas;
        i, j = contadoras;
        x, y = coordenadas da jogada;
        tab = matriz do tabuleiro;
        aux = auxiliar;
    ********************************************/

    /*le a entrada*/
    scanf("%d %d %d",&m,&n,&num);

    /*le o tabuleiro*/
    for(i=0;i<m;i++)
        scanf("%s",tab[i]);

    /*este loop le todas as jogadas e as executa*/
    while(num--)
    {
        score = 0;

        scanf("%d %d", &x, &y);/*le as jogadas*/

        x--;
        y--;

        aux = tab[x][y];/*salva o valor*/

        if(aux == '.' || aux == '*') continue;/*se tab[x][y] for um '.' ou um '*', (x,y) não é uma jogada válida*/

        /*colocaX() faz uma busca em profundidade recursiva e subsitui todas as frutas adjacentes entre si por 'X'*/
        colocaX(tab,aux,m,n,x,y,&score);

        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                if(tab[i][j] == 'X')
                    remFrutas(tab,i,j,m);/*remove os X e coloca os pontos*/

        sumScore += (score*score);/*soma a pontuação*/
    }

    /*imprime a saida*/

    printf("Score: %d\n",sumScore);/*imprime a pontuação final*/

    for(i=0;i<m;i++)
        printf("%s\n",tab[i]);

    /*fim da impressao*/


    /*fim do programa*/
    return 0;
}
