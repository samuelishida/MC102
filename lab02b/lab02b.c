#include <stdio.h>

/*
    RA: 160250
    Nome: Samuel Toyoshi Ishida
*/

int main()
{
    const int Pedra = 1;
    const int Papel = 2;
    const int Tesoura = 3;
    const int Lagarto = 4;
    const int Spock = 5;

    struct
    {
        int in;
        int score;
    }sh, leo;

    int n, i;

    sh.score = leo.score = 0;

    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d %d",&sh.in,&leo.in);

      /*• Tesoura corta Papel
        • Papel embrulha Pedra
        • Pedra amassa Lagarto
        • Lagarto envenena Spock
        • Spock quebra Tesoura
        • Tesoura decepa Lagarto
        • Lagarto come Papel
        • Papel refuta Spock
        • Spock vaporiza Pedra
        • Pedra quebra Tesoura */

        if(sh.in == leo.in)
            printf("Empate\n");

        /* testando quando sheldon escolhe pedra*/

        else if(sh.in == Pedra && leo.in == Papel){
            printf("Leonard: Papel embrulha Pedra\n");
            leo.score++;
        }
        else if(sh.in == Pedra && leo.in == Tesoura){
            printf("Sheldon: Pedra quebra Tesoura\n");
            sh.score++;
        }
        else if(sh.in == Pedra && leo.in == Lagarto){
            printf("Sheldon: Pedra amassa Lagarto\n");
            sh.score++;
        }
        else if(sh.in == Pedra && leo.in == Spock){
            printf("Leonard: Spock vaporiza Pedra\n");
            leo.score++;
        }

        /* testando quando sheldon escolhe papel*/

        else if(sh.in == Papel && leo.in == Pedra){
            printf("Sheldon: Papel embrulha Pedra\n");
            sh.score++;
        }
        else if(sh.in == Papel && leo.in == Tesoura){
            printf("Leonard: Tesoura corta Papel\n");
            leo.score++;
        }
        else if(sh.in == Papel && leo.in == Lagarto){
            printf("Leonard: Lagarto come Papel\n");
            leo.score++;
        }
        else if(sh.in == Papel && leo.in == Spock){
            printf("Sheldon: Papel refuta Spock\n");
            sh.score++;
        }

        /* testando quando sheldon escolhe tesoura*/

        else if(sh.in == Tesoura && leo.in == Pedra){
            printf("Leonard: Pedra quebra Tesoura\n");
            leo.score++;
        }
        else if(sh.in == Tesoura && leo.in == Papel){
            printf("Sheldon: Tesoura corta Papel\n");
            sh.score++;
        }
        else if(sh.in == Tesoura && leo.in == Lagarto){
            printf("Sheldon: Tesoura decepa Lagarto\n");
            sh.score++;
        }
        else if(sh.in == Tesoura && leo.in == Spock){
            printf("Leonard: Spock quebra Tesoura\n");
            leo.score++;
        }

        /* testando quando sheldon escolhe lagarto*/

        else if(sh.in == Lagarto && leo.in == Pedra){
            printf("Leonard: Pedra amassa Lagarto\n");
            leo.score++;
        }
        else if(sh.in == Lagarto && leo.in == Papel){
            printf("Sheldon: Lagarto come Papel\n");
            sh.score++;
        }
        else if(sh.in == Lagarto && leo.in == Tesoura){
            printf("Leonard: Tesoura decepa Lagarto\n");
            leo.score++;
        }
        else if(sh.in == Lagarto && leo.in == Spock){
            printf("Sheldon: Lagarto envenena Spock\n");
            sh.score++;
        }


        /* testando quando sheldon escolhe spock*/

        else if(sh.in == Spock && leo.in == Pedra){
            printf("Sheldon: Spock vaporiza Pedra\n");
            sh.score++;
        }
        else if(sh.in == Spock && leo.in == Papel){
            printf("Leonard: Papel refuta Spock\n");
            leo.score++;
        }
        else if(sh.in == Spock && leo.in == Tesoura){
            printf("Sheldon: Spock quebra Tesoura\n");
            sh.score++;
        }
        else if(sh.in == Spock && leo.in == Lagarto){
            printf("Leonard: Lagarto envenena Spock\n");
            leo.score++;
        }
    }

    printf("Sheldon %d x %d Leonard\n",sh.score,leo.score);

    return 0;
}

