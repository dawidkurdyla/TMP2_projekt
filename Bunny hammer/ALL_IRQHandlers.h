/*-------------------------------------------------------------------------
					This file is a part of the Technika Mikroprocesorowa 2 Projekt
----------------------------------------------------------------------------*/

/**
 * @file ALL_IRQHandlers.h
 * @author Kurdyla & Jatczyszyn
 * @date Styczen 2021
 * @brief Plik zawiera deklaracje funkcji obslugujacych przerwania
 * @ver 1.0
*/

#include "GlobalVariables.h"

//Obsluga przerwan na porcie A od klawiatury
void PORTA_IRQHandler(void);

//Obsluga przerwan od Timera PIT
void PIT_IRQHandler(void);

//Obsluga przerwan od licznika systemowego SysTick
void SysTick_Handler(void);

