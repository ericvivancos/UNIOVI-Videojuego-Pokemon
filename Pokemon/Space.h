
#pragma once

#include "Actor.h"
#include <list>
#include "Audio.h"

class Space
{
public:
	Space(float gravity);
	void update();
	void updateMoveRight(Actor* dynamicAct);
	void updateMoveLeft(Actor* dynamicAct);
	void updateMoveUp(Actor* dynamicAct);
	void updateMoveDown(Actor* dynamicAct);
	void addDynamicActor(Actor* actor);
	void addStaticActor(Actor* actor);
	void removeDynamicActor(Actor* actor);
	void removeStaticActor(Actor* actor);
	float gravity;
	list<Actor*> dynamicActors;
	list<Actor*> staticActors;
	Audio* audioBackground;
};
