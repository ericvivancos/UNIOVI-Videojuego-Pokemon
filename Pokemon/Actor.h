#pragma once

#include "Game.h"

class Actor
{
public:
	Actor(string filename, float x, float y, int width, int height, Game* game);
	~Actor();
	virtual void draw(float scrollX = 0, float scrollY = 0);
	bool isOverlap(Actor* actor,float margin);
	bool containsPoint(int pointX, int pointY); // contiene punto
	bool isInRender(float scrollX = 0, float scrollY = 0);
	bool outRight;
	bool outLeft;
	bool clicked;
	bool hasCollided;
	bool isActive;

	SDL_Texture* texture;
	int x;
	int y;
	float vx;
	float vy;
	int width;
	int height;
	int fileWidth;
	int fileHeight;
	Game* game;

};

