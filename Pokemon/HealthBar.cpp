#include "HealthBar.h"

HealthBar::HealthBar(float x, float y, float width, float height, SDL_Color color, Game* game)
    : Actor("", x, y, static_cast<int>(width), static_cast<int>(height), game), color(color), currentHealth(100.0f), maxHealth(100.0f) {}

HealthBar::~HealthBar() {
    // Puedes agregar l�gica de liberaci�n de recursos aqu� si es necesario
}

void HealthBar::setHealth(float health) {
    // Aseg�rate de que la salud est� en el rango adecuado (0.0f a maxHealth)
    currentHealth = std::max(0.0f, std::min(health, maxHealth));
}

void HealthBar::draw(float scrollX, float scrollY) {
    // Implementa aqu� la l�gica espec�fica de dibujo de la barra de salud.
    // Puedes utilizar game->renderer y otros miembros necesarios.
    // Recuerda llamar al m�todo draw de la clase base si es necesario.

    // Ejemplo b�sico:
    SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
    SDL_Rect healthRect = {
        static_cast<int>(x - scrollX),
        static_cast<int>(y - scrollY),
        static_cast<int>(width * (currentHealth / maxHealth)),
        static_cast<int>(height)
    };
    SDL_RenderFillRect(game->renderer, &healthRect);
}