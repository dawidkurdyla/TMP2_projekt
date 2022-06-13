/*-------------------------------------------------------------------------
					This file is a part of the Technika Mikroprocesorowa 2 Projekt
----------------------------------------------------------------------------*/

/**
 * @file pit.h
 * @author Kurdyla & Jatczyszyn
 * @date Styczen 2021
 * @brief Plik zawiera definicje funkcji inicializujacej timer PIT
 * @ver 1.0
*/

#include "MKL05Z4.h"
#include	"pit.h"

void PIT_Init(void)
{
	//Wartosc startowa 
	uint32_t tsv;
	
	// Wlaczenie sygnalu zegara do modulu PIT
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
	
	// Wlaczenie modulu PIT
	PIT->MCR &= ~PIT_MCR_MDIS_MASK;	

	//Przerwanie co 100ms	
	tsv=BUS_CLOCK/100;		
	
	// Zaladowanie wartosci startowej
	PIT->CHANNEL[0].LDVAL = PIT_LDVAL_TSV(tsv);	
	
	// Odblokowanie przerwania i wystartowanie licznika
	PIT->CHANNEL[0].TCTRL = PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK;		
	
	//Wyczyszczenie niechcianych przerwan
	NVIC_ClearPendingIRQ(PIT_IRQn);
	
	//Wlaczenie przerwan od timera PIT
	NVIC_EnableIRQ(PIT_IRQn);	
}
