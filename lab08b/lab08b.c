/* lab12: Processamento de imagens
 * Autor: Filipe de Oliveira Costa.
 * E-mail: filipe.costa@ic.unicamp.br
 */


/**********************************************
    Nome: Samuel Toyoshi Ishida
    RA: 160250
    Turma: T
    Laboratorio 08b - Processamento de imagens
************************************************/

#include <stdio.h>
#include <string.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

/* Le uma imagem em formato PGM a partir da entrada padrao.
 * Retorna 1 se a leitura for realmente de um arquivo PGM
 * e 0 caso contrario.
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO                       */
int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
            int *F, double *Px, double *Py) {
    char nome_formato[3];
    char c;
    int i,j;

    /* Le o formato da imagem. P2 indica o formato PGM */
    scanf("%s ", nome_formato);
    if (strcmp(nome_formato, "P2") != 0)
        return 0;

    /* Le o '#', que indica um comentario, e os numeros indicando
    * o filtro e o parametro, se houver */
    scanf("%[#]c", &c);
    scanf("%d", F);
    if (*F == 4) {
        scanf("%lf %lf", Px, Py);
    }

    /* Le dimensoes e intensidade maxima da imagem */
    scanf("%d", W);
    scanf("%d", H);
    scanf("%d", MaxV);

    /* Le o valor de cada pixel da imagem */
    for (i = 0; i < (*H); i++) {
        for (j = 0; j < (*W); j++) {
            scanf("%d", &img[i][j]);
        }
    }

    return 1;
}

/* Escreve a imagem em formato pgm na saida padrao
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO               */
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    /* Escreve os atributos da imagem */
    /* Tipo da imagem: P2 significa pgm*/
    printf("P2\n");
    /* Dimensoes e intensidade maxima da imagem */
    printf("%d %d %d\n", W, H, MaxV);

    /* Escreve os pixels da imagem */
    for (i = 0; i < H; i++) {
        printf("%d", img[i][0]);
        for (j = 1; j < W; j++) {
            printf(" %d", img[i][j]);
        }
        printf("\n");
    }
}

/* Negativo */
void negativo(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    for(i=0; i<H; i++)
        for(j=0; j<W; j++)
            img[i][j] = MaxV - img[i][j];
}

/* Rotacao de 180 graus */
void rotacao180(int img[][MAX_TAM], int W, int H) {
    int aux, i, j;

    /*decrementa as posições para começar do 0*/
    W--;
    H--;

    for(i=0; i<=H/2; i++)
    {
        for(j=0; j<=W; j++)
            {
                aux = img[H-i][W-j];/*troca as posições diametralmente opostas*/
                img[H-i][W-j] = img[i][j];
                img[i][j] = aux;
            }
    }

    if((H+1)%2)/*quando for um numero impar de linhas*/
    {
        i = H/2;
        for(j=0; j<=W/2; j++)
        {
            aux = img[i][W-j];
            img[i][W-j] = img[i][j];
            img[i][j] = aux;
        }
    }
}

/* Deteccao de bordas */
void detectaBorda(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j, aux, img_aux[MAX_TAM][MAX_TAM];

    for(i=1; i<H-1; i++)
    {
        for(j=1; j<W-1; j++)
        {
            aux = ( (-1 * img[i-1][j-1]) + (-4 * img[i][j-1]) +
                    (-1 * img[i+1][j-1]) + (-4 * img[i-1][j]) +
                    (20 * img[i][j])     + (-4 * img[i+1][j]) +
                    (-1 * img[i-1][j+1]) + (-4 * img[i][j+1]) +
                    (-1 * img[i+1][j+1]) );/*aplica o filtro de borda*/
            /*verifica se está fora do intervalo e atribui o valor correto*/
            if(aux < 0)
                img_aux[i][j] = 0;
            else if(aux > MaxV)
                img_aux[i][j] = MaxV;
            else/*se estiver dentro do intervalo*/
                img_aux[i][j] = aux;
        }
    }
        for(i=1; i<H-1; i++)
            for(j=1; j<W-1; j++)
                img[i][j] = img_aux[i][j];
}

/* Cisalhamento */
void cisalhamento(int img[][MAX_TAM], int W, int H, double Px, double Py) {
    int i, j, x, y, img_aux[MAX_TAM][MAX_TAM];

    for(i=0; i<H; i++)
        for(j=0; j<W; j++)
            img_aux[i][j] = 0;/*cria uma matriz auxiliar com 0, sendo assim a posição
                                em que nao houver sido colocado nada ficara com 0*/

    for(i=0; i<H; i++)
    {
        for(j=0; j<W; j++)
        {
            x = i + j*Py;
            y = j + i*Px;

            if(x < H && y < W)/*se esta dentro do limite*/
                img_aux[x][y] = img[i][j];
        }
    }

    for(i=0; i<H; i++)
        for(j=0; j<W; j++)
            img[i][j] = img_aux[i][j];/*copia a resposta para a imagem*/
}


/* VOCE NAO DEVE ALTERAR A FUNCAO PRINCIPAL */
int main() {
    /* Matriz que armazena os pixels da imagem */
    int img[MAX_TAM][MAX_TAM];
    /* Atributos da imagem */
    int W, H, MaxV;
    /* Identificador do filtro a ser utilizado */
    int F;
    /* Parametro a ser passado para o cisalhamento */
    double Px, Py;

    /* Le a imagem */
    if (ler_pgm(img, &W, &H, &MaxV, &F, &Px, &Py) != 1) {
        printf("Error: nao foi possivel ler a imagem\n");
        return 0;
    }

    /* Seleciona o filtro */
    switch (F) {
        case 1:
            negativo(img, W, H, MaxV);
            break;
        case 2:
            rotacao180(img, W, H);
            break;
        case 3:
            detectaBorda(img, W, H, MaxV);
            break;
        case 4:
            cisalhamento(img, W, H, Px, Py);
            break;
    }

    /* Escreve a imagem */
    escrever_pgm(img, W, H, MaxV);

    return 0;
}
