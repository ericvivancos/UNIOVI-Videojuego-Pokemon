#include "MenuLayer.h"


MenuLayer::MenuLayer(Game* game)
	: Layer(game) {
	init();
}

void MenuLayer::init() {
	// Fondo normal, sin velocidad
	background = new Background("resoruces/backgrounds/Menubackground.png", WIDTH * 0.5, HEIGHT * 0.5, game);
	audioBackground = Audio::createAudio("resoruces/audios/menus/backaudio.mp3",true);
	audioBackground->play();
	button = new Actor("resoruces/backgrounds/comenzar_boton.png", WIDTH * 0.7, HEIGHT * 0.8, 390, 85, game);
}

void MenuLayer::draw() {
	background->draw();
	button->draw();

	SDL_RenderPresent(game->renderer); // Renderiza NO PUEDE FALTAR
}


void MenuLayer::processControls() {
	// obtener controles
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		
		// Cambio autom�tico de input
		// PONER el GamePad
		if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_CONTROLLERAXISMOTION) {
			game->input = game->inputGamePad;
		}
		if (event.type == SDL_KEYDOWN) {
			game->input = game->inputKeyboard;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			game->input = game->inputMouse;
		}
		// Procesar teclas
		if (game->input == game->inputGamePad) {  // gamePAD
		}
		if (game->input == game->inputKeyboard) {
			keysToControls(event);
		}
		if (game->input == game->inputMouse) {
			mouseToControls(event);
		}
	}

	//procesar controles, solo tiene uno
	if (controlContinue) {
		// Cambia la capa
		audioBackground->stop();
		game->gameLayer->playAudio();
		game->layer = game->gameLayer;
		controlContinue = false;
	}
}

void MenuLayer::keysToControls(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_ESCAPE: // derecha
			game->loopActive = false;
			break;
		case SDLK_1:
			game->scale();
			break;
		case SDLK_SPACE: // dispara
			controlContinue = true;
			break;
		}
	}
}

void MenuLayer::mouseToControls(SDL_Event event) {
	// Modificaci�n de coordenadas por posible escalado
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;

	// Cada vez que hacen click
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (button->containsPoint(motionX, motionY)) {
			controlContinue = true;
			cout << "Boton pulsado" << endl;
		}
	}
}

