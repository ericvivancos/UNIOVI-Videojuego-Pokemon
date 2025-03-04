#pragma once
#include "Layer.h"
#include "Background.h"
#include "Audio.h";
class MenuLayer : public Layer
{
public:
	MenuLayer(Game* game);
	void init() override;
	void draw() override;
	void processControls() override;
	void keysToControls(SDL_Event event);
	void mouseToControls(SDL_Event event);
	bool controlContinue;
	Background* background;
	Actor* button;
	Audio* audioBackground;
};

