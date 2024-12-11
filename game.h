#ifndef __GAME__
#define __GAME__

void	playGame(int* board, int boardSize, int scoreToWin);
void	printBoard(const int* matrix, int size);
void	startGame(int* mat, int size, int* currScore, int* bestScore);
void	gameOver(int* mat, int size, int scoreToWin);

#endif
