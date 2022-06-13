
//----------------------------------------------
// SIM_SOPT2
//----------------------------------------------
// Zródlo zegara
//

#include "MKL05Z4.h"
#include "GlobalVariables.h"
#include "stdio.h"
#define MCGFLLCLK 				0x01
#define ASCII_ESC 27

//Inicjalizacja interfejsu UART0
void UART0_Init(void);

//Funkcja wyswietlajaca dany string
void Display(char buffor[]);

//Funkcja czyszczaca ekran
void Clear(void);

//Funkcja resetujaca polozenie kursora
void ResetCursor(void);
