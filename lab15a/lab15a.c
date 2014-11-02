/*********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 15a - Transferencia de Bitcoins
**********************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SUM 0
#define SUB 1
#define CAT 2 /*operador de concatenacao, designidado pelo caracter &*/

#define MAX 9

int ctoi(char c);
void combine(char num[], char comb[], int i, bool *flag,int *n);

/*funcao para converter char para int*/
int ctoi(char c)
{
	return c-'0';
}

int calc(char num[],char comb[])
{
	int cat=false, res=0, subnum=0;
	int i, j;
	
	/*a flag cat eh para marca a operacao de concatenacao de numeros
	  se ela for true, entao ate aquele ponto o programa estava realizando
	  a operacao*/
	
	for(i = MAX-1; i>=0; i--)
	{
		if(comb[i] == '+')
		{
			/*se estava fazendo uma concatenacao*/
			if(cat)
			{
				cat = false;/*fim da operacao de concatenacao*/
				subnum += ctoi(num[i])*j;/*multiplica por 10^j e soma*/
				res += subnum;
			}
				
			else
				res += ctoi(num[i]);
			
		}
			
		else if(comb[i] == '-')
		{
			if(cat)/*se estava fazendo uma concatenacao*/
			{
				cat = false;/*fim da operacao de concatenacao*/
				subnum += ctoi(num[i])*j;/*multiplica por 10^j e subtrai*/
				res -= subnum;
			}
				
			else
				res -= ctoi(num[i]);
		}
			
		else if(comb[i] == '&')
		{
			/*se nao estava realizando uma concatenacao, inicie uma nova*/
			if(!cat)
			{
				cat = true;
				subnum = 0;
				j = 1;
			}
			/*junta os numeros*/
			subnum += ctoi(num[i])*j;
			j*=10;
		}
	}
	
	return res;
}

/*faz todas as comibanções possiveis de operadores e a salva dentro do vetor comb[]*/
void combine(char num[], char comb[], int i, bool *flag,int *n)
{
	int operator;
	
	/*se chegou ao final do vetor*/
	if(i == MAX )
	{
		/*se a conta der igual a n, entao existe uma transicao valida*/
		if(calc(num,comb) == *n)
			*flag = true;
			
		return;
	}
		
	/*realiza as combinacoes*/
	for(operator=SUM;operator<=CAT && !(*flag);operator++)
	{
		/*se a flag for true, nao precisa mais verificar nenhuma combinacao*/
		if(operator == SUM)
		{
			comb[i] = '+';
			combine(num,comb,i+1,flag,n);
		}
		
		else if(operator == SUB)
		{
			comb[i] = '-';
			combine(num,comb,i+1,flag,n);
		}
		
		else if(operator == CAT)
		{
			comb[i] = '&';
			combine(num,comb,i+1,flag,n);
		}
	}
	
	return;
}

int main()
{
	int n;
	char num[MAX+1], comb[MAX+1]={0};
	bool flag = false;/*se for true, ha um combinacao possivel*/
	
	scanf("%s %d",num,&n);
	
	/*o primeiro numero sempre eh positivo*/
	comb[0] = '+';
	
	combine(num,comb,1,&flag,&n);
	
	printf("%s\n",(flag)?( "Transferencia aceita" ):( "Transferencia abortada" ));
	
	return 0;
}