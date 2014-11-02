#include <stdio.h>

/**********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 07a - The Voice - Blind Auditions
************************************************/

int main()
{
    int hit[100][4], pref[100][4], i, j, n;
    struct{
        int p[100];/*guarda os participantes do time*/
        int tam;/*guarda o tamanho do time*/
    }time[4];

    /*********************************************************
        hit = matriz que mostra os botoes que foram apertados
        pref = matriz que mostra a preferencia dos participantes
        time = estrutura que guarda os times finais
    ***********************************************************/

    /*le a entrada */
    scanf("%d",&n);

    for(i=0; i<4; i++)
        time[i].tam=0;

    for(i=0; i<n; i++)
        for(j=0; j<8; j++)
            (j<4)?(scanf("%d",&hit[i][j])):(scanf("%d",&pref[i][j-4]));

    /*fim da leitura*/

    for(i=0; i<n; i++){
        for(j=0; j<4; j++){
            if(hit[i][pref[i][j]-1]){/*verifica na ordem de preferencia se o artista escolhido apertou o botao*/
                j = pref[i][j]-1;/*atribui o valor ao j só pela maior clareza*/
                time[j].p[time[j].tam++] = i+1;/*coloca o participante no time e incrementa o tamanho deste*/
                break;
            }
        }
    }

    /*imprime a saida*/
    for(i=0; i<4; i++){
        printf("Time %d:",i+1);

        for(j=0; j<time[i].tam; j++)
            printf(" %d",time[i].p[j]);

        if(time[i].tam == 0)/*se ninguem apertou o botao*/
            printf(" Nenhum participante");

        printf("\n");
    }


    /*fim do programa*/

    return 0;
}
