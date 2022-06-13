#include "MKL05Z4.h"
#include "frdm_bsp.h"
#include "klawiatura.h"
#include "uart0.h"
#include "GlobalVariables.h"

#ifndef RUN_H
#define RUN_H

//Do obslugi wyswietlania na terminalu
#define ASCII_ESC 27 

//Zasadnicza funkcja programu
void Run(void);

//Menu glówne programu
void DisplayManu(void);

//Lista najlepszych wyników
void DisplayBest(void);


#endif  /* RUN_H */
