#include "Space.h"



Space::Space(float gravity) {
	this->gravity = gravity;
	dynamicActors.clear();
	staticActors.clear();
    this->audioBackground = Audio::createAudio("resoruces/audios/game/collision_sound.wav", false);
}

void Space::update()
{
	for (auto const& actor : dynamicActors) {
		actor->vy = actor->vy + gravity;

		// MoverDerecha / izquierda
		updateMoveRight(actor);
        actor->hasCollided = false;
		updateMoveLeft(actor);
        actor->hasCollided = false;
        updateMoveUp(actor);
        actor->hasCollided = false;
        updateMoveDown(actor);
        actor->hasCollided = false;
	}

}
void Space::updateMoveRight(Actor* dynamicAct) {
    if (dynamicAct->vx > 0) {
        int possibleMovement = dynamicAct->vx;
        // El mejor "idealmente" vx partimos de ese
        bool colissionDetected = false;
        for (auto const& staticAct : staticActors) {
            int rightDynamic = dynamicAct->x + dynamicAct->width / 2;
            int topDynamic = dynamicAct->y - dynamicAct->height / 2;
            int downDynamic = dynamicAct->y + dynamicAct->height / 2;

            int leftStatic = staticAct->x - staticAct->width / 2;
            int topStatic = staticAct->y - staticAct->height / 2;
            int downStatic = staticAct->y + staticAct->height / 2;

            // Alerta!, Elemento estático en la trayectoria.
            if ((rightDynamic + dynamicAct->vx) >= leftStatic
                && rightDynamic <= leftStatic
                && topStatic < downDynamic
                && downStatic > topDynamic) {

                // Comprobamos si la distancia al estático es menor
                // que nuestro movimientoPosible actual
                if (possibleMovement >= leftStatic - rightDynamic) {
                    // La distancia es MENOR que nuestro movimiento posible
                    // Tenemos que actualizar el movimiento posible a uno menor
                    possibleMovement = leftStatic - rightDynamic;
                    if (!dynamicAct->hasCollided) {
                        std::cout << "Colisión detectada. Reproduciendo sonido..." << std::endl;                       
                        audioBackground->play();
                       dynamicAct->hasCollided = true;
                        return;
                    }
                }
            }
            
        }
        
        // Ya se han comprobado todos los estáticos
        dynamicAct->x = dynamicAct->x + possibleMovement;
        // Restringir la velocidad actual (opcional)
        dynamicAct->vx = possibleMovement;
        colissionDetected = false;
    }
}
void Space::updateMoveLeft(Actor* dynamicAct) {
    if (dynamicAct->vx < 0) {
        int possibleMovement = dynamicAct->vx;
        // El mejor "idealmente" vx partimos de ese

        for (auto const& staticAct : staticActors) {
            int leftDynamic = dynamicAct->x - dynamicAct->width / 2;
            int topDynamic = dynamicAct->y - dynamicAct->height / 2;
            int downDynamic = dynamicAct->y + dynamicAct->height / 2;

            int rightStatic = staticAct->x + staticAct->width / 2;
            int topStatic = staticAct->y - staticAct->height / 2;
            int downStatic = staticAct->y + staticAct->height / 2;

            // Alerta!, Elemento estático en la trayectoria.
            if ((leftDynamic + dynamicAct->vx) <= rightStatic
                && leftDynamic >= rightStatic
                && topStatic < downDynamic
                && downStatic > topDynamic) {

                // Comprobamos si la distancia al estático es menor
                // que nuestro movimientoPosible actual
                if (possibleMovement <= rightStatic - leftDynamic) {
                    // La distancia es MENOR que nuestro movimiento posible
                    // Tenemos que actualizar el movimiento posible a uno menor
                    possibleMovement = rightStatic - leftDynamic;
                    if (!dynamicAct->hasCollided) {
                        // Reproducir el sonido
                        audioBackground->play();
                        dynamicAct->hasCollided = true;
                        return;
                    }                   
                }

            }

        }
        // Ya se han comprobado todos los estáticos
        dynamicAct->x = dynamicAct->x + possibleMovement;
        // Restringir la velocidad actual (opcional)
        dynamicAct->vx = possibleMovement;
    }
}
void Space::updateMoveUp(Actor* dynamicAct) {
    if (dynamicAct->vy < 0) {
        int possibleMovement = dynamicAct->vy;

        for (auto const& staticAct : staticActors) {
            int topDynamic = dynamicAct->y - dynamicAct->height / 2;
            int downDynamic = dynamicAct->y + dynamicAct->height / 2;
            int rightDynamic = dynamicAct->x + dynamicAct->width / 2;
            int leftDynamic = dynamicAct->x - dynamicAct->width / 2;

            int topStatic = staticAct->y - staticAct->height / 2;
            int downStatic = staticAct->y + staticAct->height / 2;
            int rightStatic = staticAct->x + staticAct->width / 2;
            int leftStatic = staticAct->x - staticAct->width / 2;

            if ((topDynamic + dynamicAct->vy) <= downStatic
                && downDynamic > topStatic
                && leftDynamic < rightStatic
                && rightDynamic > leftStatic) {

                if (possibleMovement <= downStatic - topDynamic) {
                    possibleMovement = downStatic - topDynamic;
                    if (!dynamicAct->hasCollided) {
                        // Reproducir el sonido
                        audioBackground->play();
                        dynamicAct->hasCollided = true;
                        return;
                    }
                }
            }
        }
        dynamicAct->y = dynamicAct->y + possibleMovement;
        dynamicAct->vy = possibleMovement;
    }
}
void Space::updateMoveDown(Actor* dynamicAct) {
    if (dynamicAct->vy > 0) {
        int possibleMovement = dynamicAct->vy;

        for (auto const& staticAct : staticActors) {
            int topDynamic = dynamicAct->y - dynamicAct->height / 2;
            int downDynamic = dynamicAct->y + dynamicAct->height / 2;
            int rightDynamic = dynamicAct->x + dynamicAct->width / 2;
            int leftDynamic = dynamicAct->x - dynamicAct->width / 2;

            int topStatic = staticAct->y - staticAct->height / 2;
            int downStatic = staticAct->y + staticAct->height / 2;
            int rightStatic = staticAct->x + staticAct->width / 2;
            int leftStatic = staticAct->x - staticAct->width / 2;

            if ((downDynamic + dynamicAct->vy) >= topStatic
                && topDynamic < downStatic
                && leftDynamic < rightStatic
                && rightDynamic > leftStatic) {
                if (possibleMovement >= topStatic - downDynamic) {
                    possibleMovement = topStatic - downDynamic;
                   
                    if (!dynamicAct->hasCollided) {
                        std::cout << "Colisión detectada. Reproduciendo sonido..." << std::endl;
                        audioBackground->play();

                        // Marcamos que ha ocurrido una colisión para este actor
                        dynamicAct->hasCollided = true;
                        return;
                    }
                    
                }
            }
        }
        dynamicAct->y = dynamicAct->y + possibleMovement;
        dynamicAct->vy = possibleMovement;
    }
}

void Space::addDynamicActor(Actor* actor) {
	dynamicActors.push_back(actor);
}

void Space::addStaticActor(Actor* actor) {
	staticActors.push_back(actor);
}

void Space::removeDynamicActor(Actor* actor) {
	dynamicActors.remove(actor);
}

void Space::removeStaticActor(Actor* actor) {
	staticActors.remove(actor);
}


