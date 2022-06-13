#include "ALL_IRQHandlers.h"

void PIT_IRQHandler()
{		
		if(!counted)
		{
			counter++;
			if(counter == speed)
			{
				counted = 1;
				counter = 0;
			}
		
		}
	PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;	
	NVIC_ClearPendingIRQ(PIT_IRQn);
}

void PORTA_IRQHandler(void)	// Podprogram obslugi przerwania od klawiszy S1, S2, S3 i S4
{
	uint32_t buf;
	buf=PORTA->ISFR & (S1_MASK | S2_MASK | S3_MASK | S4_MASK);

	switch(buf)
	{
		case S1_MASK:	DELAY(10)
				if(!(PTA->PDIR&S1_MASK))		// Minimalizacja drgan zestyków
				{
					if(!(PTA->PDIR&S1_MASK))	// Minimalizacja drgan zestyków (c.d.)
					{
						if(!S_pressed[0])
						{
							//Sygnalizacja ze zostal wcisniety jakikolwiek przycisk
							KeyPressed = 1;
							
							S_pressed[0] = 1;

						}
					}
				}
				break;
				
		case S2_MASK:	DELAY(10)
				if(!(PTA->PDIR&S2_MASK))		
				{
					if(!(PTA->PDIR&S2_MASK))	
					{
						if(!S_pressed[1])
						{
							//Sygnalizacja ze zostal wcisniety jakikolwiek przycisk
							KeyPressed = 1;
							
							S_pressed[1]=1;
						}
					}
				}
				break;
				
		case S3_MASK:	DELAY(10)
				if(!(PTA->PDIR&S3_MASK))		
				{
					if(!(PTA->PDIR&S3_MASK))	
					{
						if(!S_pressed[2])
						{
							//Sygnalizacja ze zostal wcisniety jakikolwiek przycisk
							KeyPressed = 1;
							
							S_pressed[2]=1;
						}
					}
				}
				break;
				
		case S4_MASK:	DELAY(10)
				if(!(PTA->PDIR&S4_MASK))		
					{
						if(!(PTA->PDIR&S4_MASK))	
						{
							if(!S_pressed[3])
							{
								//Sygnalizacja ze zostal wcisniety jakikolwiek przycisk
								KeyPressed = 1;
								
								S_pressed[3] = 1;
							}
						}
					}
				break;
		default:		break;
	}	
	// Kasowanie wszystkich bitów ISF
	PORTA->ISFR |=  S1_MASK | S2_MASK | S3_MASK | S4_MASK;
		
	//Kasowanie niechcianych przerwan
	NVIC_ClearPendingIRQ(PORTA_IRQn);
}
