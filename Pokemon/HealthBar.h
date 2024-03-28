// HealthBar.h
#pragma once

#include "Actor.h"  // Asegúrate de incluir el encabezado de la clase base
#include "Pokemon.h"

class HealthBar : public Actor {
public:
    HealthBar(float x, float y, float width, float height, SDL_Color color, Game* game);
    ~HealthBar();  // Añadí el destructor para liberar recursos si es necesario

    void setHealth(float health);  // Añade esta función para actualizar la salud
    void draw(float scrollX, float scrollY) override;  // Sobrescribe la función draw

private:
    SDL_Color color;
    float currentHealth;
    float maxHealth;
};
