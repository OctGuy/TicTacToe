#pragma once
#include "Renderer.h"
#include "TicTacToe.h"

class Game
{
private:
	SDL_Renderer* renderer;
	Renderer gameRenderer;
	SDL_Window* window;
	TicTacToe ticTacToe;
public:
	Game() : renderer(nullptr), window(nullptr) {}
	~Game();
	bool initGame();
	void run();
};

