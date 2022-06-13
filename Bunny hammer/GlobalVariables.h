/*-------------------------------------------------------------------------
					This file is a part of the Technika Mikroprocesorowa 2 Projekt
----------------------------------------------------------------------------*/


#include "MKL05Z4.h"
#include "frdm_bsp.h"

#ifndef GLOBAL_H
#define GLOBAL_H

//Maski dla pinów klawiatury
#define S1_MASK	(1<<7)		// Maska dla klawisza S1
#define S2_MASK	(1<<10)		// Maska dla klawisza S2
#define S3_MASK	(1<<11)		// Maska dla klawisza S3
#define S4_MASK	(1<<12)		// Maska dla klawisza S4

//Tablica sygnalizujaca który przycisk zostal nacisniety
// "1" - klawisz zostal wcisniety "0" - klawisz "skonsumowany"
volatile extern uint8_t S_pressed[4];	

//Zmienna symbolizujaca przerwanie od klawiatury
volatile extern uint8_t KeyPressed;

//Bufor wyswietlajac
char extern display[];

//Ilosc zliczen licznika
int extern counter;

int extern speed;

//Sygnalizacja czy wyswietlony "królik" zostal zabity
int extern killed;

//Wylosowana wartosc okreslajaca pozycje "królika"
int extern BunnyPos;

//Wynik gracza
int extern score;

//Zycia gracza
int extern lifes;

//Zliczenie zostalo skonsumowane przez petle
int extern counted;

//Czy zliczenie zostalo "skonsumowane"
int extern sekunda_OK;

//Licznik zliczen licznika SysTick
int extern sekunda;

#endif  /* GLOBAL_H */
