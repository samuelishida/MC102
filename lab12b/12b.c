/*************************************************
* Nome: Samuel Toyoshi Ishida
* RA: 160250
* Turma: T
* Laboratorio 12b - Whiteworse
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tamanho maximo do nome do titular */
#define MAXNOME 21
/* Tamanho maximo do nome dos arquivos de entrada/saida */
#define MAXNOMEARQ 101
/* Numero maximo de contas */
#define MAXCONTAS 20
/* Numero maximo de transacoes */
#define MAXTRANS 40
/* Valor da taxa de deposito em conta com saldo negativo */
#define TAXA 5.00

/* Conta
 * ag = numero da agencia
 * cc = numero da conta corrente
 * titular = Nome do titular da conta
 * saldo = Saldo da conta
 */
struct Conta {
    int ag;
    int cc;
    char titular[MAXNOME];
    double saldo;
};

typedef struct Conta Conta;

/* Transacao
 * tipo - 'D' para Depositos e 'S' para Saques
 * ag - Numero da agencia
 * cc - Numero da conta corrente
 * valor - Valor da operacao
 */
struct Transacao {
    char tipo;
    int ag;
    int cc;
    double valor;
};

typedef struct Transacao Transacao;

int getId(Conta *key, Conta *vet, int n)
{
    int i;

    for(i=0; i<n; i++)
        if(vet[i].cc == key->cc && vet[i].ag == key->ag)
            return i;

    return -1;
}

int main(int argc, char **argv) {
    /* Nome do arquivo binario com as contas */
    char nomeArqConta[MAXNOMEARQ];
    /* Nome do arquivo binario com as transacoes */
    char nomeArqTrans[MAXNOMEARQ];
    /* Nome do arquivo binario de saida */
    char nomeArqSaida[MAXNOMEARQ];

    /* Ponteiro do arquivo binario com as contas */
    FILE *arqConta;
    /* Ponteiro do arquivo binario com as transacoes */
    FILE *arqTrans;
    /* Ponteiro do arquivo binario com as contas */
    FILE *arqSaida;

    /* Numero de contas */
    int numC;
    /* Numero de transacoes */
    int numT;
    /* Variavel contadora*/
    int i;
    /* Variavel que indica o indice no vetor retornado por search()*/
    int id;

    /* Vetor de registros do tipo Conta para armazenar a entrada */
    Conta contas[MAXCONTAS];
    /* Registro usado para fazer achar o indice*/
    Conta aux;
    /* Vetor de registros do tipo Transacao para armazenar a entrada */
    Transacao tr;


    /* Obtendo o nome dos arquivos */
    strcpy(nomeArqConta, argv[1]);
    strcpy(nomeArqTrans, argv[2]);
    strcpy(nomeArqSaida, argv[3]);

    /* Abrindo os arquivos */
    arqConta = fopen(nomeArqConta,"rb");
    arqTrans = fopen(nomeArqTrans,"rb");
    arqSaida = fopen(nomeArqSaida,"wb");

    /* Lendo os arquivos */
    fread(&numC,sizeof(int),1,arqConta);
    fread(&numT,sizeof(int),1,arqTrans);

    fread(contas,sizeof(Conta),numC,arqConta);

    /* Le as transacoes e as realiza*/
    for(i=0; i<numT; i++){
        fread(&tr,sizeof(Transacao),1,arqTrans);

        /* Atribui os devidos valores a variavel aux*/
        aux.ag = tr.ag;
        aux.cc = tr.cc;

        /* Encontra o indice no vetor contas dados os numeros de agencia e conta */
        id = getId(&aux,contas,numC);

        if(id != -1)/* Se achou a conta */
        {
            /* Verifica se a transicao foi valida, a classifica e a realiza*/
            if(tr.tipo == 'S')
            {
                if(contas[id].saldo > 0)
                {
                    if(contas[id].saldo - tr.valor >= 0){
                        contas[id].saldo -= tr.valor;
                        /* So imprime se a trasicao foi valida */
                        printf("T%d: %c %d %d %.2f\n",i,tr.tipo, tr.ag, tr.cc, tr.valor);
                    }

                    else if(contas[id].saldo - tr.valor >= -100){
                        contas[id].saldo -= (tr.valor+TAXA);
                        /* So imprime se a trasicao foi valida */
                        printf("T%d: %c %d %d %.2f\n",i,tr.tipo, tr.ag, tr.cc, tr.valor);
                    }
                }

            }
            else if(tr.tipo == 'D'){
                contas[id].saldo += tr.valor;
                /* So imprime se a trasicao foi valida */
                printf("T%d: %c %d %d %.2f\n",i,tr.tipo, tr.ag, tr.cc, tr.valor);
            }
        }

    }

    /* Escreve o numero de contas */
    fwrite(&numC,sizeof(int),1,arqSaida);

    /* Escreve todos os registros no arquivo binario */
    fwrite(&contas,sizeof(Conta),numC,arqSaida);


    /* Fechando os arquivos*/
    fclose(arqConta);
    fclose(arqTrans);
    fclose(arqSaida);

    return 0;
}
