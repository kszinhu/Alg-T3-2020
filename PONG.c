/*
PONG [\] AlgI - T3 - 2020
> Cassiano Rodrigues
> 13/07/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <process.h>
#include <windows.h>

#define MAX 100
#define ESC 27
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define F6 64
#define F7 65
#define F8 66
#define F9 67
#define F10 68
#define F11 133
#define F12 134
// '0' (F1>F10) [] '224' (F11-F12)
#define BAIXO 80
#define CIMA 72
#define ENTER 13
#define DIREITA 77
#define ESQUERDA 75
#define W 87
#define S 83

char nome[50];
char array[80][80] = {"vai ficar aqui os #"};
/* ---------------- */
void show_console_cursor(bool show)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}
/* ----------------- */
int setcolor(char color)
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h, color);
    /* Função pega na Internet -- */
}
/* ----------------- */
void APAGAR(int xmin, int xmax, int ymin, int ymax)
{
    int i, j;
    for (i = xmin; i <= xmax; i++)
    {
        for (j = ymin; j < ymax; j++)
        {
            gotoxy(xmin + i, ymin + j);
            putchar(' ');
        }
    }
    gotoxy(1, 1);
}
/* ----------------- */
void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x - 1, y - 1});
    /* Função pega na Internet */
}
/* ----------------- */
void caixa(int xmin, int xmax, int ymin, int ymax)
{
    setcolor(1);
    int i, j;
    gotoxy(xmin, ymax);
    for (i = xmin; i <= xmax; i++)
    {
        printf("%c", 205);
    }
    for (i = 1; i < (ymax - 1); i++)
    {
        if (i == 1)
        {
            gotoxy(xmin - 1, ymin);
            printf("%c", 201);
        }
        if (i == (ymax - 2))
        {
            gotoxy(xmax + 1, ymin);
            printf("%c ", 187);
        }
        gotoxy((xmin - 1), (ymin + i));
        printf("%c", 186);
    }
    for (i = 1; i < (ymax - 1); i++)
    {
        if (i == 1)
        {
            gotoxy(xmin - 1, ymax);
            printf("%c", 200);
        }
            gotoxy((xmax + 1), (ymin + i));
            printf("%c", 186);
        if (i == (ymax - 2))
        {
            gotoxy((xmax+1), ymax);
            printf("%c", 188);
        }
    }
    gotoxy(xmin, ymin);
    for (i = xmin; i <= xmax; i++)
    {
        printf("%c", 205);
    }
    setcolor(7);
}
/* ----------------- */
void PONG(int x, int y)
{
    gotoxy(x, y);
    printf(" %c%c%c%c%c    %c%c%c%c   %c%c  %c%c   %c%c%c%c%c \n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    y++;
    gotoxy(x, y);
    printf(" %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c     \n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    y++;
    gotoxy(x, y);
    printf(" %c%c  %c%c  %c%c  %c%c  %c%c%c %c%c  %c%c     \n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    y++;
    gotoxy(x, y);
    printf(" %c%c%c%c%c   %c%c  %c%c  %c%c %c%c%c  %c%c %c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    y++;
    gotoxy(x, y);
    printf(" %c%c      %c%c  %c%c  %c%c  %c%c  %c%c   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    y++;
    gotoxy(x, y);
    printf(" %c%c       %c%c%c%c   %c%c  %c%c   %c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
}
/* >>>>>>>>>>>>>>>>>>>>>>>>> */
void controles()
{
    int tecla, x = 11, y = 3;
    int x_ = 59, y_ = 3;
    do
    {
        tecla = getch(); //capturamos a tecla digitada
        tecla = toupper(tecla);
        switch (tecla)
        {
        case BAIXO:       /* > Se pressionarmos a tecla seta para BAIXO < */
            gotoxy(x, y); /* > Movendo no eixo X(VAR) */
            putchar(' ');
            if (y == 19)
            {          /* > Ele testa se estamos na posição 14 no eixo y < */
                y = 3; /* > Se sim retornamos a posição 7 < */
            }
            else
            {
                y++; /* > vamos mais para baixo <*/
            }
            gotoxy(x, y);
            printf("%c", 219); /* > Imprime um cursor para nos localizarmos < */
            break;

        case CIMA: /* > Se pressionarmos a tecla seta para CIMA < */
            gotoxy(x, y);
            putchar(' ');
            if (y == 3)
            {           /* > Se estamos na posição 7 < */
                y = 19; /* > Se sim vamos para a posição 14 < */
            }
            else
            {
                y--; /* > Vamos para cima < */
            }
            gotoxy(x, y);
            printf("%c", 219);
            break;
        case S:             /* > Se pressionarmos a tecla seta S < */
            gotoxy(x_, y_); /* > Movendo no eixo X(VAR) */
            putchar(' ');
            if (y_ == 19)
            {           /* > Ele testa se estamos na posição 15 no eixo y < */
                y_ = 3; /* > Se sim retornamos a posição 12 < */
            }
            else
            {
                y_++; /* > vamos mais para baixo <*/
            }
            gotoxy(x_, y_);
            printf("%c", 219); /* > Imprime um cursor para nos localizarmos < */
            break;

        case W: /* > Se pressionarmos a tecla W < */
            gotoxy(x_, y_);
            putchar(' ');
            if (y_ == 3)
            {            /* > Se estamos na posição 12 < */
                y_ = 19; /* > Se sim vamos para a posição 18 < */
            }
            else
            {
                y_--; /* > Vamos para cima < */
            }
            gotoxy(x_, y_);
            printf("%c", 219);
            break;
        default:
            break;
        }
    } while (tecla != ESC);
}
void musica()
{
#define A3 110.0
#define C4 130.8
#define D4 146.9
#define G3 98.0
#define H3 123.5
#define F3 87.4
#define A4 261.0
#define G4 196.0
#define C5 291.6
#define E4 164.9
#define E5 349.6
#define Bb4 233.1
    for (;;)
    {
        Beep(C5, 250);
        Beep(C5, 250);
        Beep(Bb4, 250);
        Beep(Bb4, 250);
        Beep(C5, 250);
        Beep(C5, 250);
        Beep(E5, 250);
        Beep(E5, 250);
        Beep(E5, 250);
        Beep(E5, 250);
        Beep(E5, 250);
        Beep(E5, 250);
        Beep(C5, 250);
        Beep(C5, 250);
        Beep(E5, 250);
        Beep(A4, 250);
        Beep(A4, 250);
        Beep(G4, 250);
        Beep(G4, 250);
        Beep(A4, 250);
        Beep(A4, 250);
        Beep(C5, 250);
        Beep(C5, 250);
        Beep(E5, 250);
        Beep(E5, 250);
        Beep(C5, 250);
        Beep(A4, 250);
        Beep(A4, 250);
        Beep(E5, 250);
        Beep(A4, 250);
    }
}
main()
{
    int i, j, pontosB = 0, pontosA = 0;
    show_console_cursor(false);
    caixa(10, 60, 2, 20);
    gotoxy(46, 11);
    printf("%c", 254); /* BOLINHA */
    PONG(19, 22);
    caixa(8, 62, 1, 29);
    _beginthread(musica, 0, NULL);
    system("title GAME PONG");        /* Titulo da janela do console */
    _beginthread(controles, 0, NULL); /* Nao pode deixar pressionado uma tecla apenas */
    for (i = 0;; i++)                 /* Deixar rodando infinitamente a MAIN */
    {
        Sleep(10000);
    }
    system("pause");
}