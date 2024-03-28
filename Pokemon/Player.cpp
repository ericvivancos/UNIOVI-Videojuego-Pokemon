#include "Player.h"
Player::Player(float x, float y, Game* game)
	: Actor("resoruces/tiles/asteroide.png",x,y,64,64,game) {
	orientation = game->Down;
	state = game->Moving;
	aMoveLeft = new Animation("resoruces/tiles/Player/move_left.png", width, height, 256, 63,3,4,true,game);
	aMoveRight = new Animation("resoruces/tiles/Player/move_right.png", width, height, 256, 63, 3, 4, true, game);
	aMoveUp = new Animation("resoruces/tiles/Player/move_up.png", width, height, 256, 63, 3, 4, true, game);
	aMoveDown = new Animation("resoruces/tiles/Player/move_down.png", width, height, 256, 63, 3, 4, true, game);
	aIdleLeft = new Animation("resoruces/tiles/Player/idle_left.png", width, height, 256, 63, 3, 1, true, game);
	aIdleRight = new Animation("resoruces/tiles/Player/idle_right.png", width, height, 256, 63, 3, 1, true, game);
	aIdleUp = new Animation("resoruces/tiles/Player/idle_up.png", width, height, 256, 63, 3, 1, true, game);
	aIdleDown = new Animation("resoruces/tiles/Player/idle_down.png", width, height, 256, 63, 3, 1, true, game);
	animation = aMoveDown;

}
void Player::update() {
	animation->update();
	
    if (state == game->Moving) {
        if (vx != 0 || vy != 0) {
            // Priorizar la dirección horizontal sobre la vertical
            if (abs(vx) > abs(vy)) {
                // Movimiento horizontal
                orientation = (vx > 0) ? game->Right : game->Left;
            }
            else {
                // Movimiento vertical
                orientation = (vy > 0) ? game->Down : game->Up;
            }

            // Seleccionar la animación correspondiente
            if (vx != 0) {
                animation = (vx > 0) ? aMoveRight : aMoveLeft;
            }
            else if (vy != 0) {
                animation = (vy > 0) ? aMoveDown : aMoveUp;
            }
        }
        else {
            // No se está moviendo
            if (orientation == game->Right) {
                animation = aIdleRight;
            }
            else if (orientation == game->Left) {
                animation = aIdleLeft;
            }
            else if (orientation == game->Up) {
                animation = aIdleUp;
            }
            else if (orientation == game->Down) {
                animation = aIdleDown;
            }
        }
    }

	
}
void Player::moveX(float axis) {
	vx = axis * 10;
}
void Player::moveY(float axis) {
	vy = axis * 10;
}
void Player::draw(float scrollX, float scrollY) {
	animation->draw(x - scrollX ,y -scrollY);
	
}
