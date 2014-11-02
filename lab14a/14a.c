/*********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 14a - Gerenciador de memoria
**********************************************/

#include <stdio.h>

void imprime(int memoria, int aloc)
{
    if(memoria > aloc)/*se sobrou regioes de memoria*/
        printf("Alocacao parcial\n");
    else if(memoria == aloc)/*se a alocou todas as regioes*/
        printf("Alocacao total\n");
    else/*solicitou mais regioes do que havia disponivel*/
        printf("Alocacao invalida\n");
}

int main()
{
    char c;
    int memoria=1, aloc=0;

    scanf("%c",&c);

    while(c != '#')
    {
        if(c == 'D')
        {
            /*O processo de dividir abre mais duas regioes de memoria, pois divide a atual em 3,
              ou seja, o numero de regioes disponiveis aumenta em 2*/
            memoria += 2;
            aloc++;/*ocupa uma das regioes*/
        }
        else if(c == 'I')
            aloc++;/*aloca uma regiao*/

        scanf("%c",&c);
    }

    /*imprime a resposta*/
    imprime(memoria, aloc);

    /*fim do programa*/
    return 0;
}
