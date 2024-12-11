#include <stdio.h>
#include "player.h"
#include "game.h"
#include "utils.h"


void	up(int* mat, int size, int* currScore,int* bestScore)
{
	int i, counterCheck = 0;								
	for (i = 0; i < size; i++)							//run on the matrix from line 2
	{ 											
		shiftUp(mat + i, size, &counterCheck);				//move the numbers up
		mergeUp(mat + i, size, currScore, &counterCheck);	//merge if possible
		shiftUp(mat + i, size, &counterCheck);				//move the numbers up 
	}							
	finishMove(mat, size, currScore, bestScore, counterCheck);
}


void	down(int* mat, int size, int* currScore,int* bestScore)
{
	int i, counterCheck = 0;
	for(i = 0; i < size ; i++)						//run on the matrix from line 2
	{ 											
		shiftDown(mat + i, size, &counterCheck);				//move the numbers down
		mergeDown(mat + i, size, currScore, &counterCheck);	//merge if possible
		shiftDown(mat + i, size, &counterCheck);				//move the numbers down
	}
	finishMove(mat, size, currScore, bestScore, counterCheck);
}


void	right(int* mat, int size, int* currScore,int* bestScore)
{
	int i, counterCheck = 0;
	for(i = 0; i < size; i++)
	{ 
		shiftRight(mat + i * size, size, &counterCheck);				//move the numbers right
		mergeRight(mat + i * size, size, currScore, &counterCheck);	//merge if possible
		shiftRight(mat + i * size, size, &counterCheck);				//move the numbers right
	}
	finishMove(mat, size, currScore, bestScore, counterCheck);
}


void	left(int* mat, int size, int* currScore,int* bestScore)
{
	int i, counterCheck = 0;
	for(i = 0; i < size ; i++)								//run on the matrix from line 2
	{ 											
		shiftLeft(mat + i * size, size, &counterCheck);				//move the numbers left
		mergeLeft(mat + i * size, size, currScore, &counterCheck);	//merge if possible
		shiftLeft(mat + i * size, size, &counterCheck);				//move the numbers left
	}
	finishMove(mat, size, currScore, bestScore, counterCheck);
}


