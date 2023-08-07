#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TaTeTi.h"

void msgIni()
{
    printf("\n*******************************\n");
    printf("*        \\--WELCOME!!--/      *\n");
    printf("*         \\   O    O  /       *\n");
    printf("*          \\    ^    /        *\n");
    printf("*           \\  ___  /         *\n");
    printf("*           /       \\         *\n");
    printf("*          /         \\        *\n");
    printf("*******************************\n\n");

    system("pause");
}

int menu()
{
    int op;
    system("cls");
    do{
        printf("-------BIENVENIDO AL JUEGO DE TATETI:-------\n");

        printf("UN JUGADOR -----> 1\n");
        printf("DOS JUGADORES --> 2\n");
        printf("SALIR ----------> 0\n");
        printf("Ingrese la opcion: ");
        scanf("%d", &op);

        if (op<0 || op>2)
            printf("Opcion no valida. Reingresar\n");
    }while(op<0 || op>2);
    return op;
}






void inicializarTablero(char tablero[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}


void imprimirTablero(char tablero[FILAS][COLUMNAS])
{
    printf("\n");

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf(" %c ", tablero[i][j]);
            if (j < COLUMNAS - 1)
                printf("|");
        }
        printf("\n");
        if (i < FILAS - 1)
            printf("---+---+---\n");
    }
    printf("\n");
}


char verificarGanador(char tablero[FILAS][COLUMNAS])
{

    for (int i = 0; i < FILAS; i++)
    {
        if (tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2])
            return tablero[i][0];
    }


    for (int j = 0; j < COLUMNAS; j++)
    {
        if (tablero[0][j] == tablero[1][j] && tablero[0][j] == tablero[2][j])
            return tablero[0][j];
    }

    if (tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2])
        return tablero[0][0];

    if (tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])
        return tablero[0][2];

    return ' ';
}


int tableroLleno(char tablero[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (tablero[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void jugarMaquina(char tablero[FILAS][COLUMNAS])
{
    int fila, columna;
    do {
        fila = rand() % FILAS;
        columna = rand() % COLUMNAS;
    } while (tablero[fila][columna] != ' ');

    tablero[fila][columna] = 'O';
}

void jugarJugador(char tablero[FILAS][COLUMNAS], char jugadorActual)
{
    int fila, columna;
    printf("Turno del Jugador %c. Ingrese fila (1-3) y columna (1-3) separados por espacio: ", jugadorActual);
    scanf("%d %d", &fila, &columna);

    fila--;
    columna--;

    if (tablero[fila][columna] == ' ')
        tablero[fila][columna] = jugadorActual;
    else {
        printf("¡Casilla ocupada! Intente nuevamente.\n");
        jugarJugador(tablero, jugadorActual);
    }
}
