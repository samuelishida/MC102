#include <stdio.h>
/*
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 05a - Caça ao tesouro
*/

int main()
{
    struct{
        int dica;
        int visitado;/*marca se a dica ja foi visitada*/
    }mapa[101];/*indices de 1 a 100 para facilitar a manipulção*/

    int n, i;

    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        scanf("%d",&mapa[i].dica);
        mapa[i].visitado = 0;/*nenhum lugar foi visitado a principio*/
    }

    i=1;

    /*enquanto o tesouro nao for encontrado ou nao voltar a algum ponto já visitado*/
    while(mapa[i].dica != i && !mapa[i].visitado)
    {
        mapa[i].visitado = 1;/*o lugar da dica foi visitada*/
        i = mapa[i].dica;/*aponta para o próximo lugar*/
    }

    if(mapa[i].dica == i)
        printf("Tesouro existe em %d\n",i);
    else
        printf("Nao existe tesouro\n");

    return 0;
}
