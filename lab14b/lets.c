/************************************************************
 * Autor: Leticia Motta										
 * RA:159833												
 Laboratório 14b: Liber8									
 ***********************************************************/

#include <stdio.h>	
#include <stdlib.h>

/* Função que tem por objetivo encontrar todas as bombas dispostas pelo mapa */
void encontraBombas(char **mapa, int num_linhas, int num_colunas, int bomba_x, int bomba_y) {
	int i,j, raio;

	
	raio = mapa[bomba_x][bomba_y]-'0';
	mapa[bomba_x][bomba_y] = 'B';

    if(bomba_x-raio < 0)
    	i= 0; 
    else 
    	i =bomba_x-raio;

    if(bomba_y-raio < 0)
    	j= 0; 
    else 
     	j=bomba_y-raio;

    for(; (i <= bomba_x+raio) && (i < num_linhas); i++){ 
    	for(; (j <= bomba_y+raio) && (j < num_colunas); j++) {
		
			if (mapa[i][j] == '.') 
				mapa[i][j] = 'x';
			else if((mapa[i][j] != 'B') && (mapa[i][j] != 'x')) 
				encontraBombas(mapa, num_linhas, num_colunas, i, j);
			
			printf("%d %d %d %d %d\n",i,j,raio,bomba_x,bomba_y);
		}
	}		
}
/*Imprime o mapa final após as alterações feitas */
void imprimeMapa(char **mapa, int num_linhas, int num_colunas) {	
	int i,j;

	for(i=0; i < num_linhas; i++){
		for(j=0; j < num_colunas; j++){
			printf("%c", mapa[i][j]);
		}
	printf("\n");
	}
} 
int main() {
 	int num_linhas, num_colunas, bomba_x, bomba_y, i; /* Números de linhas e colunas do mapa */
 	char **mapa;

 	/* leitura das variáveis inteiras */
 	scanf("%d %d %d %d", &num_linhas, &num_colunas, &bomba_x, &bomba_y);

 	bomba_x--;
    bomba_y--;

    /* aloca dinamicamente o mapa */
 	mapa = malloc(num_linhas *sizeof(char*));
    	for(i=0;i < num_linhas;i++) {
        	mapa[i] = malloc((num_colunas+1) *sizeof(char)); 
        	scanf("%s", mapa[i]); /*lê o mapa*/
        }	

	/* Chamada das funções */
	encontraBombas(mapa, num_linhas, num_colunas, bomba_x, bomba_y);
	imprimeMapa(mapa, num_linhas, num_colunas);	

	/* Libera memória alocada*/
	for (i = 0; i < num_linhas; i++){
        free(mapa[i]);
    }
    free(mapa);

	/*Fim do programa */
 	return 0;
}