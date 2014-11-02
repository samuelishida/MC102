#include <stdio.h>

/*********************************************

    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio Fruit Crush Saga - Part II

**********************************************/

#define MAX 52

/*remove as frutas e ajusta o tabuleiro*/
void remFrutas(char tab[][MAX], int x, int y)
{
    int i;

    for(i=x; i>=1; i--)
        tab[i][y] = tab[i-1][y];
}

int colocaX(char tab[][MAX], char aux, int m, int n, int x, int y)
{
    int i, score;

    tab[x][y] = 'X';

    score = 1;/*pelo menos a posi��o que ele jogou muda*/

    /*cada for verifica as posi��es adjacentes (um pra cada dire��o)
    sendo que ele para o loop quando a posi�o for != de aux e em cada
    itera��o ele troca o valor na matriz por 'X' e incrementa score*/
    for(i=y+1; i<n; i++){
        if(tab[x][i] != aux) break;
        tab[x][i] = 'X';
        score++;
    }

    for(i=y-1; i>=0; i--){
        if(tab[x][i] != aux) break;
        tab[x][i] = 'X';
        score++;
    }

    for(i=x+1; i<=m; i++){
        if(tab[i][y] != aux) break;
        tab[i][y] = 'X';
        score++;
    }

    for(i=x-1; i>=0; i--){
        if(tab[i][y] != aux) break;
        tab[i][y] = 'X';
        score++;
    }

    return score;
}

/*fun��o principal*/
int main()
{
    int m, n, i, j, x, y, score, sumScore=0, num;
    char tab[MAX][MAX], aux;

    /*******************************************
        m = numero de linhas;
        n = numero de colunas;
        i, j = contadoras;
        x, y = coordenadas da jogada;
        tab = matriz do tabuleiro;
        aux = auxiliar;
    ********************************************/

    scanf("%d %d %d",&m,&n,&num);/*le a entrada*/

    /*coloca '.' na primeira linha da matriz para facilitar na substitui��o,
     pois s� � necess�rio copiar o valor da linha de cima na hora de colocar os
     pontos no tabuleiro*/
    for(i=0; i<n; i++)
        tab[0][i] = '.';

    getc(stdin);/*tira o '\n' do buffer*/

    for(i=1;i<=m;i++)
        fgets(tab[i],n+2,stdin);/*n+2 para o '\n' e para o '\0'*/

    /*le todas as jogadas e as executa*/
    while(num--)
    {
        scanf("%d %d", &x, &y);/*le as jogadas*/

        y--;

        aux = tab[x][y];/*salva o valor*/

        if(aux == '.') continue;/*se for um ponto n�o � uma jogada v�lida*/

        /*colocaX coloca os X nas frutas adjacentes e retorna a pontua��o*/
        score = colocaX(tab,aux,m,n,x,y);

        for(i=1; i<=m; i++)
            for(j=0; j<n; j++)
                if(tab[i][j] == 'X')
                    remFrutas(tab,i,j);/*remove os X e coloca os pontos*/

        score *= score;

        sumScore += score;/*soma a pontua��o*/
    }

    printf("Score: %d\n",sumScore);/*imprime a pontua��o final*/

    for(i=1;i<=m;i++){
        for(j=0;j<n;j++){
            printf("%c",tab[i][j]);/*imprime a saida*/
        }
        printf("\n");/*pula a linha*/
    }

    /*fim do programa*/
    return 0;
}
