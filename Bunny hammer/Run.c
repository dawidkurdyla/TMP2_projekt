#include "Run.h"
#include "Game.h"
#include "ALL_IRQHandlers.h"
#include "GlobalVariables.h"

void Run(void)
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

void DisplayManu(void)
{	
		Clear();
		ResetCursor();
	
		sprintf( display, "S1: Start Game");
		Display(display);
		ResetCursor();
		sprintf( display, "\nS2: Best Scores");
		Display(display);
	
}

void DisplayBest(void)
{
	
}






