#include <stdio.h>
#include <string.h>

/**********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 07b - Modern Word Search
************************************************/

#define MAX 50
#define TRUE 1
#define FALSE 0

int vogal(char letra)
{
    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
        return TRUE;
    else
        return FALSE;
}

int main()
{
    int i, j, k, z, n, m, tam, hits;
    char palavra[MAX/2 + 1], tab[MAX][MAX + 1], res[MAX][MAX];

    /*******************************************************
        i, j, k, z = auxiliares
        palavra = string a ser procurada
        tab = matrik q armakena o caça palavras
        n, m = numero de linhas e colunas
        tam = numero de caracteres de palavra
        hits = numero de ocorrencias
        res = matrik que contem as palavras
        vogal() = função que verifica se o char é uma vogal
    ********************************************************/

    /*leitura da entrada*/

    scanf("%d %d %s",&n, &m, palavra);

    for(i=0; i<n;i++)
        scanf("%s",tab[i]);

    /*fim da leitura*/


    /*inicialikando os valores*/

    hits = 0;/*inicialmente não há nenhuma palavra encontrada*/

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            res[i][j] = '.';/*inicialmente não há nenhuma palavra encontrada*/

    tam = strlen(palavra);

    /*fim da inicialikação*/


    /*verifica as palavras na horizontal*/
    for(i=0; i<n; i++)
    {
        for(j=0; j<=m-tam; j++)
        {
            for(k=0; k<tam; k++)
            {
                if(tab[i][j+k] == palavra[k])
                    continue;
                else if(tab[i][j+k] == '_')
                    continue;
                else if(tab[i][j+k] == '#' && vogal(palavra[k]) )
                    continue;
                else if(tab[i][j+k] == '%' && !vogal(palavra[k]))
                    continue;
                else
                    break;
            }

            if(k == tam)/*se achou a palavra*/
            {
                for(k=j; k<j+tam; k++)
                    res[i][k] = tab[i][k];
                hits++;
            }
        }
    }
    /*fim da verificação*/

    /*verifica as palavras na vertical*/
    for(j=0; j<m; j++)
    {
        for(i=0; i<=n-tam; i++)
        {
            for(k=0; k<tam; k++)
            {
                if(tab[i+k][j] == palavra[k])
                    continue;
                else if(tab[i+k][j] == '_')
                    continue;
                else if(tab[i+k][j] == '#' && vogal(palavra[k]) )
                    continue;
                else if(tab[i+k][j] == '%' && !vogal(palavra[k]))
                    continue;
                else
                    break;
            }

            if(k == tam)/*se achou a palavra*/
            {
                for(k=i; k<i+tam; k++)
                    res[k][j] = tab[k][j];
                hits++;
            }
        }
    }
    /*fim da verificação*/

    /*verifica as palavras no triangulo superior e diagonal principal*/
    for(j=0; j<=m-tam; j++)
    {
        i=0;
        for(k=j; k<=m-tam && i<=n-tam; k++, i++)
        {
            for(z=0; z<tam; z++)
            {
                if(tab[i+z][k+z] == palavra[z])
                    continue;
                else if(tab[i+z][k+z] == '_')
                    continue;
                else if(tab[i+z][k+z] == '#' && vogal(palavra[z]) )
                    continue;
                else if(tab[i+z][k+z] == '%' && !vogal(palavra[z]))
                    continue;
                else
                    break;
            }

            if(z == tam)/*se achou a palavra*/
            {
                for(z=0; z<tam; z++)
                    res[i+z][k+z] = tab[i+z][k+z];

                hits++;
            }
        }
    }
    /*fim da verificação*/

    /*verifica as palavras no triangulo inferior*/
    for(i=1; i<=n-tam; i++)
    {
        j=0;
        for(k=i; k<=n-tam && j<=m-tam; k++, j++)
        {
            for(z=0; z<tam; z++)
            {
                if(tab[k+z][j+z] == palavra[z])
                    continue;
                else if(tab[k+z][j+z] == '_')
                    continue;
                else if(tab[k+z][j+z] == '#' && vogal(palavra[z]) )
                    continue;
                else if(tab[k+z][j+z] == '%' && !vogal(palavra[z]))
                    continue;
                else
                    break;
            }

            if(z == tam)/*se achou a palavra*/
            {
                for(z=0; z<tam; z++)
                    res[k+z][j+z] = tab[k+z][j+z];

                hits++;
            }
        }
    }
    /*fim da verificação*/


    /*imprime a saida final*/
    printf("%s %d\n",palavra, hits);

    for(i=0; i<n; i++){
        for(j=0;j<m;j++)
            printf("%c",res[i][j]);
        printf("\n");
    }
    /*fim da saida*/

    /*fim do programa*/

    return 0;
}
