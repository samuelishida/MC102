#include<stdio.h>

/*
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
*/
int max(int a, int b)
{
	return (a > b)?(a):(b);/*retorna o maximo*/
}

int main()
{
    int num0=0, num1=0, contF=0,tamF=0;/*variáveis contadoras*/
    int numMols=0;/* Número de mols transportados*/
    int in=0, prevIn=0; /*Entrada e entrada anterior*/
    int S, M;/* Dados do enunciado */

    scanf("%d %d",&M,&S);

    /*Iniciando as variáveis para o laço*/
    scanf("%d",&in);
    prevIn = in;
    /*Este bloco desconsidera a primeira leitura*/

    while(prevIn == in)
    {
        prevIn = in;
        scanf("%d",&in);
    }

	prevIn = in;

    /*Este é o bloco principal, onde o programa vai contando
      os números zeros e uns e verificando se houve ou não o
      sincronismo. Se houver sincronismo ele incrementa o nú-
      mero de mols transportados*/
    while(in != -1)
    {
		if(in != prevIn) /*se houve mudança de fase*/
		{

			if(!tamF)
				tamF = max(num0,num1);


            if(num0 == num1)/* duas fases iguais*/
            {
                if(tamF == num0)/*se as fases em sincronia são iguais as anteriores*/
                    contF++;
                else
                {
                    contF = 0;
                    tamF = num0;
                }
            }
			else
				contF = 0;

            if(contF == S-1)/*Se o portal abriu*/
            {
                numMols = M*tamF;
                contF = tamF = 0;/*reseta a contagem*/
            }

			if(in)
			{
				num1 = 0;
				tamF = num0;
			}
			else
			{
				num0 = 0;
				tamF = num1;
			}
		}

		if(in)/*conta os 0 e 1*/
			num1++;
		else
			num0++;

        prevIn = in;/* salva o in atual*/
        scanf("%d",&in);/* atribui o pŕoximo valor ao in*/

    }/* fim do while principal */

    if(numMols)
        printf("%d mols\n",numMols);
    else
        printf("Portal nao abriu\n");


    return 0;
}

