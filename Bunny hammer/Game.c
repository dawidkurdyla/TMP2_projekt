#include "Game.h"

void Game(void)
{
	//Wyczyszczenie tablicy przerwan od przycisków
	KeyPressed = 0;
	for (int i = 0; i < 4; i++)
		S_pressed[i] = 0;
	pause = 1;
	state = 1;
	lastValue = 0;
	
	while(state)
	{	
		if(counted)
		{
				//Pauza pomiedzy wyswietleniami pozycji królika
				if(pause)
				{
					//Blokowanie klikania po zniknieciu królika
					NVIC_DisableIRQ(PORTA_IRQn);
					
					if(!killed)
					{
						lifes--;
					}										
						SetSpeed();
						Clear();
						ResetCursor();
						DisplayGame();
						pause = 0;
						
				}			
				else if(!pause)
				{
					NVIC_EnableIRQ(PORTA_IRQn);
					state = CheckGameState();	
					BunnyPos = rand() % (4); 
					DisplayGame();
					killed = 0;
					pause = 1;
				}
				counted = 0;
		}
		if(KeyPressed)
		{		
				//Wylaczenie przerwan od klawiatury
				NVIC_DisableIRQ(PORTA_IRQn);
			
				//Jesli trafiono królika 
				if(CheckPressed())
				{
					//Dodanie pkt
					score ++;
					
					//Sygnalizacja ze królik zostal zbity
					killed = 1;
					
					Clear();
					ResetCursor();
					
					//Wyswietlenie aktualnych statystyk
					DisplayStats();
					
					sprintf(display, "\n\n____");
					Display(display);
					
				}
				//Jesli nie trafiono
				else 
				{
					Clear();
					ResetCursor();
										
					//Wyswietlenie aktualnych statystyk
					DisplayStats();
					
					sprintf(display, "\n\n____");
					Display(display);
				}
				
				KeyPressed = 0;
		}	
	}
}

void SetSpeed(void)
{
	//Co 10 punktów, przyspiesz gre o 10ms
	if(score > lastValue + 10)
	{
		if(speed > 10)
		{
			speed -= 10;
		}
		lastValue = score;
	}
}

void DisplayGame()
{
		Clear();
	
		ResetCursor();
		
		DisplayStats();
	
		//Wyswietlenie pozycji królika
		if(!pause)
		{
			sprintf( display, "\n\n");
			for(int i = 0; i < 4; i++ )
			{
					if(i == BunnyPos)
					{
						strcat(display, "#");
					}
					else
					{
						strcat(display, "_");
					}				
			}
			Display(display);
		}
		//Wyswietlenie puustego pola w celu oddzelenia wyswietlen
		else
		{
			sprintf(display, "\n\n____");
			Display(display);
		}
}
int CheckGameState(void)
{	
	int result = 1;
	
	//Jesli ilosc zyc spadnie do 0 -> koniec gry
	if(lifes <= 0)
	{
		result = 0;
	}
	
	return result;
}

int CheckPressed(void)
{
	int result = 0;
	for(int i = 0; i < 4; i++)
	{
		if(S_pressed[i] == 1)
		{
			if(i == BunnyPos)
			{
				result = 1;
			}
			else
			{
				result = 0;
			}
			//Wyczyszczenie "flagi" przycisku
			S_pressed[i] = 0;
		}
		
	}
	return result;
}

void DisplayStats(void)
{
	//Wyswietlenie aktualnego wyniku
		sprintf( display, "Score: %d", score);
		Display(display);
		ResetCursor();
	
		//Wyswietlenie ilosci zyc gracza
		sprintf( display, "\nLifes: %d", lifes);
		Display(display);
		ResetCursor();
}
