// Turn.cpp
#include "Turn.h"

Turn::Turn(Pokemon* performer, Pokemon* target, Movement* move)
    : performer(performer), target(target), move(move) {}

void Turn::execute() {
    // Lógica para ejecutar el turno, por ejemplo, realizar el movimiento y actualizar las barras de salud
     move->performMove(performer, target);

    // Actualizar barras de salud, etc.
}
