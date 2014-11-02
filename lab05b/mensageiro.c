/*Nome: Paulo Henrique da Fonseca*
 *RA: 138995*
 *Laboratorio 07 - Killing the Messenger*/

#include <stdio.h>


/*
 *    Recebe o mRNA (com tamanho R) e Oligonucleotideo (com tamanho O)
 *    a ser comparados, e retorna:
 *     - caso o mRNA seja silenciado, retornar a primeira posicao inicial
 *       para o mRNA em que os trechos sao iguais;
 *     - caso nao haja trecho em comum, retornar -1.
 */
int ComparaRNA(char rna[], int R, char oligo[], int O);

int Combina(char rna, char oligo);


int main(){
    
    int R, O, i, compara, k;
    char rna[101], oligo[26], aux;
    
    scanf("%d %d", &R, &O);
   
    scanf("%s", rna);
    
    scanf("%s", oligo);
   
    
    for(i = 0, k = O-1; i<O/2; i++, k--){
        aux = oligo[k];
        oligo[k] = oligo[i];
        oligo[i] = aux;
    }
    
    compara = ComparaRNA(rna, R, oligo  , O);
    
    if(compara == (-1)){
        printf("Nao silenciado\n");
    }else{
        printf("Silenciado em %d\n", compara);
    }
    
    return 0;
}


int ComparaRNA(char rna[], int R, char oligo[], int O){
    
    int i, j, k, flag = 1, combina;

    for(i=0; i<R; i++){
        combina = Combina(rna[i], oligo[0]);
        if(combina){
            k = i+1;
            for(j = 0; (j < O) && (flag) && (k < R); j++, k++){
                combina = Combina(rna[k], oligo[j]);
                if(combina == 0){
                    flag = 0;
                }
            }
            if(j == O){
                return i;
            }
        }
    }
    return -1;
}

int Combina(char rna, char oligo){
    
    if(rna == 'A' && oligo == 'U'){
        return 1;
    }else if(rna == 'U' && oligo == 'A'){
        return 1;
    }else if(rna == 'C' && oligo == 'G'){
        return 1;
    }else if(rna == 'G' && oligo == 'C'){
        return 1;
    }
    
    return 0;
}