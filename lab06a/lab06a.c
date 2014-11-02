#include <stdio.h>

/*********************************************

    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio Fruit Crush Saga - Part I

**********************************************/

int main()
{
    int m, n, i, j, x, y, score;
    char tab[52][52], aux;

    /*******************************************
    m = numero de linhas;
    n = numero de colunas;
    i, j = contadoras;
    x, y = coordenadas da jogada;
    tab = matriz do tabuleiro;
    aux = auxiliar;
    ********************************************/

    scanf("%d %d %d %d",&m,&n,&x,&y);/*le a entrada*/

    getc(stdin);/*tira o '\n' do buffer*/

    for(i=0;i<m;i++)
        fgets(tab[i],n+2,stdin);/*n+2 para o '\n' e para o '\0'*/

    x--;
    y--;

    aux = tab[x][y];/*salva o valor*/
    tab[x][y] = 'X';

    score = 1;/*pelo menos a posição que ele jogou muda*/


    /*cada for verifica as posições adjacentes (um pra cada direção)
      sendo que ele para o loop quando a posião for != de aux e em cada
      iteração ele troca o valor na matriz por 'X' e incrementa score*/
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

    for(i=x+1; i<m; i++){
        if(tab[i][y] != aux) break;
        tab[i][y] = 'X';
        score++;
    }

    for(i=x-1; i>=0; i--){
        if(tab[i][y] != aux) break;
        tab[i][y] = 'X';
        score++;
    }

    score *= score;/*eleva ao quadrado*/

    printf("Score: %d\n",score);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%c",tab[i][j]);/*imprime a saida*/
        }
        printf("\n");/*pula a linha*/
    }

    /*fim do programa*/
    return 0;
}
