#include "Renderer.h"

Renderer::~Renderer() {}

void Renderer::renderBoard() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set color for the border (black)

	// Draw horizontal and vertical lines
	for (int i = 1; i < BOARD_SIZE; i++) {
		SDL_RenderDrawLine(renderer, 0, i * CELL_SIZE, 480, i * CELL_SIZE);
		SDL_RenderDrawLine(renderer, i * CELL_SIZE, 0, i * CELL_SIZE, 480);
	}
}

void Renderer::drawX(int row, int col) {
	// Draw X
	SDL_RenderDrawLine(renderer, CELL_SIZE / 5 + CELL_SIZE * col, CELL_SIZE / 5 + CELL_SIZE * row,
		CELL_SIZE * (col + 1) - CELL_SIZE / 5, CELL_SIZE * (row + 1) - CELL_SIZE / 5);
	SDL_RenderDrawLine(renderer, CELL_SIZE * (col + 1) - CELL_SIZE / 5, CELL_SIZE / 5 + CELL_SIZE * row,
		CELL_SIZE / 5 + CELL_SIZE * col, CELL_SIZE * (row + 1) - CELL_SIZE / 5);
}

void Renderer::markInGrid(int row, int col, int player) {
	if (player == 1)
		SDL_SetRenderDrawColor(renderer, 61, 155, 176, 255); // Blue
	else if (player == 2)
		SDL_SetRenderDrawColor(renderer, 255, 51, 40, 255);  // Red
	drawX(row, col);
}

void Renderer::renderWindow(const TicTacToe& game) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set white for renderer
	SDL_RenderClear(renderer);							  // Clear the game screen
	renderBoard();

	auto board = game.getGrid();
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] != 0)
				markInGrid(i, j, board[i][j]);
		}
	}

	SDL_RenderPresent(renderer);							// Show the game screen
}