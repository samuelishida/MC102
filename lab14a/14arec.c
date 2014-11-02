/*********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 14a - Gerenciador de memoria
**********************************************/

#include <stdio.h>

void imprime(double memoria, double aloc)
{
	char c;
	
	scanf("%c",&c);/*a recursao pode acabar antes do '#', nesse caso indicando alocacao invalida*/
	
    if(memoria > aloc)/*se sobrou regioes de memoria*/
        printf("Alocacao parcial\n");
    else if(memoria == aloc && c == '#')/*se a alocou todas as regioes*/
        printf("Alocacao total\n");
    else/*solicitou mais regioes do que havia disponivel*/
        printf("Alocacao invalida\n");
}

double mem(double memoria)
{
	double aloc;
    char c;

    scanf("%c",&c);

    if(c == 'D')
    {
        aloc = mem(memoria/4);/*cria uma regiao de 1/4 de memoria*/
		aloc += mem(memoria/4);/*cria a outra regiao de 1/4 de memoria*/
        return memoria/2 + aloc;/*toma metade da regiao atual + 1/4 + o outro 1/4*/
    }
	
	if(c == 'I')
    {
        return (memoria);/*I simplesmente pega a regiao atual inteira*/
    }

    return 0;/*quando acabar a recursao*/
}

int main()
{
	double memoria=1, aloc=0;

    aloc = mem(memoria);
	
    /*imprime a resposta*/
    imprime(memoria, aloc);

    /*fim do programa*/
    return 0;
}
