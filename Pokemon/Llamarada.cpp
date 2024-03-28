#include "Llamarada.h"

Llamarada::Llamarada() 
    :Movement("Llamarada",20,30)
{
}

void Llamarada::performMove(Pokemon* user, Pokemon* target)
{
    // Lógica específica para el movimiento de llamarada
    int damage = (int)(user->attack * power / target->defense);
    if (damage > 0) {
        target->reduceHealt(damage);
        std::cout << user->name << " usa " << name << ". Causa " << damage << " de daño a " << target->name << "!" << std::endl;
    }
    else {
        std::cout << user->name << " usa " << name << ". No causa daño a " << target->name << "." << std::endl;
    }
}
