#pragma once
#include <SDL.h>
#include "TicTacToe.h"

class Renderer
{
private:
	SDL_Renderer* renderer;
public:
	Renderer() : renderer(nullptr) {}
	Renderer(SDL_Renderer* r) : renderer(r) {}
	~Renderer();
	void renderBoard();
	void drawX(int, int);
	void markInGrid(int, int, int);
	void renderWindow(const TicTacToe&);
};