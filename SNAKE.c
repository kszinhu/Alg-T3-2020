//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>

//DEFINES
#define BAIXO 80
#define CIMA 72
#define DIREITA 77
#define ESQUERDA 75
#define ENTER 13

void setcolor(int color)
{ //função para as cores
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, color);
    return;
}
/* >>----<< */
void gotoxy(int w, int z)
{ //função para usar o gotoxy
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){w - 1, z - 1});
}
/* >>----<< */
void show_console_cursor(bool show)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}
/* >>----<< */
void caixa()
{ //função pra o limite da caixa do jogo
    int x;
    setcolor(2);
    for (x = 2; x < 22; x++)
    {
        gotoxy(2, x);
        printf("%c", 219);
    }
    for (x = 2; x < 74; x++)
    {
        gotoxy(x, 22);
        printf("%c", 219);
    }
    for (x = 2; x < 23; x++)
    {
        gotoxy(74, x);
        printf("%c", 219);
    }
    for (x = 2; x < 74; x++)
    {
        gotoxy(x, 2);
        printf("%c", 219);
    }
    printf("\n\n\n\n\n\n\n\n\n");
    setcolor(7);
}
/* >>----<< */
void face()
{ //interface do jogo
    int x;

    //Capa do jogo
    setcolor(2);
    for (x = 2; x < 22; x++)
    {
        gotoxy(10, x);
        printf("%c", 219);
    }
    for (x = 10; x < 110; x++)
    {
        gotoxy(x, 22);
        printf("%c", 219);
    }
    for (x = 2; x < 23; x++)
    {
        gotoxy(110, x);
        printf("%c", 219);
    }
    for (x = 10; x < 110; x++)
    {
        gotoxy(x, 2);
        printf("%c", 219);
    }
    setcolor(6);
    gotoxy(32, 8);
    printf(" .d8888b.  888b    888        d8888 888    d8P  8888888888\n");
    gotoxy(32, 9);
    printf("d88P  Y88b 8888b   888       d88888 888   d8P   888\n");
    gotoxy(32, 10);
    printf("Y88b.      88888b  888      d88P888 888  d8P    888\n");
    gotoxy(32, 11);
    printf("  Y888b.   888Y88b 888     d88P 888 888d88K     8888888\n");
    gotoxy(32, 12);
    printf("     Y88b. 888 Y88b888    d88P  888 8888888b    888\n");
    gotoxy(32, 13);
    printf("       888 888  Y88888   d88P   888 888  Y88b   888\n");
    gotoxy(32, 14);
    printf("Y88b  d88P 888   Y8888  d8888888888 888   Y88b  888\n");
    gotoxy(32, 15);
    printf("   Y8888P  888    Y888 d88P     888 888    Y88b 8888888888\n");

    //menu
    setcolor(7);
    gotoxy(53, 25);
    putchar('>');
    gotoxy(54, 25);
    printf("JOGAR\n");
    gotoxy(54, 26);
    printf("SAIR\n\n\n");

    int tecla, a = 53, b = 25;

    do
    { //DO do menu principal
        tecla = getch();

        switch (tecla)
        {

        case BAIXO:
            gotoxy(a, b);
            putchar(' ');
            if (b == 26)
            {
                b = 25;
            }
            else
                (b++);
            gotoxy(a, b);
            putchar('>');
            break;

        case CIMA:
            gotoxy(a, b);
            putchar(' ');
            if (b == 25)
            {
                b = 26;
            }
            else
                (b--);
            gotoxy(a, b);
            putchar('>');
            break;

        case ENTER:
            switch (b)
            {

            case 25:
                system("cls");
                jogo();
                tecla = 1;
                break;

            case 26:
                system("cls");
                gotoxy(5, 5);
                printf("OBRIGADO POR JOGAR :)");
                gotoxy(5, 8);
                printf("Jogo feito pelos alunos Jo%co Pedro e Cassiano, alunos do Curso de BCC da UNESP-Bauru.", 198);
                gotoxy(5, 15);
                tecla = 1;
                break;
            }

        default:
            break;
        }
    } while (tecla != 1);
}
/* >>----<< */
void jogo()
{ //jogo em si

    int p = 37, r = 11, jg = 'h', d = 2;                      //gotoxy e variáveis do jogo
    int pontos = 1, velo = 150, velop = 0;                    //marcação
    int pm, rm, cp[300] = {5, 5}, cr[300] = {9, 9}, t = 1, x; //dimensões dos elementos
    int m = 2, n = 2;                                         //condições do while
    int i = 4, j = 9, op;                                     //gotoxy do final do jogo

    caixa(); //chama a função que delimita o espaço do jogo

    //cria uma coordenada p/ comida inicial
    pm = (rand() % 58) + 3;
    rm = (rand() % 12) + 3;

    while (jg != 's')
    { //while que funciona o jogo

        while (jg != 's' && !(jg = kbhit()))
        {
            for (x = t; x > 0; x--)
            { //for da cobrinha
                cp[x] = cp[x - 1];
                cr[x] = cr[x - 1];
            }
            //movimentos da cobrinha
            if (d == 0)
                cr[0]--; /*Diminui o coeficiente X*/
            if (d == 1)
                cp[0]--; /*Diminui o coeficiente Y*/
            if (d == 2)
                cr[0]++; /*Aumenta o coeficiente X*/
            if (d == 3)
                cp[0]++; /*Aumenta o coeficiente Y*/

            //apaga o caractere
            gotoxy(cp[t], cr[t]);
            putchar(' ');

            if (pm == cp[0] && rm == cr[0])
            { //if quando o jogador pegar uma comida
                //aumenta o tamanho
                t++;
                //aumenta a pontuação
                pontos++;
                //gera uma nova comida
                pm = (rand() % 58) + 3;
                rm = (rand() % 12) + 3;
                //aumenta a velocidade
                velo -= 5;
                velop += 10;
            }

            gotoxy(cp[0], cr[0]);
            printf("%c", 219); /* COBRINHA */
            
            gotoxy(pm, rm);
            setcolor(4);
            printf("%c", 208); /* MACA */
            setcolor(7);

            //informações que ficam do lado da tela
            gotoxy(80, 8);
            printf("VELOCIDADE: %d", velop);
            gotoxy(80, 10);
            printf("Pontua%c%co: %d", 135, 198, pontos - 1);
            gotoxy(80, 12);
            printf("%cUse as setinhas do teclado para", 42);
            gotoxy(80, 13);
            printf("controlar a cobrinha.");
            gotoxy(80, 15);
            printf("%cTente pegar o m%cximo de comidas que", 42, 160);
            gotoxy(80, 16);
            printf("conseguir e evite bater nas paredes e");
            gotoxy(80, 17);
            printf("tamb%cm em voc%c mesmo.", 136, 136);
            gotoxy(80, 18);
            printf("TENHA UM BOM JOGO :)");

            //
            Sleep(velo);

            //condições para perder o jogo
            for (x = 1; x < t; x++)
            {
                if (cp[0] == cp[x] && cr[0] == cr[x])
                    jg = 's';
            }
            if (cr[0] == 2 || cr[0] == 22 || cp[0] == 2 || cp[0] == 74)
                jg = 's';
        }
        if (jg != 's') //movimentação da cobrinha
            jg = getch();
        if (jg == CIMA)
            d = 0;
        if (jg == ESQUERDA)
            d = 1;
        if (jg == BAIXO)
            d = 2;
        if (jg == DIREITA)
            d = 3;
        if (cr[0] == 2 || cr[0] == 22 || cp[0] == 2 || cp[0] == 74)
            jg = 's'; /* Perde o jogo se encostar nas paredes */
    }

    //tela pós-jogo
    system("cls");
    system("title VOCE PERDEU - SNAKE");
    gotoxy(5, 5);
    setcolor(2);
    printf("Voc%c perdeu, sua pontua%c%co foi de: ", 136, 135, 198);
    setcolor(7);
    printf("%d.", pontos - 1);
    setcolor(2);
    gotoxy(5, 7);
    printf("O que deseja fazer agora?");
    gotoxy(5, 9);
    printf("Jogar novamente.");
    gotoxy(5, 10);
    printf("Sair do jogo.");
    setcolor(7);

    //DO das opções no final do jogo
    do
    {
        op = getch();

        switch (op)
        {

        case BAIXO:
            gotoxy(i, j);
            putchar(' ');
            if (j == 10)
            {
                j = 9;
            }
            else
                (j++);
            gotoxy(i, j);
            putchar('>');
            break;

        case CIMA:
            gotoxy(i, j);
            putchar(' ');
            if (j == 9)
            {
                j = 10;
            }
            else
                (j--);
            gotoxy(i, j);
            putchar('>');
            break;

        case ENTER:
            switch (j)
            {

            case 9:
                system("cls");
                jogo();
                break;

            case 10:
                system("cls");
                gotoxy(5, 5);
                printf("OBRIGADO POR JOGAR :)");
                gotoxy(5, 8);
                printf("Jogo feito pelos alunos Jo%co Pedro e Cassiano, alunos do Curso de BCC da UNESP-Bauru.", 198);
                gotoxy(5, 12);
                getch();
                n = 1;
                break;
            }
        default:
            break;
        }
    } while (n != 1);
}

main()
{
    srand(time(NULL));
    system("MODE con cols=120 lines=30 ");
    show_console_cursor(false);
    system("title JOGANDO - SNAKE");

    face();

    system("pause");
}