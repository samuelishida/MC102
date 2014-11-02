#include <stdio.h>

int main()
{
    float area, min, peso[7],notas[8][4], media=0,sum=0, nota1;
    int i, j;

    scanf("%f %f",&area, &min);

    for(i=0; i<6; i++)
        scanf("%f",&peso[i]);

    scanf("%f %f %f",&notas[0][0],&notas[0][1],&notas[0][2]);

    nota1 = (notas[0][0]-notas[0][1])*100/notas[0][2] + 500;

    printf("Primeira Fase: %.1f\n",nota1);

    if( nota1 >= 550)
    {
        for(i=1; i<6;i++)
            for(j=0;j<3;j++)
                scanf("%f",&notas[i][j]);

        for(i=0;i<6;i++)
        {
            notas[i][2] = (notas[i][0]-notas[i][1])*100/notas[i][2] + 500;
            media += peso[i]*( notas[i][2] );
            sum += peso[i];
        }

        media /= sum;

        printf("Segunda Fase: %.1f\n", media);

        printf("Grupo %d",(
              (area == 1 && notas[3][2] >= min && notas[5][2] >= min)
            ||(area == 2 && notas[2][2] >= min && notas[4][2] >= min)
            ||(area == 3 && notas[5][2] >= min) )?     (1):(2)      );
    }

    return 0;
}
