#include "TicTacToe.h"

void TicTacToe::makeMove(int row, int col) {
	// Define player1 as 1, also for player2
	if (grid[row][col] == 0 && !gameEnded) {
		grid[row][col] = player1Turn ? 1 : 2;
		player1Turn = !player1Turn;
		turnCount++;
	}
}

int TicTacToe::checkWin() const {
	// Check rows and columns
	for (int i = 0; i < 3; i++) {
		if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != 0)
			return grid[i][0];
		if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != 0)
			return grid[0][i];
	}

	// Check diagonal
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != 0)
		return grid[0][0];
	if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != 0)
		return grid[0][2];

	return 0; // GAME TIE
}

bool TicTacToe::isGameEnded() const { return gameEnded; }
void TicTacToe::setGameEnded(bool ended) { gameEnded = ended; }
int TicTacToe::getTurnCount() const { return turnCount; }
vector<vector<int>> TicTacToe::getGrid() const { return grid; }