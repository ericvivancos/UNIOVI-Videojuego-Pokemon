// HealthBar.h
#pragma once

#include "Actor.h"  // Aseg�rate de incluir el encabezado de la clase base
#include "Pokemon.h"

class HealthBar : public Actor {
public:
    HealthBar(float x, float y, float width, float height, SDL_Color color, Game* game);
    ~HealthBar();  // A�ad� el destructor para liberar recursos si es necesario

    void setHealth(float health);  // A�ade esta funci�n para actualizar la salud
    void draw(float scrollX, float scrollY) override;  // Sobrescribe la funci�n draw

private:
    SDL_Color color;
    float currentHealth;
    float maxHealth;
};
