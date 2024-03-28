#pragma once
#include "Actor.h"
#include "Animation.h"
#include "Movement.h"

#include <vector>
class Movement;
class Pokemon : public Actor {
public:
	Pokemon(std::string name, int health, int attack, int defense, std::string filename, float x, float y, int width, int height, Game* game);
	static Pokemon* generateRandomPokemon(Game* game);
	void draw(float scrollX = 0,float scrollY = 0) override;
	void reduceHealt(int amount);
	Animation* frontal;
	Animation* back;
	Animation* animation;
	string name;

	int health;
	int maxHealth;
	int attack;
	int defense;
	int speed;

	std::vector<Movement*> moves;
	Game* game;
};


