#include "BattleLayer.h"

const float PLAYER_HEALTH_BAR_X = WIDTH * 0.685;
const float PLAYER_HEALTH_BAR_Y = HEIGHT * 0.59;
const float ENEMY_HEALTH_BAR_X = WIDTH * 0.316;
const float ENEMY_HEALTH_BAR_Y = HEIGHT * 0.209;
const float MAX_HEALTH_BAR_WIDTH = 185.0f;
const float HEALTH_BAR_HEIGHT = 17.0f;
const SDL_Color PLAYER_HEALTH_COLOR = { 112, 248, 168, 255 };  // Verde brillante

BattleLayer::BattleLayer(Game* game)
	: Layer(game)
{
	init();
}
void BattleLayer::init() {
	background = new Background("resoruces/backgrounds/battle.png", WIDTH * 0.5, HEIGHT * 0.5, game);
	secondMovementButton = new Actor("resoruces/backgrounds/boton.png", WIDTH * 0.72, HEIGHT * 0.8, 242, 50, game);
	fourthMovementButton = new Actor("resoruces/backgrounds/boton.png", WIDTH * 0.72, HEIGHT * 0.9, 242, 50, game);
	firstMovementButton = new Actor("resoruces/backgrounds/boton.png", WIDTH * 0.38, HEIGHT * 0.8, 242, 50, game);
	thirstMovementButton = new Actor("resoruces/backgrounds/boton.png", WIDTH * 0.38, HEIGHT * 0.9, 242, 50, game);
	exitButton = new Actor("resoruces/backgrounds/HuirBoton.png", WIDTH * 0.55, HEIGHT * 0.92, 72, 70, game);
	bagButton = new Actor("resoruces/backgrounds/BolsaBoton.png", WIDTH * 0.52, HEIGHT * 0.87, 68, 70, game);
	pokemonButton = new Actor("resoruces/backgrounds/IntercambioBoton.png", WIDTH * 0.58, HEIGHT * 0.87, 67, 70, game);
	playerUI = new Actor("resoruces/backgrounds/PlayerHeathBar.png", WIDTH * 0.7, HEIGHT * 0.6, 388, 140, game);
	enemyUI = new Actor("resoruces/backgrounds/HealtBarEnemy.png", WIDTH * 0.35, HEIGHT * 0.2, 372, 108, game);
	
	this->player = new Animation("resoruces/backgrounds/PlayerBackground.png", 153 , 361, 153, 361, 3, 1, true, game);

	playerHealthBar = new HealthBar(PLAYER_HEALTH_BAR_X, PLAYER_HEALTH_BAR_Y, MAX_HEALTH_BAR_WIDTH, HEALTH_BAR_HEIGHT, PLAYER_HEALTH_COLOR, game);
	enemyHealthBar = new HealthBar(ENEMY_HEALTH_BAR_X, ENEMY_HEALTH_BAR_Y, MAX_HEALTH_BAR_WIDTH, HEALTH_BAR_HEIGHT, PLAYER_HEALTH_COLOR, game);
	
	dialogManager = new DialogManager();
	
}	
void BattleLayer::processControls()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			game->input = game->inputMouse;
		}
		if (game->input == game->inputMouse) {
			mouseToControls(event);
		}
	}
}

void BattleLayer::update()
{
	if (!turnQueue.empty()) {
		Turn* currentTurn = turnQueue.top();
		currentTurn->execute();
		turnQueue.pop();
		
		enemyHealthBar->setHealth(wildPokemon->health);
		playerHealthBar->setHealth(selectedPokemon->health);
	}
}

void BattleLayer::draw() {
	background->draw();
	firstMovementButton->draw();
	secondMovementButton->draw();
	thirstMovementButton->draw();
	fourthMovementButton->draw();
	bagButton->draw();
	pokemonButton->draw();
	exitButton->draw();
	wildPokemon->draw();
	playerUI->draw();
	enemyUI->draw();
	selectedPokemon->draw();
	player->draw(WIDTH * 0.1,HEIGHT*0.8);
	
	playerHealthBar->draw(0,0);
	enemyHealthBar->draw(0, 0);
	
	
	currentPokemonLevel->draw(BLACK);
	currentPokemonName->draw(BLACK);
	enemyPokemonName->draw(BLACK);
	enemyPokemonLevel->draw(BLACK);
	firstMovementName->draw(WHITE);

	SDL_RenderPresent(game->renderer);
}

void BattleLayer::mouseToControls(SDL_Event event)
{
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;

	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (exitButton->containsPoint(motionX, motionY)) {
			game->layer = game->gameLayer;
			cout << "Boton pulsado" << endl;
		}
		if (firstMovementButton->containsPoint(motionX, motionY)) {
			Turn* turn = new Turn(selectedPokemon, wildPokemon, selectedPokemon->moves.front());
			turnQueue.push(turn);
			dialogManager->startDialog();
			dialog = new Text(dialogManager->getCurrentDialog(), WIDTH * 0.2, HEIGHT * 0.9, game);
			dialogManager->advanceDialog();
			dialog->draw(BLACK);
			Turn* turn2 = new Turn(wildPokemon, selectedPokemon, wildPokemon->moves.front());
			turnQueue.push(turn2);
		}
	}
}

void BattleLayer::initializeBattle(list<Pokemon*> playerpokemon,Pokemon* wildpokemon)
{
	this->wildPokemon = wildpokemon;
	this->playerPokemon = playerpokemon;
	for (const auto& pokemon : playerPokemon) {
		pokemon->animation = pokemon->back;
		pokemon->x = WIDTH * 0.35;
		pokemon->y = HEIGHT * 0.6;
	}
	selectedPokemon = playerPokemon.front();
	currentPokemonName = new Text(selectedPokemon->name, WIDTH * 0.7, HEIGHT * 0.555, game);
	currentPokemonLevel = new Text(to_string(selectedPokemon->attack), WIDTH * 0.823, HEIGHT * 0.555, game);
	firstMovementName = new Text(selectedPokemon->moves.front()->name, WIDTH * 0.38, HEIGHT * 0.8, game);
	enemyPokemonName = new Text(wildPokemon->name, WIDTH * 0.33, HEIGHT * 0.173, game);
	enemyPokemonLevel = new Text(to_string(wildPokemon->attack), WIDTH * 0.455, HEIGHT * 0.173, game);
}


