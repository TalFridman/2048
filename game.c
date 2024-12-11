#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "game.h"
#include "player.h"
#include "utils.h"

//SIZE REPRESNT COLS AND ROWS



void	playGame(int* mat, int size, int scoreToWin)
{
	int bestScore = 0;
	int currScore = 0;
	char input;
	resetMat(mat, size);
	printBoard(mat, size);
	do 
	{
		input = getValidChar();
		if (input == 'N') 
		{
			startGame(mat, size, &currScore, &bestScore);      // start the game 
		}
		else if (input == 'R')
		{
			if (ifStarted(mat, size) == 0)
				continue;
			right(mat, size, &currScore, &bestScore);
			gameOver(mat, size, scoreToWin);
			
		}
		else if (input == 'L')
		{
	  		if (ifStarted(mat, size) == 0)
				continue;
	    		left(mat, size,&currScore,&bestScore);
			gameOver(mat, size, scoreToWin);
		}
		else if (input == 'U')
		{
	  		if (ifStarted(mat, size) == 0)
				continue;    
	    		up(mat, size,&currScore,&bestScore);
			gameOver(mat, size, scoreToWin);
		}
		else if (input == 'D')
		{
	  		if (ifStarted(mat, size) == 0) 
				continue; 
	    		down(mat, size, &currScore,&bestScore);
			gameOver(mat, size, scoreToWin);
		}
		else if (input == 'E')
		{
	    	printf("Ending previous game - you score %d best score %d\n\nBye bye\n", currScore, bestScore);
		break;
		}
		
		else
		{
			printf("Invalid input! please try again!");
			
		}
	} while (1);
	
}


void    printBoard(const int* matrix,int size)
{
	int i,j,k,l;

    	for(i = 0; i < size; i++)
    	{
     		for(k = 0 ; k < size; k++)
              	{
            		printf("-------");
              	}
              	printf("-\n");
            	for(j = 0; j < size; j++)
            	{
                	if(*matrix != 0)
                   		printf("|%6d",*matrix);
                	else 
                    		printf("|      ");
                	matrix++;
            	}
              	printf("|\n");
  	}
       	for(l = 0 ; l < size; l++)
        {
             printf("-------");
        }
        printf("-\n");
}

void	startGame(int* mat,int size, int* currScore, int* bestScore)
{
	resetMat(mat, size);
	if (*currScore > *bestScore) 
		*bestScore = *currScore;
	*currScore = 0;
	
	printf("--------- STARTING A GAME ---------\n");
	
	if(size == 2)
	{
		printf("         Score for a win 32\n");
		
	}
	else if(size == 3)
	{
		printf("         Score for a win 16\n");
	}
	else if(size == 4)
	{
		printf("         Score for a win 2048\n");
	}
	printf("-----------------------------------\n\n");
	printf("Score %d  Best %d\n", *currScore, *bestScore);
	fillRandomNumber(mat, size);
	fillRandomNumber(mat, size);
	printBoard(mat, size);
	
}

void	gameOver(int* mat, int size, int scoreToWin)
{
	int maxCell = maxValue(mat, size);
	if (maxCell == scoreToWin) 
	{
		printf("You Won %d ! - Ending Game\n\n", scoreToWin);
		resetMat(mat, size);
	}
	else if(!canMove(mat, size))
	{
		printf("Game Over your score is %d\n", maxCell);
		resetMat(mat, size);
	}	
}

















