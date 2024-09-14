#include "Game.h"

int main(int argc, char* argv[]) {
	Game ticTacToe;

	if (ticTacToe.initGame() == false) { // init game failed
		return 1;
	}

	ticTacToe.run();
	return 0;
}