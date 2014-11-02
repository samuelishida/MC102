/**********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 09b - Concurso Público para Professor da UNICAMP
************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

/*estrutura para aramazenar os as notas*/
struct info{
    double nota;
    short participante;
};

/*estrutura para aramazenar os votos na classificação*/
struct lista{
    short votos;
    double media;
    short participante;
};

/*função para o qsort(), considerando os casos de empate na parta de preferencia*/
int compare1(const void *p1, const void *p2)
{
    const struct info *a = p1;
    const struct info *b = p2;

    if(a->nota < b->nota) return 1;
    else if(a->nota == b->nota)/*se der empate*/
    {
        if(a->participante < b->participante)/*cosidera a ordem de inscrição*/
            return -1;
        else
            return 1;
    }
    else if(a->nota > b->nota) return -1;

    return 0;
}

/*função para o qsort(), considerando os casos de empate na parte da classificação*/
int compare2(const void *p1, const void *p2)
{
    const struct lista *a = p1;
    const struct lista *b = p2;

    if(a->votos < b->votos) return 1;
    else if(a->votos == b->votos)/*se der empate*/
    {
        if(a->media < b->media)
            return 1;
        else if(a->media == b->media)/*se der empate*/
        {
            if(a->participante < b->participante)/*cosidera a ordem de inscrição*/
                return -1;
            else
                return 1;
        }
        else
            return -1;
    }
    else if(a->votos > b->votos) return -1;

    return 0;
}


int main()
{
    int i, j, m, k;
    double media[MAX]={0};
    struct info cPub[5][MAX];
    struct lista votos[MAX];

    /*entrada*/
    scanf("%d",&k);

    for(i=0; i<5; i++){
        for(j=0; j<k; j++){
            scanf("%lf",&cPub[i][j].nota);
            cPub[i][j].participante = j;
        }
    }
    /*fim da entrada*/



    /*calcula e imprime as notas medias*/

    for(i=0; i<k; i++){
        for(j=0; j<5; j++)
            media[i] += cPub[j][i].nota;
        media[i] /= 5.0;
    }

    printf("Nota Media:");

    for(i=0; i<k; i++)
        printf(" %.1f",media[i]);

    printf("\n\n");

    /*fim do bloco das medias*/



    /*Calcula e imprime as preferencias*/

    for(i=0; i<5; i++)/*ordena em ordem decrescente de notas os candidatos*/
        qsort(cPub[i],k,sizeof(struct info),compare1);

    printf("Preferencia:\n");

    for(i=0; i<5; i++){
        printf("Membro %d:",i+1);
        for(j=0; j<k; j++)
            printf(" %d",cPub[i][j].participante+1);/*previamente ordenado pela nota*/
        printf("\n");
    }

     printf("\n");

    /*fim do bloco das preferencias*/



    /*bloco da classificação*/
    printf("Classificacao:");

    for(i=0; i<k; i++)
    {
        for(j=0; j<k; j++){/*inicializa os valores*/
            votos[j].votos = 0;
        }

        for(j=0; j<5; j++){/*conta o numero de votos*/
            votos[cPub[j][0].participante].votos++;
            votos[cPub[j][0].participante].participante = cPub[j][0].participante;/*guarda os valores para analise no caso de empate*/
            votos[cPub[j][0].participante].media = media[cPub[j][0].participante];
        }

        /*ordena os candidatos pelos votos, depois pela media e depois pelo numero do candidato*/
        qsort(votos,k,sizeof(struct lista),compare2);

        for(j=0; j<5; j++)
            for(m=0; m<k; m++)
                if(cPub[j][m].participante == votos[0].participante)
                    cPub[j][m].nota = -1;/*retira o 1º colocado da lista*/

        for(j=0; j<5; j++)/*ordena em ordem decrescente de notas os candidatos*/
            qsort(cPub[j],k,sizeof(struct info),compare1);

        printf(" %d",votos[0].participante+1);/*imprime o colocado numero i+1*/
    }
    /*fim do bloco da classificação*/



    /*fim do programa*/

    printf("\n");

    return 0;
}
