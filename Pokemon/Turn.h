// Turn.h
#pragma once
#include "Pokemon.h"

class Turn {
public:
    Turn(Pokemon* performer, Pokemon* target, Movement* move);
    void execute(); // Lógica para ejecutar el turno
private:
    Pokemon* performer;
    Pokemon* target;
    Movement* move;
};
