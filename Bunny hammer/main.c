/*-------------------------------------------------------------------------
					Technika Mikroprocesorowa 2 - Projekt
					Tytul: Bunny Hammer
					autorzy: Dawid Kurdyla, Bartosz Jatczyszyn
					wersja: 20.01.2022r
----------------------------------------------------------------------------*/

#include "pit.h"
#include "MKL05Z4.h"
#include "frdm_bsp.h"
#include "klawiatura.h"
#include "uart0.h"
#include "GlobalVariables.h"
#include "stdio.h"

#include "Game.h"

volatile uint8_t S_pressed[4];
volatile uint8_t KeyPressed = 0;
int counted = 0;
int counter = 0;
int speed = 100;

int main (void) 
{
	//Inicializacja interfejsów oraz licznika 
	Klaw_Init();
	UART0_Init();
	PIT_Init();
		
	//Inicializacja wcisnietych przyciskow
	for (int i = 0; i < 4; i++)
		S_pressed[i] = 0;
	
	//Petla glowna programu
	while(1)
	{
				KeyPressed = 0;
				for(int i = 0; i < 1; i++)
				{
					Clear();
					ResetCursor();
		
					sprintf( display, "S1: Start Game");
					Display(display);
					ResetCursor();
					sprintf( display, "\nS2: Best Scores");
					Display(display);
				}
				while(!KeyPressed)
				{
					//Start Gry
					if(S_pressed[0])
					{
						NVIC_DisableIRQ(PORTA_IRQn);
				
						Clear();
						ResetCursor();
						Game();
						KeyPressed = 0;
						for (int i = 0; i < 4; i++)
							S_pressed[i] = 0;
						counted = 0;
						speed = 100;
						BunnyPos = 0;
						score = 0;
						lifes = 3;
						killed = 1;
						break;
				}
		}
	}
		
}
