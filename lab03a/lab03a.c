#include <stdio.h>

/*
    RA: 160250
    Nome: Samuel Toyoshi Ishida
    Laboratorio 03a
*/

int main()
{
	double sum=0;
	int i=0;
	char c;
	
	scanf("%c",&c);

	while(c != '*')
	{
		
		sum = 0;
		i = 0;
		
		/* Este bloco vai lendo os chars e incrementando o valor de sum
			com os respectivos valores (1,1/2,1/4,1,16,1/32,1/64,1/128),
			como A=65, B=66 ... O valor a ser incrementado sera 1/2^(c-65)
		*/		
		while(c != '\n')
		{
			sum += 1.0/(1 << (c - 65));/* 1/( 2 ^ (c-65)  )*/
			i++;
			scanf("%c",&c);
		}
		
		if(sum == 1)
			printf("%d",i);
		else
			printf("0");
		
		scanf("%c",&c);            
	}
    
	printf("\n");

	return 0;
}
