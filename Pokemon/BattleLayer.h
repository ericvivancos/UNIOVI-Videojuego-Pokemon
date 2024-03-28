#pragma once
#include "Layer.h"
#include "Background.h"
#include "Pokemon.h"
#include "HealtBar.h"
#include "Text.h"
#include "Turn.h"
#include <list>
#include <queue>
#include "HealthBar.h"

const SDL_Color BLACK = { 86,86,86,255 };
const SDL_Color WHITE = { 255,255,255,255 };
class BattleLayer : public Layer
{
public:
	BattleLayer(Game* game);
	//virtual ~BattleLayer() override;
	virtual void init();
	virtual void processControls() override;
	void updateHealthBars();
	virtual void update() override;
	virtual void draw() override;
	void mouseToControls(SDL_Event event);

	Background* background;
	Actor* exitButton;
	Actor* firstMovementButton;
	Actor* secondMovementButton;
	Actor* thirstMovementButton;
	Actor* fourthMovementButton;
	Actor* bagButton;
	Actor* pokemonButton;

	Actor* playerUI;
	Actor* enemyUI;

	Text* firstMovementName;
	Text* currentPokemonName;
	Text* currentPokemonLevel;

	DialogManager* dialogManager;
	Text* enemyPokemonName;
	Text* enemyPokemonLevel;
	Text* dialog;

	HealthBar* playerHealthBar;
	HealthBar* enemyHealthBar;

	Animation* player_captured;
	Animation* player;
	Pokemon* wildPokemon;
	Pokemon* selectedPokemon;
	list<Pokemon*> playerPokemon;
	priority_queue<Turn*> turnQueue;

	void initializeBattle(list<Pokemon*> playerpokemon, Pokemon* wildpokemon);
};

