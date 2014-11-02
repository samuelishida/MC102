/**********************************************
 *Nome: Paulo Henrique da Fonseca**************
 *RA:138995************************************
 *Laboratorio 15a - Transferência de Bitcoins**
 **********************************************/

/* 1 eh mais, 2 eh menos e 3 eh zero*/

#include <stdio.h>

void leitura (int *sequencia, char *sequenciaentrada, int *validacao);
void mexe_operacoes(int *operadores, int *sequencia, int *validou, int
validacao);
int operacao (int *vetor, int *sequencia);

int main (){
    
    int sequencia[9], validacao, validou = 0, operadores[9];
    char sequenciaentrada[10];
	
	operadores[0] = 1;
    
    leitura(sequencia, sequenciaentrada, &validacao);
   
    mexe_operacoes(operadores, sequencia, &validou, validacao);
    
    if(validou){
        printf("Transferencia aceita\n");
    }else{
        printf("Transferencia abortada\n");
    }
    
    return 0;
}

void leitura (int *sequencia, char *sequenciaentrada, int *validacao){
    
    int i;
    
    scanf("%s %d", sequenciaentrada, validacao);
    
    for(i = 0; i < 9; i++){
        sequencia[i] = sequenciaentrada[i] - 48;
    }
    
    return;
}

void mexe_operacoes (int *vetor, int *sequencia, int *validou, int posicao, int validacao){
    
    int i;
	
	if(posicao == 9){
		if(operacao(vetor,sequencia) == validacao)
			*validou = 1;
	}
    
    for(i = 1; i<4 && !(*validou); i++){
        vetor[posicao] = i;
        mexe_operacoes(vetor,sequencia,validou,posicao+1,validacao);
    }
}

int operacao (int *vetor, int *sequencia, int validacao){
    int op, i, j, l;
    
    for(i=0; i<9; i++)
	{
		
	}
    
    return op;
}