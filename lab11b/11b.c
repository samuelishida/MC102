/**********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 11b - BibTeX
************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;/*define o tipo string*/

/*registro usado para armazenar a entrada*/
struct info
{
    string author;
    string title;
    string journal;
    string volume;
    string year;
    string pages;
    string number;
    short n;/*indica a ordem em que a estrutura veio na entrada*/
};

typedef struct info info;/*define o tipo info como sendo struct info*/

/*atribui o conteudo ao elemento campo da estrutura article*/
void atribuiConteudo(info *article, string campo, string conteudo)
{
    if(strcmp(campo,"author") == 0){
        article->author = malloc((strlen(conteudo)+1)*sizeof(char));
        strcpy(article->author , conteudo);
    }

    else if(strcmp(campo,"title") == 0){
        article->title = malloc((strlen(conteudo)+1)*sizeof(char));
        strcpy(article->title , conteudo);
    }

    else if(strcmp(campo,"journal") == 0){
        article->journal = malloc((strlen(conteudo)+1)*sizeof(char));
        strcpy(article->journal , conteudo);
    }

    else if(strcmp(campo,"year") == 0){
        article->year = malloc((strlen(conteudo)+1)*sizeof(char));
        strcpy(article->year , conteudo);
    }

    else if(strcmp(campo,"volume") == 0){
        free(article->volume);
        article->volume = malloc((strlen(conteudo)+1)*sizeof(char));
        strcpy(article->volume , conteudo);
    }

    else if(strcmp(campo,"pages") == 0){
        free(article->pages);
        article->pages = malloc((strlen(conteudo)+1)*sizeof(char));
        strcpy(article->pages , conteudo);
    }

    else if(strcmp(campo,"number") == 0){
        free(article->number);
        article->number = malloc((strlen(conteudo)+1)*sizeof(char));
        strcpy(article->number , conteudo);
    }
}

/*funcao de comparacao do qsort()*/
int titlecmp(info *a, info *b)
{
    int ret = strcmp(a->title,b->title);

    if(ret == 0)/*leva em consideração a ordem*/
        return (int)(a->n - b->n);


    return ret;
}

/*função para inicializar os valores do vetor de struct info*/
void iniciaValores(info *article, int n)
{
    int i;
    /*atribui '\0' pois se o campo estiver vazio, na hora da impressao nao imprimira nada*/
    for(i=0; i<n; i++){
        article[i].number = malloc(51*sizeof(char));
        article[i].pages = malloc(51*sizeof(char));
        article[i].volume = malloc(51*sizeof(char));

        article[i].number[0] = article[i].pages[0] = article[i].volume[0] = '\0';
        article[i].n = i;
    }

}

/*função para imprimir a resposta final*/
void imprime(info *article, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("%s, %s, %s",article[i].title,article[i].author,article[i].journal);

        if(article[i].volume[0])/*se nao estiver vazio*/
            printf(", %s",article[i].volume);
        if(article[i].number[0])/*se nao estiver vazio*/
            printf(", %s",article[i].number);
        if(article[i].pages[0])/*se nao estiver vazio*/
            printf(", %s",article[i].pages);


        printf(", %s.\n\n",article[i].year);
    }
}

/*função para limpar tudo que fora alocado durante o programa*/
void limpa(string a, string b, info *article, int n)
{
    int i;

    free(a);
    free(b);

    for(i=0; i<n; i++)
    {
        free(article[i].author);
        free(article[i].title);
        free(article[i].journal);
        free(article[i].pages);
        free(article[i].volume);
        free(article[i].year);
        free(article[i].number);
    }

    free(article);
}


int main()
{
    int i,n;
    info *article;
    string conteudo = malloc(520*sizeof(char));
    string campo = malloc(15*sizeof(char));

    /*leitura da entrada*/

    scanf("%*c");/*descarta o %*/
    scanf("%d",&n);

    article = malloc(n*sizeof(info));/*aloca n*sizeof(info) bytes de memoria memoria*/

    iniciaValores(article,n);

    for(i=0; i<n; i++)
    {
        scanf("%*s");/*le e descarta o label*/

        scanf("%s",campo);/*le o campo*/

        while( strcmp(campo,"}") ) /*se nao é '}', isto eh fim do article*/
        {
            /*le o conteudo com todos os caracteres entre 32 e 254 na tabela ASCII até o } e descarta o "= {"*/
            scanf(" = {%[^}][32-254]s",conteudo);

            scanf("%*s");/*descarta o resto que nao foi lido*/

            atribuiConteudo(&article[i],campo,conteudo);/*copia a entrada para o vetor de info*/

            scanf("%s",campo);/*le o proximo campo*/
        }

    }

    /*fim da leitura*/

    /*ordena os artigos pelo titulo*/
    qsort(article,n,sizeof(info),(int(*)(const void*,const void*))titlecmp);
    /*função qsort() pede um parametro que é a funcao que ele usa para fazer as comparacoes,
      e essa funcao tem que ser necessariamente do tipo int e receber dois ponteiros const void.
      os outros parametros sao: o ponteiro do vetor, o numero de elementos e o tamanho de cada elemento*/

    /*imprime saida*/
    imprime(article,n);

    /*limpa a memoria*/
    limpa(campo,conteudo,article,n);

    /*fim do programa*/
    return 0;
}
