#include "Pokemon.h"
#include "Charmander.h";
#include "Squirtle.h"
Pokemon::Pokemon(std::string name, int health, int attack, int defense, std::string filename, float x, float y, int width, int height, Game* game)
	: Actor(filename, x, y, width, height, game), name(name), health(health), attack(attack), defense(defense) {
}

Pokemon* Pokemon::generateRandomPokemon(Game* game)
{
    int n = 2;
    int randomType = rand() % n;
	switch (randomType)
	{
	case 0:
		return new Charmander(WIDTH * 0.72, HEIGHT * 0.34, game);
	case 1:
		return new Squirtle(WIDTH * 0.72, HEIGHT * 0.34, game);
	default:
		return nullptr;
		break;
	}
}

void Pokemon::draw(float scrollX, float scrollY)
{
	animation->draw(x - scrollX, y - scrollY);
}

void Pokemon::reduceHealt(int amount)
{
	amount = std::max(0, amount);
	health -= amount;
	health = std::max(0, health);
}
