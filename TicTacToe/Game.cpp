#include "Game.h"

Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Game::initGame() {
	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "SDL couldn't initialize!", nullptr);
		return false;
	}

	// Make window
	window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 480, 480, SDL_WINDOW_SHOWN);
	{
		if (!window) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Window couldn't be created!", nullptr);
			SDL_Quit();
			return false;
		}
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Renderer could not be created!", nullptr);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	gameRenderer = Renderer(renderer);
	return true; // Init game successfully
}

void Game::run() {
	bool quit = false;
	SDL_Event event;

	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				int x, y;
				SDL_GetMouseState(&x, &y);

				int row = y / CELL_SIZE;
				int col = x / CELL_SIZE;

				ticTacToe.makeMove(row, col);
			}
			else if (event.type == SDL_KEYDOWN && ticTacToe.isGameEnded()) {
				if (event.key.keysym.sym == SDLK_ESCAPE) { // Press ESC to quit the screen
					quit = true;
				}
			}
		}

		gameRenderer.renderWindow(ticTacToe);

		int winner = ticTacToe.checkWin();
		if (ticTacToe.getTurnCount() == 9 && winner == 0) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Result", "GAME TIE!", nullptr);
			break;
			ticTacToe.setGameEnded(true);
		}
		else if (winner != 0) {
			string result = winner == 1 ? "BLUE IS WINNER!" : "RED IS WINNER!";
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Result", result.c_str(), nullptr);
			break;
			ticTacToe.setGameEnded(true);
		}
	}
}