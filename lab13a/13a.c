/***************************************
*   Nome: Samuel Toyoshi Ishida
*   RA: 160250
*   Turma: T
*   Laboratorio 13a - JMob
***************************************/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

/*registro usado para leitura das linhas*/
struct Mobile{
    int Pe;
    int De;
    int Pd;
    int Dd;
};

typedef struct Mobile mobile;
typedef char bool;

/*  retorna o peso da barra, e calcula o total recursivamente,
    sendo que em cada chamada verifica se há desequilibrio, e se houver,
    muda a flag para FALSE*/
int pesa(bool *flag)
{
    mobile aux;

    /*le a linha*/
    scanf("%d %d %d %d",&aux.Pe,&aux.De,&aux.Pd,&aux.Dd);

    /*se o Pe for zero*/
    if(aux.Pe == 0)
    {
        /*cacula o peso das barras abaixo*/
        aux.Pe = pesa(flag);
    }

    /*se Pd for zero*/
    if(aux.Pd == 0)
    {
        /*cacula o peso das barras abaixo*/
        aux.Pd = pesa(flag);
    }

    /*caso base: nem Pe nem Pd é zero*/
    if(aux.Pe && aux.Pd)
    {
        /*se estiver em desequilibrio*/
        if(aux.De*aux.Pe != aux.Dd*aux.Pd)
            *flag = FALSE;

        return aux.Pe+aux.Pd;/*retorne o peso da barra*/
    }

    return 0;
}

int main()
{
    int peso;
    bool flag=TRUE;/*a principio esta em equilibrio*/

    peso = pesa(&flag);

    /*se esta em equilibrio*/
    if(flag)
        printf("Mobile equilibrado\n");
    else
        printf("Mobile desequilibrado\n");

    printf("Peso total: %d\n",peso);

    return 0;
}
