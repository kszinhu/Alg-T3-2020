/*
FUNCOES [\] AlgI - T2 - 2020
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

int setcolor (char color){
	HANDLE h;
	h = GetStdHandle (STD_OUTPUT_HANDLE);
	return SetConsoleTextAttribute (h,color);
    /* Função pega na Internet -- */
}
/* >>>>>>>>>>>>>>>>>>>>>>>>> */
void tela_inicio(){
    system("title ALG1-T3-2020");
    printf("\t.----------------------------------------------------------------------------------.\n");
    printf("\t|                                  ");
    setcolor(9);
    printf(" TRABALHO JOGOS");
    setcolor(7);
    printf("                                 |\n");
    printf("\t|                          ------------------------------                          |\n");
    printf("\t|                         ________________________________                         |\n");
    printf("\t|                        |   TEMA: JOGOS                  |                        |\n");
    printf("\t|                        |      DESENVOLVIDO POR          |                        |\n");
    printf("\t|                        |         CASSIANO RODRIGUES     |                        |\n");
    printf("\t|                        |         JOAO PEDRO RODRIGUES   |                        |\n");
    printf("\t|                        |________________________________|                        |\n");
    printf("\t|                                                                                  |\n");
    printf("\t`----------------------------------------------------------------------------------`\n");
    printf("\t                                 < Digite seu nome >                               \n");
    printf("\t                              ->  ");
    setcolor(2);
    /* gets(nome); */
    setcolor(7);
}

main(){
    tela_inicio();
    /* exit(0); */
    system("pause");
}