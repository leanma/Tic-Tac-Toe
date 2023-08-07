#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TaTeTi.h"


int main()
{
    char tablero[FILAS][COLUMNAS];
    char jugadorActual = 'X';
    char ganador;

    srand(time(0));

    inicializarTablero(tablero);

    msgIni();
    int modo=menu();

    while(modo!=0)
    {
        printf("Jugador 1: X\n");
        if (modo == 1)
            printf("Maquina O\n");
        else {
            printf("Jugador 2: O\n");
        }

       do {
            system("cls");
            imprimirTablero(tablero);

            if (modo == 1 && jugadorActual == 'O')
            {
                jugarMaquina(tablero);
            } else {
                jugarJugador(tablero, jugadorActual);
            }

            ganador = verificarGanador(tablero);
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';

            } while (ganador == ' ' && !tableroLleno(tablero));

            imprimirTablero(tablero);

            if (ganador == 'X')
                printf("Felicidades, el Jugador X ha ganado!\n\n");
            else if (modo == 1 && ganador == 'O')
                printf("La maquina ha ganado!\n\n");
            else if (modo == 2 && ganador == 'O')
                printf("Felicidades, el Jugador O ha ganado!\n\n");
            else {
                printf("Es un empate!\n\n");
            }
            system("pause");
            modo=menu();
            if(modo!=0)
            {
                inicializarTablero(tablero);
                srand(time(0));
            }
    }

    printf("Fin del Programa. ADIOS!!\n");
    return 0;
}

