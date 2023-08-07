#ifndef TATETI_H_INCLUDED
#define TATETI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define FILAS 3
#define COLUMNAS 3

void msgIni();
int menu();

void inicializarTablero(char tablero[FILAS][COLUMNAS]);
void imprimirTablero(char tablero[FILAS][COLUMNAS]);
char verificarGanador(char tablero[FILAS][COLUMNAS]);
int tableroLleno(char tablero[FILAS][COLUMNAS]);

void jugarMaquina(char tablero[FILAS][COLUMNAS]);
void jugarJugador(char tablero[FILAS][COLUMNAS], char jugadorActual);

#endif // TATETI_H_INCLUDED
