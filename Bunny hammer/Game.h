#include "MKL05Z4.h"
#include "frdm_bsp.h"
#include "klawiatura.h"
#include "uart0.h"
#include "GlobalVariables.h"
#include "ALL_IRQHandlers.h"
#include "pit.h"
#include "time.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef GAME_H
#define GAME_H

//Przelacznik, 1 -> przerwa pomiedzy wyswietlaniem, 0-> wyswietlenie królika
int static pause = 1;

//Stan gry 1 -> wciaz trwa, 0 -> koniec gry
int static state = 1;

//Zmienna przechowujaca poprzednia ilosc dziesiatek pkt
int static lastValue = 0;

//Gra -> zwraca "1" jesli trwa "0" jesli zostala zakonczona
void Game(void);

//Funkcja zwiekszajaca predkosc gry o 10ms co 10 pkt
void SetSpeed(void);

//Funkcja sprawdzajaca stan gry
int CheckGameState(void);

//Funkcja weryfikujaca czy wcisniety przycisk odpowiada pozycji królika
int CheckPressed(void);

//Funkcja wyswietlajaca wszystko na ekranie
void DisplayGame(void);

//Funkcja wyswietlajaca punkty oraz ilosc zycia
void DisplayStats(void);

#endif  /* GAME_H */
