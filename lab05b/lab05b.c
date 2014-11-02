#include <stdio.h>
#include <string.h> /* para a função strstr() */

/*
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 05b - Killing the Messenger
*/

int main()
{
    int numR, numO, x=0,i;
    char mRNA[101], oligo[26], aux;

    /*le as entradas*/

    scanf("%d %d",&numR,&numO);

    scanf("%s %s",mRNA,oligo);

    for(i=0; i<numO; i++)/*troca as bases para comparação*/
    {
        switch (oligo[i])
        {
            case 'A':
                oligo[i] = 'U';
                break;
            case 'U':
                oligo[i] = 'A';
                break;
            case 'G':
                oligo[i] = 'C';
                break;
            case 'C':
                oligo[i] = 'G';
                break;
        }
    }

    if(strstr(mRNA,oligo) == NULL)/*se não achou a substring olido dentro da mRNA*/
    {
        for(i=0; i<numO/2;i++)/*inverte a string*/
           {
               aux = oligo[i];
               oligo[i] = oligo[numO-i-1];
               oligo[numO-i-1] = aux;
           }
    }

    /*x = ponteiro do primeiro elemento coincidente de substring menos
        o primeiro ponteiro da string, resultando no indice da string em
        que o primeiro elemento coincide*/
    x = (int)(strstr(mRNA,oligo)-mRNA) + 1;

    if(x <= 0 || x > 100)/*se não achou a substring*/
        printf("Nao silenciado\n");
    else
        printf("Silenciado em %d\n",x);

    /*fim do programa*/

    return 0;
}
