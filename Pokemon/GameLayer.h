#pragma once
#include "Layer.h"
#include "Audio.h"
#include "Space.h"
#include "Pokemon.h"
#include "Tile.h"
#include "Player.h"
#include "CollisionsTiles.h"


#include<list>
#include<fstream>
#include <sstream>
#include "Background.h"

class GameLayer : public Layer
{
public:
	GameLayer(Game* game);
	void init() override;
	void playAudio() override;
	void processControls() override;
	void update() override;
	void draw() override;
	void keysToControls(SDL_Event event);
	void mouseToControls(SDL_Event event);
	void loadMap(string name);
	void loadMapObject(char character, float x, float y);
	void calculateScroll();
	bool isCollisionWithArbol(Player* player);
	bool pause;
	Space* space;
	float scrollX;
	float scrollY;
	int mapWidth;
	int mapHeight;

	Player* player;
	Background* background;
	list<Tile*> tiles;
	list<Tile*> grass;
	list<Actor*> arboles;
	list<Actor*> casas;
	list<Pokemon*> capturedPokemons;

	Actor* centroPokemon;
	Actor* gimnasio;

	CollisionsTiles* colissionTiles;
	Audio* audioBackground;

	bool controlContinue = false;
	int controlMoveX = 0;
	int controlMoveY = 0;
};

