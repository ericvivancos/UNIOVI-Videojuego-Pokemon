#pragma once
#include "Actor.h"
#include "Animation.h"

class Player :
    public Actor
{
public:
    Player(float x, float y, Game* game);
    void update();
    void moveX(float axis);
    void moveY(float axis);
    void draw(float scrollX = 0, float scrollY = 0) override;
    int state;
    Game::Orientation orientation;

    Animation* aMoveLeft;
    Animation* aMoveRight;
    Animation* aMoveUp;
    Animation* aMoveDown;

    Animation* aIdleLeft;
    Animation* aIdleRight;
    Animation* aIdleUp;
    Animation* aIdleDown;

    Animation* animation;
};

