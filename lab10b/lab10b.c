/***************************************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 10b:
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Nome: Kairo Vinícius Ramos
 * RA: 156075
 * Laboratorio 10b - Don't Panic */

#include <stdio.h>
#include <stdlib.h>

/* Tamanho maximo permutacao */
#define MAX_P 102

/* Imprime a lista da permutacao */
void exibir_lista(int lista[], int numeros_lista){
    int i;
    printf("(");
    for(i = 1; i < numeros_lista; i++)
        printf("%d ", lista[i]);
    printf("%d", lista[numeros_lista]);
    printf(")\n");
}

int main(){
    /* lista = permutação
     * vetaux = vetor auxiliar para troca */
    int lista[MAX_P], *vetaux = NULL;
    
    /* i = variavel para comando de repeticao 
     * tam_permutacao, tp = tamanho da permutacao
     * doublebreakpoint = */
    int i, tam_permutacao, tp, doublebreakpoint;
    
    /* Sequencia_permutada, sp = Sequencia de numeros ja ordenados
     * endfor, endwhile = flags para encerrar for e while */
    int sequencia_permutada = 0, sp = 0, endfor = 1, endwhile = 1;
    
    /* mini, maiori = posicao da menor e maior transposição
     * peso = contador dos peso total */
    int mini = 0, maiori = 0, peso = 0;
    
    /* Le o tamanho da permutacao */
    scanf("%d", &tam_permutacao);
    
    tp = tam_permutacao;
    sp = sequencia_permutada;
    
    /* O primeiro elemento da lista de permutacao é 0
     * O ultimo elemento é o tamanho da permutacao +1 */
    lista[0] = 0;
    lista[tp + 1] = tp + 1;
    
    /* Aloca posicoes para o vetor auxiliar */
    vetaux = malloc((tp + 2) * sizeof(int));
    
    /* Entrada da lista de permutacao */
    for(i = 1; i <= tp; i++)
        scanf("%d", &lista[i]);
    
    /* Saida da lista de permutacao */
    exibir_lista(lista, tp);
    
    /* Enquanto os elementos nao estiverem todos ordenados
     * realiza as operacoes necessarias para troca- los */     
    while(endwhile){
        /* inicializa maiori, mini como o ultimo elemento da permutacao
         * endfor é sempre verdade até que se prove o contrario */
        maiori = tp + 1;
        mini = tp + 1;
        endfor = 1;
        
        /* O primeiro elemento do vetor auxiliar sera sempre o primeiro elemento
         * a ser permutado na lista */
        vetaux[0] = lista[1];
        
        /* Verifica se há uma sequencia para ser realizada a permutacao
         * se nao houver, somente o primeiro elemento sera permutado */
        for( i = 1; i <= tp && endfor; i++){
            if(lista[i+1] - lista[i] == 1){
                vetaux[i] = lista[i+1];
                sp++;
                
                /* Se essa sequencia for igual ao numero de permutacao,
                 * encerra o while */
                if(sp == tp)
                    endwhile = 0;
            }            
            else
                endfor=0;
        }
        
        /* Verifica onde estao as transposicoes a serem feitas
         * a partir do elemento anterior a strip e o proximo elemento da strip
        */
        for(i = sp; i < tp + 1 && endwhile; i++){
            if(vetaux[0] - 1 == lista[i] && i != 0)
                mini = i;
            else if(vetaux[sp] + 1 == lista[i])
                maiori = i;
            
            
        }
        
        /* Verifica qual tem menor peso, ou seja, a menor transposição a ser
         * feita. Se for o elemento anterior a strip, colocará a strip 
         * apos o mesmo, e vai verificar se o elemento seguinte á esse elemento
         * anterior possui um numero (1)vez menor que ele nos elementos
         * anteriores a ele . Caso tenha, será realizado uma dupla remoção
         * de breakpoints */
        if(mini < maiori && endwhile){
            peso += mini;
            
            for(i = 1, doublebreakpoint = 0; i < mini; i++){
                if(lista[i] == lista[mini + 1] - 1){
                    sp = i - 1;
                    doublebreakpoint = 1;
                }    
            }
            /* Se for realizada uma dupla remocao, atualiza o vetor auxiliar */
            for(i = 1; i <= sp + 1 && doublebreakpoint; i++)
                vetaux[i] = lista[i + 1];
            
            /* Troca os elementos da permutacao
             * Primeiro removendo aqueles a serem permutados e reduzindo o
             * vetor. Depois colocando-os na posicao que devem ser colocado */
            for(i = 1; i <= ( mini - (sp + 1) ); i++)
                lista[i] = lista[sp + i + 1];
            for(i = 0; i < sp + 1; i++)
                lista[1 + mini - (sp + 1) + i] = vetaux[i];
        }
        
        else if (endwhile){
            peso += maiori - 1;
            
            /* Troca os elementos da permutacao
             * Primeiro removendo aqueles a serem permutados e reduzindo o
             * vetor. Depois colocando-os na posicao que devem ser colocado */
            for(i = 1; i <= (maiori - (sp + 2) ); i++)
                lista[i] = lista[sp + i + 1];
            for(i = 0; i < sp + 1; i++)
                lista[maiori - (sp + 1) + i] = vetaux[i];
            
        }
        
        /* Exibir lista atualizada */
        if(endwhile)
            exibir_lista(lista, tp);
        /* Inicializa a sequencia de permutacao */
        sp = 0;
    }    
    
    /* Exibe o peso total */
    printf("Peso: %d\n", peso);
    
    /* Libera a memoria anteriormente alocada do vetor auxiliar */
    free(vetaux);
    
    return 0;
}