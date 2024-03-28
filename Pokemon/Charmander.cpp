#include "Charmander.h"
#include "Llamarada.h"

Charmander::Charmander(float x, float y, Game* game)
	:Pokemon("Charmander",100,30,20,"resoruces/backgrounds/Pokemons/0004/charmanderFront.png",x,y,87,94,game)
{
	this->frontal = new Animation("resoruces/backgrounds/Pokemons/0004/charmanderFront.png", width, height, 87, 94, 3, 1, false, game);
	this->back = new Animation("resoruces/backgrounds/Pokemons/0004/charmanderBack.png", width, height, 87, 94, 3, 1, false, game);
	this->animation = frontal;
	this->moves.push_back(new Llamarada());
	this->speed = 21;
}
