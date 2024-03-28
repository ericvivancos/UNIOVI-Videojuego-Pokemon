#pragma once

#include "Game.h"
class Game;

class Layer
{
public:
	Layer(Game* game);
	virtual ~Layer(){}
	virtual void init() {};
	virtual void playAudio() {};
	virtual void processControls(){}
	virtual void update() {};
	virtual void draw() {};

	Game* game;
};

