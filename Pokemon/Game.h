#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map>

#define WIDTH 1280
#define HEIGHT 720

#include"Layer.h"
#include "DialogManager.h"

class Layer;

using namespace std;
class Game
{
public:
	Game();
	~Game();
	void initialize();
	void cleanUp();
	void scale();
	void loop();

	SDL_Texture* getTexture(string filename);
	map<string, SDL_Texture*> mapTextures;
	TTF_Font* font;
	bool scaledToMax = false;
	float scaleLower = 1;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool loopActive;
	Layer* layer;
	Layer* menuLayer;
	Layer* gameLayer;
	Layer* battleLayer;
	Layer* OptionsLayer;

	

	int input;
	int const inputKeyboard = 1;
	int const inputMouse = 2;
	int const inputGamePad = 3;

	enum GameState { Idle, Moving, Collided };
	enum Orientation { Up, Down, Right, Left };
	enum BattleState { Preparation, In_Progress, Finished};
	enum PokemonSate { Healthy, Weakened};
	enum PlayerSate{ Exploration, Confrontation};
	enum MapSate { Interor, Outside};
	enum CathcState { Attempt, Captured, Failure};
	enum MenuState { MainMenu, OptionMenu};

};

