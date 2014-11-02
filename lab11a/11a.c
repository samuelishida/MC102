/**********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 11a - Copa do Mundo
************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;

enum letras
{
    A,B,C,D,E,F,G,H/*enumeração para indentificar os grupos*/
};

struct time
{
    char nome[15];
    int golsFeitos;
    int golsSofridos;
    int pontos;
};

typedef struct time time;

string times[] = { "Brasil","Mexico","Croacia","Camaroes",
                   "Chile","Holanda","Espanha","Australia",
                   "Japao","Colombia","Grecia","CostaDoMarfim",
                   "Italia","Uruguai","Inglaterra","CostaRica",
                   "Equador","Suica","Franca","Honduras",
                   "Bosnia","Ira","Nigeria","Argentina",
                   "Alemanha","EstadosUnidos","Gana","Portugal",
                   "Belgica","Argelia","CoreiaDoSul","Russia"};

/*funcao para saber o indice do time dado o nome dele*/
int hashTable(string str)
{
    int i=0, j=0;

    for(i=0; i<4; i++)
        for(j=0; j<8; j++)
            if(strcmp(str,times[i+4*(j)]) == 0)
                return i;

    return -1;

}

/*ajusta os valores iniciais e coloca os nomes dos times*/
void iniciaTimes(time grupos[][4])
{
    int i, j, k=0;


    for(i=A; i<=H; i++)
        for(j=0; j<4; j++){
            grupos[i][j].golsFeitos = grupos[i][j].golsSofridos = grupos[i][j].pontos = 0;
            strcpy(grupos[i][j].nome, times[k++]);
        }
}

/*funcao de comparacao para ser usada na ordenacao*/
int compare(const void *p1, const void *p2)
{
    const time *a = p1;
    const time *b = p2;

    if(a->pontos < b->pontos) return 1;

    else if(a->pontos == b->pontos)/*se der empate*/
    {
        if(a->golsFeitos - a->golsSofridos < b->golsFeitos - b->golsSofridos)
            return 1;

        else if(a->golsFeitos - a->golsSofridos == b->golsFeitos - b->golsSofridos)/*se der empate*/
        {
            if(a->golsFeitos < b->golsFeitos)
                return 1;
            else if(a->golsFeitos == b->golsFeitos)/*se der empate*/
            {
                return (strcmp(a->nome,b->nome));/*ordem alfabetica*/
            }
            else
                return -1;
        }

        else
            return -1;
    }

    else if(a->pontos > b->pontos) return -1;

    return 0;
}

int main()
{
    int i, j, gols_time1, gols_time2, indice1, indice2;
    time grupos[8][4];
    char nome_time1[15], nome_time2[15];

    iniciaTimes(grupos);

    for(i=0; i<6*8; i++){
        scanf("%s %d x %d %s", nome_time1, &gols_time1, &gols_time2, nome_time2);

        /*calcula o indice na matriz com base no time*/
        indice1 = hashTable(nome_time1);
        indice2 = hashTable(nome_time2);

        /*i/6 indica o grupo ao qual os resultados sao*/
        grupos[i/6][indice1].golsFeitos += gols_time1;
        grupos[i/6][indice1].golsSofridos += gols_time2;

        grupos[i/6][indice2].golsFeitos += gols_time2;
        grupos[i/6][indice2].golsSofridos += gols_time1;

        /*calcula a pontuação*/
        if(gols_time1 > gols_time2)
            grupos[i/6][indice1].pontos += 3;
        else if( gols_time1 < gols_time2)
            grupos[i/6][indice2].pontos += 3;
        else
        {
            grupos[i/6][indice1].pontos++;
            grupos[i/6][indice2].pontos++;
        }
    }

    /*ordena*/
    for(i=A; i<=H; i++)
        qsort(grupos[i],4,sizeof(time),compare);

    /*imprime a saida*/
    for(i=A; i<=H; i++)
    {
        printf("Grupo %c:\n",'A'+i);

        for(j=0; j<4; j++)
        {
            printf("%-15s %3d %3d %3d %3d\n",
                   grupos[i][j].nome, grupos[i][j].pontos, grupos[i][j].golsFeitos,
                   grupos[i][j].golsSofridos, grupos[i][j].golsFeitos-grupos[i][j].golsSofridos);
        }
        printf("\n");
    }

    printf("Oitavas de final:\n");

    for(i=A; i<=H; i+=2){
        printf("%15s x %s\n", grupos[i][0].nome, grupos[i+1][1].nome);
        printf("%15s x %s\n", grupos[i+1][0].nome, grupos[i][1].nome);
    }
    /*fim da saida*/

    /*fim do programa*/
    return 0;
}
