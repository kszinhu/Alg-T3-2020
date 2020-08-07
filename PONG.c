/*
FUNCOES [\] AlgI - T3 - 2020
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
#define ESPACO 32
#define W 87
#define S 83

/* -------- GLOBAL --------- */
char nome[50];
float vx = 2;
float vy = 1;
int dificuldade = 1;
int modo = 1;
bool thread_controller = true;
bool thread_controller1 = true;
bool thread_controller_mtela = true;
bool thread_controller_controles = true;

int x = 11, y = 11;
int x_ = 59, y_ = 11;
int placarA = 0, placarB = 0;

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x - 1, y - 1});
    /* Função pega na Internet */
}
/* ------------------------ */
int setcolor(char color)
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h, color);
    /* Função pega na Internet -- */
}
/* ------------------------ */
void preenchimento(int xmin, int xmax, int ymin, int ymax, int cor)
{
    int i, j;
    setcolor(cor);
    gotoxy(xmin, ymax);
    for (i = xmin; i < (xmax); i++)
    {
        printf("%c", 219);
    }
    for (i = 1; i < (ymax); i++)
    {
        gotoxy((xmin), (ymin + i));
        for (j = 0; j < (xmax - xmin); j++)
        {
            printf("%c", 219);
        }
    }
    setcolor(7);
    gotoxy(1, 1);
}
/* ------------------------ */
void APAGAR(int xmin, int xmax, int ymin, int ymax)
{
    int i, j;
    for (i = xmin; i <= ymax; i++)
    {
        for (j = ymin; j <= xmax; j++)
        {
            gotoxy(xmin + j, ymin + i);
            printf("%c", 0);
        }
    }
    gotoxy(1, 1);
}
/* ------------------------ */
void movimento_bola()
{
    int bx = 35, by = 5;
    gotoxy(70, 7);
    setcolor(3);
    printf("%d", placarA);
    gotoxy(74, 7);
    setcolor(7);
    printf("x");
    setcolor(4);
    gotoxy(78, 7);
    printf("%d", placarB);
    for (;;)
    {
        if ((placarB == 5) || (placarA == 5))
        {
            break;
        }
        else
        {
            bx += vx;
            by += vy;
            if (bx <= 9 || bx >= 61)
            {
                /* marcar_gol */
                if (bx <= 10)
                {
                    placarB++;
                    gotoxy(70, 7);
                    setcolor(3);
                    printf("%d", placarA);
                    gotoxy(74, 7);
                    setcolor(7);
                    printf("x");
                    setcolor(4);
                    gotoxy(78, 7);
                    printf("%d", placarB);
                }
                if (bx >= 60)
                {
                    placarA++;
                    gotoxy(70, 7);
                    setcolor(3);
                    printf("%d", placarA);
                    gotoxy(74, 7);
                    setcolor(7);
                    printf("x");
                    setcolor(4);
                    gotoxy(78, 7);
                    printf("%d", placarB);
                }
                setcolor(7);
                vx = -vx;
                by = 4;
                bx = 34;
            }
            if (by <= 3 || by >= 19)
            {
                gotoxy(bx, by);
                putchar(' ');
                vy = -vy;
            }
            else
            {
                if (((bx == 12) || (bx == 13)) && ((by == y) || (by == y - 2) || (by == y - 1) || (by == y + 2) || (by == y + 1)))
                {
                    vx = -vx;
                }

                if ((bx == 58) && ((by == y_) || (by == y_ - 2) || (by == y_ - 1) || (by == y_ + 1) || (by == y_ + 2)))
                {
                    vx = -vx;
                }
            }
            setcolor(10);
            gotoxy(bx, by);
            printf("%c", 254); /* BOLINHA */
            Sleep(100);
            gotoxy(bx, by);
            putchar(' ');
            setcolor(7);
        }
    }
    system("cls");
    thread_controller = false;
    thread_controller1 = false;
    thread_controller_controles = false;
    main_pong();
}
/* ------------------------ */
void show_console_cursor(bool show)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}
/* ------------------------ */
void caixa(int xmin, int xmax, int ymin, int ymax, int cor)
{
    setcolor(cor);
    int i, j;
    gotoxy(xmin, ymax);
    for (i = xmin; i <= xmax; i++)
    {
        printf("%c", 205);
    }
    for (i = 0; i <= (ymax - 1); i++)
    {
        if (i == 1)
        {
            gotoxy(xmin - 1, ymin);
            printf("%c", 201);
        }
        if ((ymin + i) <= ymax)
        {
            gotoxy((xmin - 1), (ymin + i));
            printf("%c", 186);
        }
        if (i == (ymax - 2))
        {
            gotoxy(xmax + 1, ymin);
            printf("%c ", 187);
        }
    }
    for (i = 1; i < (ymax - 1); i++)
    {
        if (i == 1)
        {
            gotoxy(xmin - 1, ymax);
            printf("%c", 200);
        }
        if ((ymax - i) >= ymin)
        {
            gotoxy((xmax + 1), (ymin + i));
            printf("%c", 186);
        }
        if (i == (ymax - 2))
        {
            gotoxy((xmax + 1), ymax);
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
/* ------------------------ */
void pong_title(int x, int y)
{
    gotoxy(x, y);
    printf(" %c%c%c%c%c    %c%c%c%c   %c%c  %c%c   %c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    y++;
    gotoxy(x, y);
    printf(" %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    y++;
    gotoxy(x, y);
    printf(" %c%c  %c%c  %c%c  %c%c  %c%c%c %c%c  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
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
/* >>>>>>>>>>>>>>>>>>>>>>>> */
void controles()
{
    thread_controller_controles = true;
    int tecla;
    do
    {
        tecla = getch(); //capturamos a tecla digitada
        tecla = toupper(tecla);
        switch (tecla)
        {
        case BAIXO: /* > Se pressionarmos a tecla seta para BAIXO < */
            gotoxy(x, (y - 1));
            putchar(' ');
            gotoxy(x, y);
            putchar(' ');
            gotoxy(x, (y + 1));
            putchar(' ');
            if (y == 18)
            {          /* > Ele testa se estamos na posição 14 no eixo y < */
                y = 4; /* > Se sim retornamos a posição 7 < */
            }
            else
            {
                y++; /* > vamos mais para baixo <*/
            }
            /* > Imprime CARACTER < */
            setcolor(9);
            gotoxy(x, (y - 1));
            printf("%c", 219);
            gotoxy(x, y);
            printf("%c", 219);
            gotoxy(x, (y + 1));
            printf("%c", 219);
            setcolor(7);
            break;

        case CIMA: /* > Se pressionarmos a tecla seta para CIMA < */
            gotoxy(x, (y - 1));
            putchar(' ');
            gotoxy(x, y);
            putchar(' ');
            gotoxy(x, (y + 1));
            putchar(' ');
            if (y == 4)
            {           /* > Se estamos na posição 7 < */
                y = 18; /* > Se sim vamos para a posição 14 < */
            }
            else
            {
                y--; /* > Vamos para cima < */
            }
            setcolor(9);
            gotoxy(x, (y - 1));
            printf("%c", 219);
            gotoxy(x, y);
            printf("%c", 219);
            gotoxy(x, (y + 1));
            printf("%c", 219);
            setcolor(7);
            break;
        case S: /* > Se pressionarmos a tecla seta S < */
            gotoxy(x_, (y_ - 1));
            putchar(' ');
            gotoxy(x_, y_);
            putchar(' ');
            gotoxy(x_, (y_ + 1));
            putchar(' ');
            if (y_ == 18)
            {           /* > Ele testa se estamos na posição 15 no eixo y < */
                y_ = 4; /* > Se sim retornamos a posição 12 < */
            }
            else
            {
                y_++; /* > vamos mais para baixo <*/
            }
            setcolor(12);
            gotoxy(x_, (y_ - 1));
            printf("%c", 219);
            gotoxy(x_, y_);
            printf("%c", 219);
            gotoxy(x_, (y_ + 1));
            printf("%c", 219);
            setcolor(7);
            break;

        case W: /* > Se pressionarmos a tecla W < */
            gotoxy(x_, (y_ - 1));
            putchar(' ');
            gotoxy(x_, y_);
            putchar(' ');
            gotoxy(x_, (y_ + 1));
            putchar(' ');
            if (y_ == 4)
            {            /* > Se estamos na posição 12 < */
                y_ = 18; /* > Se sim vamos para a posição 18 < */
            }
            else
            {
                y_--; /* > Vamos para cima < */
            }
            setcolor(12);
            gotoxy(x_, (y_ - 1));
            printf("%c", 219);
            gotoxy(x_, y_);
            printf("%c", 219);
            gotoxy(x_, (y_ + 1));
            printf("%c", 219);
            setcolor(7);
            break;
        default:
            break;
        }
    } while (thread_controller_controles);
}
/* ------------------------ */
void tela_configuracoes(y)
{
    if (dificuldade == 1)
    {
        if (y != 18)
        {
            gotoxy(23, 18);
            printf(" NIVEL FACIL   ");
        }
        else if (y == 18)
        {
            gotoxy(24, 18);
            printf(" NIVEL FACIL    ");
        }
        vx = 2;
    }
    else
    {
        if (y != 18)
        {
            gotoxy(23, 18);
            printf(" NIVEL DIFICIL  ");
        }
        else if (y == 18)
        {
            gotoxy(24, 18);
            printf(" NIVEL DIFICIL  ");
        }
        vx = 3;
    }
    if (modo == 1)
    {
        if (y != 19)
        {
            gotoxy(23, 19);
            printf(" MULTIPLAYER   ");
        }
        else if (y == 19)
        {
            gotoxy(24, 19);
            printf(" MULTIPLAYER    ");
        }
        /* alterar variavel aqui */
    }
    else
    {
        if (y != 19)
        {
            gotoxy(23, 19);
            printf(" SINGLEPLAYER  ");
        }
        else if (y == 19)
        {
            gotoxy(24, 19);
            printf(" SINGLEPLAYER  ");
        }
        /* alterar variavel aqui */
    }
    if (y != 20)
    {
        gotoxy(23, 20);
        printf(" VOLTAR  ");
    }
    else if (y == 20)
    {
        gotoxy(24, 20);
        printf(" VOLTAR  ");
    }
    gotoxy(19, 29);
    printf("AO CLICAR NAS OPCOES, MUDA AS CONFIGURACOES");
}
/* ------------------------ */
void configuracoes()
{
    int x = 22, y = 19, tecla, sair = 0;
    APAGAR(13, 68, 16, 29);
    gotoxy(24, 21);
    printf("            "); /* APAGAR AJUDA */
    system("title CONFIGURACOES PONG");
    do
    {
        tela_configuracoes(y);
        tecla = getch();
        switch (tecla)
        {
        case BAIXO:
            gotoxy(x, y);
            putchar(' ');
            if (y == 20)
            {
                y = 18;
            }
            else
            {
                y++;
            }
            gotoxy(x, y);
            putchar('>');
            break;

        case CIMA:
            gotoxy(x, y);
            putchar(' ');
            if (y == 18)
            {
                y = 20;
            }
            else
            {
                y--;
            }
            gotoxy(x, y);
            putchar('>');
            break;
        case ENTER:
            switch (y)
            {
            case 18:
                dificuldade = -dificuldade;

                break;
            case 19:
                modo = -modo;
                break;
            case 20:
                return 0;
                break;
            default:
                break;
            }
            tela_configuracoes();
        }
    } while (1);
}
/* ------------------------ */
void tela_opcoes(y)
{
    gotoxy(24, 16);
    printf("%c UTILIZE AS SETAS DO TECLADO %c", 240, 240);
    if (y != 18)
    {
        gotoxy(24, 18);
        printf("INICIAR O JOGO          ");
    }
    else if (y == 18)
    {
        gotoxy(23, 18);
        printf("  INICIAR O JOGO          ");
    }
    if (y != 19)
    {
        gotoxy(24, 19);
        printf("CONFIGURACOES           ");
    }
    else if (y == 19)
    {
        gotoxy(23, 19);
        printf("  CONFIGURACOES           ");
    }
    if (y != 20)
    {
        gotoxy(24, 20);
        printf("VOLTAR ");
    }
    else if (y == 20)
    {
        gotoxy(23, 20);
        printf("  VOLTAR");
    }
    if (y != 21)
    {
        gotoxy(24, 21);
        printf("AJUDA                   ");
    }
    else if (y == 21)
    {
        gotoxy(23, 21);
        printf("  AJUDA             ");
    }
}
/* ------------------------ */
void menu_opcoes()
{
    int x = 22, y = 18, tecla;
    APAGAR(13, 68, 16, 24);
    gotoxy(x, y);
    putchar('>');
    do
    {
        tela_opcoes(y);
        tecla = getch();
        switch (tecla)
        {
        case BAIXO:
            gotoxy(x, y);
            putchar(' ');
            if (y == 21)
            {
                y = 18;
            }
            else
            {
                y++;
            }
            gotoxy(x, y);
            putchar('>');
            break;

        case CIMA:
            gotoxy(x, y);
            putchar(' ');
            if (y == 18)
            {
                y = 21;
            }
            else
            {
                y--;
            }
            gotoxy(x, y);
            putchar('>');
            break;
        case ENTER:
            switch (y)
            {
            case 18:
                APAGAR(13, 68, 16, 24);
                Sleep(200);
                return 0;
                break;
            case 19:
                configuracoes();
                x = 22;
                y = 20;
                gotoxy(1, 1);
                APAGAR(13, 68, 16, 25);
                Sleep(200);
                /* APAGAR(13, 68, 16, 24);
                gotoxy(24, 18);
                printf("INICIAR O JOGO");
                gotoxy(24, 19);
                printf("CONFIGURACOES");
                gotoxy(24, 20);
                printf("VOLTAR"); 
                */
                gotoxy(19, 29);
                printf("                                        ");
                break;
            case 20:
                thread_controller = false;
                thread_controller1 = false;
                main_pong(); /* RETORNA INTERFACE INICIAL */
                return 0;
                break;
            case 21:
                Sleep(100);
                gotoxy(26, 26);
                printf("[%c] CONTROLES", 158);
                gotoxy(26, 27);
                printf("P1 ---[KEY-UP]--[KEY-DOWN]----");
                gotoxy(26, 28);
                printf("P2 ------[W]-------[S]--------");
                break;
            default:
                break;
            }
        }
    } while (1);
}
/* ------------------------ */
void musica_pong()
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
    while (thread_controller1)
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
/* ------------------------ */
void musica_tela()
{
#define A3 110.0
#define C4 130.8
#define D4 146.9
#define G3 98.0
#define H3 123.5
#define F3 87.4
#define D5 587
#define A4 261.0
#define G4 196.0
#define C5 291.6
#define E4 164.9
#define G5 783
#define E5 349.6
#define Bb4 233.1
#define half 250
    while (thread_controller_mtela)
    {
        Beep(E5, half);
        Beep(D5, half);

        Sleep(400);

        /* Beep(E5, half);
        Beep(E5, half);
        Beep(E5, half);

        Sleep(400); */

        Beep(E5, half);
        Beep(G5, half);
        Beep(C5, half);
        Beep(D5, half);
        Beep(E5, half);

        Beep(C4, half);
        Beep(D4, half);
        Beep(E4, half);

        /* Beep(F5, half);
        Beep(F5, half);
        Beep(F5, half);

        Sleep(400); */

        Beep(F5, half);
        Beep(E5, half);
        Beep(E5, half);

        /* Sleep(400);

        Beep(E5, half);
        Beep(D5, half);
        Beep(D5, half);
        Beep(E5, half);
        Beep(D5, half);
 */
        Sleep(600);
    }
}
/* ------------------------ */
void animacao_barritas()
{
    int x = 17, y = 5, x2 = 64, y2 = 6;
    while (thread_controller)
    {
        y2++;
        y--;
        gotoxy(x2, y2 - 1);
        putchar(' ');
        gotoxy(x2, y2 - 2);
        putchar(' ');
        if (y2 == 12)
        {           /* > Se estamos na posição 7 < */
            y2 = 3; /* > Se sim vamos para a posição 14 < */
        }
        gotoxy(x2, y2);
        printf("%c", 219);
        gotoxy(x2, y2 - 1);
        printf("%c", 219);

        gotoxy(x, y + 1);
        putchar(' ');
        gotoxy(x, y + 2);
        putchar(' ');
        if (y == 1)
        {           /* > Se estamos na posição 7 < */
            y = 10; /* > Se sim vamos para a posição 14 < */
        }
        gotoxy(x, y);
        printf("%c", 219);
        gotoxy(x, y + 1);
        printf("%c", 219);
        Sleep(700);
    }
}
/* ------------------------ */
void tela_pong()
{
    int sair;
    system("title TELA PONG");
    while (1)
    {
        system("cls");
        caixa(16, 65, 1, 12, 9);
        caixa(15, 66, 1, 13, 8);
        caixa(12, 69, 15, 24, 15);
        pong_title(24, 4);
        Sleep(100);
        thread_controller_mtela = true;
        _beginthread(musica_tela, 0, NULL);
        _beginthread(animacao_barritas, 0, NULL);
        Sleep(200);
        gotoxy(32, 14);
        printf("< OP%c%cES DO JOGO >", 128, 229);
        gotoxy(1, 1);
        menu_opcoes();
        thread_controller_mtela = false;
        return 0;
    }
}
/* ------------------------ */
main_pong()
{
    Sleep(300);
    thread_controller_mtela = false;
    thread_controller1 = false;
    thread_controller = true;
    int i = 1, j, pontosB = 0, pontosA = 0, tecla;
    tela_pong();
    system("cls");

    /* teladeloading */
    Sleep(375);

    preenchimento(66, 83, 0, 1, 4);
    caixa(10, 60, 2, 20, 7);
    caixa(8, 62, 1, 29, 8);
    pong_title(19, 22);

    /* JOGO() */
    thread_controller = false;
    thread_controller1 = true;
    _beginthread(movimento_bola, 0, NULL); /* EXECUTAR UMA THREAD SO JUNTO COM OS CONTROLES */
    _beginthread(musica_pong, 0, NULL);

    system("title GAME PONG");        /* Titulo da janela do console */
    _beginthread(controles, 0, NULL); /* Nao pode deixar pressionado uma tecla apenas */
    thread_controller1 = true;
    for (i = 0;; i++) /* Deixar rodando infinitamente a MAIN */
    {
        Sleep(10000);
    }
    system("pause");
}

main()
{
    show_console_cursor(false);
    
    main_pong();
    system("pause");
}