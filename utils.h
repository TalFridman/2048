#ifndef __UTILS__
#define __UTILS__

void	fillRandomNumber(int* mat, int size);
void	swap(int* x, int* y);
int	ifStarted(int* mat, int size);
void	printMenu();
void	finishMove(int* mat, int size,int* currScore, int* bestScore, int counterCheck);
int	canMove(const int* mat, int size);
void	resetMat(int* mat, int size);
int	maxValue(const int* mat, int size);

void	shiftUp(int* mat, int size, int* counterCheck);
void	shiftDown(int* mat, int size, int* counterCheck);
void	shiftRight(int* mat, int size, int* counterCheck);
void	shiftLeft(int* mat, int size, int* counterCheck);

void	mergeUp(int* mat, int size, int* currScore, int* counterCheck);
void	mergeDown(int* mat, int size, int* currScore, int* counterCheck);
void	mergeLeft(int* mat, int size, int* currScore, int* counterCheck);
void	mergeRight(int* mat, int size, int* currScore, int* counterCheck);


#endif
