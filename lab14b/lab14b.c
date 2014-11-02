// lab14b.cpp : Defines the entry point for the console application.
//


/* Nome: Leonardo Beretta Alvetti
 * RA:156191
 * Laboratorio 14b - Liber8 */

#include <stdio.h>

#define TAM_MAX 50
#define CONVERSAO_ASCII 48

void ProcuraBomba(char mapa[TAM_MAX + 1][TAM_MAX + 1], int pos_x, int pos_y, int num_linhas, int num_colunas);

int main() {
    /* Declaracao */
    char mapa[TAM_MAX + 1][TAM_MAX + 1];
    int num_linhas, num_colunas, num_bombas;
    int pos_x, pos_y;
    int i;

    /* Leitura */
    scanf("%d %d %d %d", &num_linhas, &num_colunas, &pos_x, &pos_y);
    for(i = 0; i < num_linhas; i++)
        scanf("%s", mapa[i]);

   
    
    ProcuraBomba(mapa, (pos_x - 1), (pos_y - 1), num_linhas, num_colunas);

    for(i = 0; i < num_linhas; i++)
        printf("%s\n", mapa[i]);

    return 0;
}

void ProcuraBomba(char mapa[TAM_MAX + 1][TAM_MAX + 1], int pos_x, int pos_y, int num_linhas, int num_colunas) {
    int i, j, comeca_ler_linha, termina_ler_linha, comeca_ler_coluna, termina_ler_coluna, raio;
	
	raio = mapa[pos_x][pos_y]-48;
    mapa[pos_x][pos_y] = 'B';

    comeca_ler_linha = pos_x - raio;
    termina_ler_linha = pos_x + raio+1;

    comeca_ler_coluna = pos_y - raio;
    termina_ler_coluna = pos_y + raio +1;

    /* Ajusta pra nao sair do mapa */
    while(comeca_ler_linha < 0)
        comeca_ler_linha++;
    while(termina_ler_linha > num_linhas)
        termina_ler_linha--;
    while(comeca_ler_coluna < 0)
        comeca_ler_coluna++;
    while(termina_ler_coluna > num_colunas)
        termina_ler_coluna--;
		

    for(i = comeca_ler_linha; i < termina_ler_linha; i++)
        for(j = comeca_ler_coluna; j < termina_ler_coluna; j++) {
           
            if((mapa[i][j] != 'x') && (mapa[i][j] != 'B') && (mapa[i][j] != '.')) {
                
                
                ProcuraBomba(mapa, i, j, num_linhas, num_colunas);
            } else if(mapa[i][j] == '.') {
                mapa[i][j] = 'x';
            }
        }
}