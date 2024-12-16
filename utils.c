#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"
#include "game.h"
#include "player.h"

void	fillRandomNumber(int* mat, int size)
{
	int index;
	
	do{
		index = rand() % (size * size);
	}while(*(mat + index) != 0);
	
	*(mat + index) = (rand() / (float)RAND_MAX < 0.3) ? 4 : 2;

}

void	swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}

void	shiftUp(int* mat, int size, int* counterCheck)			
{
	int i, j = 0;
	for (i = 1; i <= size - 1; i++)
	{
		if (*(mat + j * size) == 0)
		{
			if(*(mat + i * size) != 0)
			{
				swap((mat + i * size),(mat + j * size));
				(*counterCheck)++;
				j++;			
			}
		}else
		{
			j++;
		}
	}

}

void	mergeUp(int* mat, int size, int* currScore,int* counterCheck)
{
	int i;
	for (i = 0; i < size - 1; i++)
	{
		if (*(mat + i * size) != 0)
		{
			if (*(mat + i * size) == *(mat + (i * size) + size))
			{
				*(mat + i * size) *= 2;
				*(mat + (i * size) + size) = 0;
				*currScore += *(mat + i * size);
				(*counterCheck)++;
				return;
			}
		}
	}
	
}

void	shiftDown(int* mat, int size, int* counterCheck)			
{
	int i, j = size - 1;
	for (i = size - 2; i >= 0; i--)
	{
		if (*(mat + j * size) == 0)
		{
			if(*(mat + i * size) != 0)
			{
				swap((mat + i * size), (mat + j * size));
				(*counterCheck)++;
				j--;		
			}
		}else
		{
			j--;
		}
	}

}


void	mergeDown(int* mat, int size, int* currScore, int* counterCheck)
{
	int i;
	for (i = size - 1; i > 0 ; i--)
	{
		if(*(mat + i * size) != 0)
		{
			if (*(mat + i * size) == *(mat + (i * size) - size))
			{
				*(mat + i * size) *= 2;
				*(mat + (i * size) - size) = 0;
				*currScore += *(mat + i * size);
				(*counterCheck)++;
				return;
			}
		}
	}

}


void	shiftRight(int* mat, int size, int* counterCheck)	
{
	int i, j = size - 1;
	for (i = size - 2; i >= 0; i--)
	{
		
		if (*(mat + j) == 0)
		{
			if(*(mat + i) != 0)
			{
				swap((mat + i), (mat + j));
				(*counterCheck)++;
				j--;			
			}
		}else
		{
			j--;
		}
	}

}


void	mergeRight(int* mat, int size, int* currScore, int* counterCheck)
{
	int i;
	for (i = size - 1; i > 0; i--)
	{
		if(*(mat + i) != 0)
		{	
			if (*(mat + i) == *(mat + i -1))
			{
				*(mat + i) *= 2;
				*(mat + i - 1) = 0;
				*currScore += *(mat + i);
				(*counterCheck)++;
				return;
			}
		}
	}

}


void	shiftLeft(int* mat, int size, int* counterCheck)	
{
	int i, j = 0;
	for (i = 1; i <= size - 1; i++)
	{
		if (*(mat + j) == 0)
		{
			if(*(mat + i) != 0)
			{
				swap((mat + i), (mat + j));
				(*counterCheck)++;
				j++;		
			}
		}else
		{
			j++;
		}
	}

}


void	mergeLeft(int* mat, int size, int* currScore, int* counterCheck)
{
	int i;
	for (i = 0; i < size - 1; i++)
	{
		if(*(mat + i) != 0)
		{
			if (*(mat + i) == *(mat + i + 1))
			{
				*(mat + i) *= 2;
				*(mat + i + 1) = 0;
				*currScore += *(mat + i);
				(*counterCheck)++;
				return;
			}
		}
	}	

}

int		ifStarted(int* mat, int size) 
{
	for (int i = 0; i < size * size; i++) 
	{
		if (*(mat + i) != 0) 
			return 1;
	}
	printf("Need to start the game first!");
	return 0;
}

void	printMenu()
{
	printf("\nPlease choose one of the following options: \nN/n - New Game\nR/r - Move Right\nL/l - Move Left\nU/u - Move Up\nD/d - Move Down\nE/e - Exit\n");
}


void	finishMove(int* mat, int size,int* currScore, int* bestScore, int counterCheck)
{
	if(counterCheck == 0)
	{	
		printf("Nothing to move in this direction, the board remains unchanged, choose another option. \n");
		printf("Score %d  Best %d\n", *currScore, *bestScore);
		printBoard(mat, size);  
		//prints the score and the board again in case of cannot move although unchanged
	}
	else
	{
		fillRandomNumber(mat, size);
		if(*currScore > *bestScore)       
			*bestScore = *currScore;
		printf("Score %d  Best %d\n", *currScore, *bestScore);
		printBoard(mat, size);
		//update the best score (if need to) and showing the move		
	}

}


int	canMove(const int* mat, int size) {
  	
	for (int i = 0; i < size * size; i++)								//check if there are empty cells(0 in cell)
	{
		if (*(mat + i) == 0)							
		{
		    return 1;
		}
	}
	    
	for (int row = 0; row < size; row++) 								//check if there are possibble adds
	{
		for (int col = 0; col < size; col++) 
		{
			int current = *(mat + row * size + col);

			if (col < size - 1 && current == *(mat + row * size + col + 1)) 		//check cell from right 
			{
		        return 1;
			}

			if (col > 0 && current == *(mat + row * size + col - 1)) 			//check cell from left
		    	{
		        return 1;
		    	}
		    
		    	if (row < size - 1 && current == *(mat + (row + 1) * size + col)) 		//check cell from down
		    	{
		        return 1; 
		    	}

		    	if (row > 0 && current == *(mat + (row - 1) * size + col)) 			//check cell from up
		    	{
		        return 1; 								
		    	}
		}
	}
  
	    return 0;										//if there's no cell with 0 and none adds(cant move)
}

void	resetMat(int* mat, int size)
{
	int i;
	for(i = 0; i < size * size; i++)
		*(mat+i) = 0;

}

int	maxValue(const int* mat, int size)
{
	int i,max = *mat;
	for(i = 1; i < size * size; i++)
	{
		if(*(mat+i) > max)
		{
			max = *(mat + i);
		}
	}
	return max;
}





















