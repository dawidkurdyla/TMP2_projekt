/*-------------------------------------------------------------------------
					This file is a part of the Technika Mikroprocesorowa 2 Projekt
----------------------------------------------------------------------------*/

/**
 * @file klawiatura.h
 * @author Kurdyla & Jatczyszyn
 * @date Styczen 2021
 * @brief Plik zawiera deklaracje funkcji oraz makr dla Klawiatura.c
 * @ver 1.0
*/

//#include "GlobalVariables.h"
#ifndef KLAW_H
#define KLAW_H

#include "MKL05Z4.h"

//Zdefiniowanie wlasnych masek dla odpowiednich pinów i przycisków
#define Sw1	7							// Numer bitu dla klawisza S1
#define Sw2	10						// Numer bitu dla klawisza S2
#define Sw3	11						// Numer bitu dla klawisza S3
#define Sw4	12						// Numer bitu dla klawisza S4

void Klaw_Init(void);

#endif  /* KLAW_H */
