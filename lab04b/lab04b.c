#include<stdio.h>

/*
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma T
    Laboratorio 04b - Semanada
*/

int main()
{
    int vet[100], n, numRet,contRet=0, i, maior=0,tamVal=0;

    scanf("%d %d",&n,&numRet);

    for(i=0;i<n;i++)
        scanf("%d",&vet[i]);/*atribui os numeros ao vetor vet*/

    while(contRet < numRet && tamVal < n-numRet)/*enquanto nao retirar tudo ou tamVal exceder o limite*/
    {
        /*varre de tamVal até a quantidade a ser extraida+1 procurando pelo maior elemento*/
        for(i=tamVal, maior=0; i<=numRet-contRet+tamVal; i++)
            if(maior <= vet[i])
                maior = vet[i];

        /*elimina os valores menores que maior a esquerda dele*/
        while(vet[tamVal] < maior)
        {
            for(i=tamVal; i<n-1; i++)
                vet[i] = vet[i+1];
            contRet++;
        }

        tamVal++;

    }/*Fim do While principal*/

    printf("Maior valor: ");

    for(i=0;i<n-numRet;i++)
        printf("%d",vet[i]);/*Imprimindo resposta*/

    /*Fim do programa*/
    printf("\n");
    return 0;
}
