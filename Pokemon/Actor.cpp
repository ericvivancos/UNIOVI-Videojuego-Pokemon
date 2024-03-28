#include "Actor.h"

Actor::Actor(string filename, float x, float y, int width, int height, Game* game) {
	clicked = false;
	this->game = game;
	texture = game->getTexture(filename);
	this->x = x;
	this->y = y;
	// lo que mide el fichero
	this->fileWidth = width;
	this->fileHeight = height;
	// lo que va a medir en el juego
	this->width = width;
	this->height = height;
	this->hasCollided = false;
}
Actor::~Actor() {
	// Implementa la lógica de liberación de recursos según tus necesidades
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}
void Actor::draw(float scrollX, float scrollY)  {
	// Recorte en el fichero de la imagen
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = fileWidth; // texture.width;
	source.h = fileHeight; // texture.height;

	// Donde se va a pegar en el renderizador
	SDL_Rect destination;
	destination.x = x - width / 2 - scrollX;
	destination.y = y - height / 2 - scrollY;
	destination.w = width;
	destination.h = height;
	// Modificar para que la referencia sea el punto central

	SDL_RenderCopyEx(game->renderer,
		texture, &source, &destination, 0, NULL, SDL_FLIP_NONE);
}
bool Actor::isOverlap(Actor* actor, float margin) {
    bool overlap = false;
    const float tolerance = 1.0f;
    if (actor->x - actor->width / 2 - margin + tolerance <= x + width / 2 + margin - tolerance
        && actor->x + actor->width / 2 + margin - tolerance >= x - width / 2 - margin + tolerance
        && actor->y + actor->height / 2 + margin - tolerance >= y - height / 2 - margin + tolerance
        && actor->y - actor->height / 2 - margin + tolerance <= y + height / 2 + margin - tolerance) {
        overlap = true;
    }
    return overlap;
}

bool Actor::containsPoint(int pointX, int pointY) {
	if (pointY >= y - height / 2 &&
		pointY <= y + height / 2 &&
		pointX <= x + width / 2 &&
		pointX >= x - width / 2) {
		return true;
	}
	return false;
}
bool Actor::isInRender(float scrollX, float scrollY) {
	if ((x - scrollX) - width / 2 <= WIDTH && (x - scrollX) + width / 2 >= 0 &&
		(y - scrollY) - height / 2 <= HEIGHT && (y - scrollY) + height / 2 >= 0) {
		return true;
	}
	return false;
}
