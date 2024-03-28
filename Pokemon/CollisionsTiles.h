#pragma once
#include "Space.h"
#include "Tile.h"
class CollisionsTiles
{
public:
	bool static shouldSpawnPokemon();
	void colissionGrass(Actor* actor,list<Tile*> grass_list, Game* game);

};

