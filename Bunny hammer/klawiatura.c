/*-------------------------------------------------------------------------
					This file is a part of the Technika Mikroprocesorowa 2 Projekt
----------------------------------------------------------------------------*/

/**
 * @file klawiatura.c
 * @author Kurdyla & Jatczyszyn
 * @date Styczen 2021
 * @brief Plik zawiera definicje funkcji dla obslugi klawiatury matrycowej
 * @ver 1.0
*/

#include "klawiatura.h"

void Klaw_Init(void)
{
	// Wlaczenie portu A
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;	
	
	//Ustawienienie pinów portu A jako PTAx
	PORTA->PCR[Sw1] |= PORT_PCR_MUX(1);
	PORTA->PCR[Sw2] |= PORT_PCR_MUX(1);
	PORTA->PCR[Sw3] |= PORT_PCR_MUX(1);
	PORTA->PCR[Sw4] |= PORT_PCR_MUX(1);
	
	//Ustawienie rezystorów podciagajacych dla piniów klawiatury
	PORTA->PCR[Sw1] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	PORTA->PCR[Sw2] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	PORTA->PCR[Sw3] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	PORTA->PCR[Sw4] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
		
	//Ustawienie wykrywania przerwan przez zbocze opadajace
	PORTA -> PCR[Sw1] |= PORT_PCR_IRQC(0xa);
	PORTA -> PCR[Sw2] |= PORT_PCR_IRQC(0xa);
	PORTA -> PCR[Sw3] |= PORT_PCR_IRQC(0xa);		
	PORTA -> PCR[Sw4] |= PORT_PCR_IRQC(0xa);
	
	//Wlaczenie przerwan od portu A
	NVIC_ClearPendingIRQ(PORTA_IRQn);
	NVIC_EnableIRQ(PORTA_IRQn);
}
