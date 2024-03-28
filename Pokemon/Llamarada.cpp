#include "Llamarada.h"

Llamarada::Llamarada() 
    :Movement("Llamarada",20,30)
{
}

void Llamarada::performMove(Pokemon* user, Pokemon* target)
{
    // L�gica espec�fica para el movimiento de llamarada
    int damage = (int)(user->attack * power / target->defense);
    if (damage > 0) {
        target->reduceHealt(damage);
        std::cout << user->name << " usa " << name << ". Causa " << damage << " de da�o a " << target->name << "!" << std::endl;
    }
    else {
        std::cout << user->name << " usa " << name << ". No causa da�o a " << target->name << "." << std::endl;
    }
}
