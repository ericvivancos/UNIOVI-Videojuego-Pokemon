#include "Squirtle.h"
#include "Llamarada.h"

Squirtle::Squirtle(float x, float y, Game* game)
	:Pokemon("Squirtle", 100, 30, 20, "resoruces/backgrounds/Pokemons/0007/squirtleFront.png", x, y, 97, 100, game)
{
	this->frontal = new Animation("resoruces/backgrounds/Pokemons/0007/squirtleFront.png", width, height, 97, 100, 3, 1, false, game);
	this->back = new Animation("resoruces/backgrounds/Pokemons/0007/squirtleBack.png", width, height, 97, 100, 3, 1, false, game);
	this->animation = frontal;
	this->moves.push_back(new Llamarada());
	this->speed = 20;
}
