/**********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 09a - Oliver Queen is alive!
************************************************/

#include <stdio.h>

#define BRANCA 0
#define AZUL 1
#define VERDE 2
#define VERMELHO 3
#define TREMOR 4


int main()
{
    int i, j, tMax, tCont, d, mapa[30][30], teta;

    /*******************************************************
        i, j = auxiliares
        tMax = tempo maximo
        tCont = contador de tempo
        d = dimensão do mapa
        mapa = matriz que armazena as informações do lugar
        teta = angulo em relação ao eixo x

        ###################### x
        # ---@ teta = 0
        # |
        # |
        # @ teta = 90
        #
        # @--- teta = 180
        #
        # @
        # |
        # | teta = 270
        y
    ********************************************************/

    /*lendo a entrada*/
    scanf("%d %d", &d, &tMax);

    for(i=0; i<d; i++)
        for(j=0; j<d; j++)
            scanf("%d",&mapa[i][j]);
    /*fim da leitura*/

    tCont = i = j = teta = 0;/*inicializando os valores*/

    /*enquanto o tempo nao acabar ou o dispositivo nao tiver sido encontrado ou
      o oliver nao sair do mapa ou pisar numa armadilha*/
    while(tCont<tMax && mapa[i][j] != TREMOR && mapa[i][j] != VERMELHO && i<d && j<d && i>=0 && j >= 0)
    {

        /******************************************************************************************************
            Região branca: devo marcá-la como uma região azul e seguir em frente por uma região;
            Região azul: devo marcá-la como verde, me virar para a esquerda e seguir em frente por uma região;
            Região verde: devo marcá-la como branca, me virar para a direita e seguir em frente por uma região.
        ********************************************************************************************************/
        switch (mapa[i][j])
        {
            case BRANCA:
                mapa[i][j] = AZUL;
            break;

            case AZUL:
                mapa[i][j] = VERDE;
                teta -= 90;/*vira para a esquerda*/
            break;

            case VERDE:
                mapa[i][j] = BRANCA;
                teta += 90;/*vira para a direita*/
            break;
        }

        /*ajusta o angulo*/
        if(teta < 0) teta += 360;
        else if(teta >= 360) teta -= 360;

        switch (teta)
        {
            case 0:
                j++;
            break;

            case 90:
                i++;
            break;

            case 180:
                j--;
            break;

            case 270:
                i--;
            break;
        }

        tCont++;
    }

    if(mapa[i][j] ==  VERMELHO || i == d || j == d || i < 0 || j < 0)
        printf("Oliver morre\n");
    else if(tCont == tMax)
        printf("Oliver nao chega ao dispositivo a tempo\n");
    else if(mapa[i][j] == TREMOR)
        printf("Oliver destroi o dispositivo em %d segundos\n",tCont);

    return 0;
}
