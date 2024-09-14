#pragma once
#include <SDL.h>
#include <vector>
#include <string>

using namespace std;

// Screen stats
const int CELL_SIZE = 160;
const int BOARD_SIZE = 3;
const int WINDOW_SIZE = CELL_SIZE * BOARD_SIZE;

class TicTacToe
{
private:
	vector<vector<int>> grid;
	bool player1Turn;
	bool gameEnded;
	int turnCount;
public:
	TicTacToe() : grid(BOARD_SIZE, vector<int>(BOARD_SIZE, 0)), player1Turn(true),
		gameEnded(false), turnCount(0) {}
	void makeMove(int, int);	// switch turns
	int checkWin() const;
	bool isGameEnded() const;
	void setGameEnded(bool); // end or not ?
	int getTurnCount() const;
	vector<vector<int>> getGrid() const;
};

