#pragma once

#include "Game.h"

class Text
{
public:
	Text(string content, float x, float y, Game* game);
	void draw(SDL_Color color);
	string content; // texto
	int x;
	int y;
	int width;
	int height;
	Game* game; // referencia al juego
};