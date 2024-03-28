#include "GameLayer.h"

GameLayer::GameLayer(Game* game)
	: Layer(game) {
	init();
}
void GameLayer::init() {
	space = new Space(0);
	scrollX = 0;
	scrollY = 0;
	tiles.clear();
	colissionTiles = new CollisionsTiles();
	
	background = new Background("resoruces/backgrounds/fondo.jpg", WIDTH * 0.5, HEIGHT * 0.5, -1, game);
	audioBackground = Audio::createAudio("resoruces/audios/game/town.mp3",true);
	loadMap("resoruces/maps/3.txt");
}
void GameLayer::playAudio() {
	audioBackground->play();
}
void GameLayer::loadMap(string name) {
	char character;
	string line;
	ifstream streamFile(name.c_str());
	if (!streamFile.is_open()) {
		cout << "Falla abrir el fichero de mapa" << endl;
		return;
	}
	else {
		// Por línea
		for (int i = 0; getline(streamFile, line); i++) {
			istringstream streamLine(line);
			mapWidth = line.length() * 32; // Ancho del mapa en pixels
			mapHeight = 64 + i * 64;
			// Por carácter (en cada línea)
			for (int j = 0; !streamLine.eof(); j++) {
				streamLine >> character; // Leer character 
				cout << character;
				float x = 64 / 2 + j * 64; // x central
				float y = 64 + i * 64; // y suelo
				loadMapObject(character, x, y);
			}

			cout << character << endl;
		}
	}
	streamFile.close();
}
void GameLayer::processControls() {
	//audioBackground->play();
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		keysToControls(event);
		if (controlMoveX > 0) {
			cout << "Moviendo a la derecha";
			player->moveX(1);
		}
		else if (controlMoveX < 0) {
			cout << "Moviendo a la izquierda";
			player->moveX(-1);
		}
		else {
			cout << "Quieto";
			player->moveX(0);
		}

		// Eje Y
		if (controlMoveY > 0) {
			player->moveY(1);
		}
		else if (controlMoveY < 0) {
			player->moveY(-1);
		}
		else {
			player->moveY(0);
		}
	}

		


	
	/*if (controlContinue) {
		pause = false;
		controlContinue = false;
	}*/
	// Eje X
	if (controlMoveX > 0) {
		cout << "Moviendo a la derecha";
		player->moveX(1);
	}
	else if (controlMoveX < 0) {
		cout << "Moviendo a la izquierda";
		player->moveX(-1);
	}
	else {
		cout << "Quieto";
		player->moveX(0);
	}

	// Eje Y
	if (controlMoveY > 0) {
		player->moveY(1);
	}
	else if (controlMoveY < 0) {
		player->moveY(-1);
	}
	else {
		player->moveY(0);
	}
	
	

}
void GameLayer::loadMapObject(char character, float x, float y)
{
	switch (character) {


		case '1': {
			Tile* tile = new Tile("resoruces/tiles/tierra.png", x, y, game);
			tiles.push_back(tile);
			player = new Player(x, y, game);
			// modificación para empezar a contar desde el suelo.
			player->y = player->y - player->height / 2;
			space->addDynamicActor(player);

			break;
		}
		case '_': {
			Tile* tierra = new Tile("resoruces/tiles/tierra.png", x, y, game);
			tiles.push_back(tierra);
			Tile* tile = new Tile("resoruces/tiles/mountains/hierba.png", x, y, game);
			tiles.push_back(tile);
			grass.push_back(tile);
			break;
		}
		case '!': {
			Tile* tierra = new Tile("resoruces/tiles/tierra.png", x, y, game);
			tiles.push_back(tierra);

			Tile* tile = new Tile("resoruces/tiles/mountains/up_frontal.png", x, y, game);
			tiles.push_back(tile);
			space->addStaticActor(tile);
			break;
		}
		case '|': {
			Tile* tierra = new Tile("resoruces/tiles/tierra.png", x, y, game);
			tiles.push_back(tierra);
			Tile* tile = new Tile("resoruces/tiles/mountains/relleno.png", x, y, game);
			tiles.push_back(tile);
			space->addStaticActor(tile);
			break;
		}
		case '$': {
			Tile* tile = new Tile("resoruces/tiles/mountains/saliente.png", x, y, game);
			tiles.push_back(tile);
			space->addStaticActor(tile);
			break;
		}
		case '%': {
			Tile* tile = new Tile("resoruces/tiles/mountains/saliente_izq.png", x, y, game);
			tiles.push_back(tile);
			space->addStaticActor(tile);
			break;
		}
		case '#': {
			Tile* tile = new Tile("resoruces/tiles/tierra.png", x, y, game);
			tiles.push_back(tile);
			Actor* arbol = new Actor("resoruces/tiles/arbol.png", x, y, 73, 117, game);
			space->addStaticActor(arbol);

		// modificación para empezar a contar desde el suelo.
		//tile->y = tile->y - tile->height / 2;
		arboles.push_back(arbol);
		break;
		}
		case '.': {
			Tile* tile = new Tile("resoruces/tiles/tierra.png", x, y, game);
			tiles.push_back(tile);
			break;
		}
		case 'C': {
			Actor* casa = new Actor("resoruces/tiles/Casa1.png", x, y, 166, 270, game);
			casas.push_back(casa);
			space->addStaticActor(casa);
			break;
		}
		case 'G': {
			this->gimnasio = new Actor("resoruces/tiles/gimnasioPokemon.png", x, y, 231, 205, game);
			space->addStaticActor(gimnasio);
			break;
		}
		case 'V': {
			this->centroPokemon = new Actor("resoruces/tiles/centroPokemon.png", x, y, 232, 201, game);
			space->addStaticActor(centroPokemon);
			break;
		}




	}
}
void GameLayer::update() {
	
	space->update();
	
	if (pause) {
		return;
	}
	player->update();
	
	colissionTiles->colissionGrass(player,grass,game);
	
	background->update();
	cout << "update GameLayer" << endl;
}
void GameLayer::calculateScroll() {
	const float horizontalScrollThreshold = WIDTH * 0.3;
	const float verticalScrollThreshold = HEIGHT * 0.4;

	//// Límite izquierdo
	//if (player->x - scrollX < horizontalScrollThreshold) {
	//	scrollX = player->x - horizontalScrollThreshold;
	//}

	//// Límite derecho
	//if (player->x - scrollX > WIDTH - horizontalScrollThreshold) {
	//	scrollX = player->x - (WIDTH - horizontalScrollThreshold);
	//}

	//// Límite superior
	//if (player->y - scrollY < verticalScrollThreshold) {
	//	scrollY = player->y - verticalScrollThreshold;
	//}

	//// Límite inferior
	//float lowerVerticalLimit = mapHeight - HEIGHT + verticalScrollThreshold;
	//if (player->y - scrollY > lowerVerticalLimit) {
	//	scrollY = player->y - lowerVerticalLimit;
	//}
	  // Ajusta este valor según tus necesidades

	if (player->x - scrollX < horizontalScrollThreshold) {
		scrollX = player->x - horizontalScrollThreshold;
	}

	if (player->x - scrollX > WIDTH - horizontalScrollThreshold) {
		scrollX = player->x - (WIDTH - horizontalScrollThreshold);
	}

	if (player->y - scrollY < verticalScrollThreshold) {
		scrollY = player->y - verticalScrollThreshold;
	}

	if (player->y - scrollY > HEIGHT + 10 - verticalScrollThreshold) {
		scrollY = player->y - (HEIGHT + 10 - verticalScrollThreshold);
	}
}
void GameLayer::draw() {

	calculateScroll();
	background->draw();
	for (auto const& tile : tiles) {
		if (tile->y >= scrollY - 200 && tile->y <= scrollY + HEIGHT + 200) {
			tile->draw(scrollX, scrollY);
		}

	}
	for (auto const& arbol : arboles) {
		if (arbol->y  >= scrollY - 200 && arbol->y <= scrollY + HEIGHT + 200) {
			arbol->draw(scrollX,scrollY);
		}
		for (auto const& casa : casas) {
			if (casa->y >= scrollY - 200 && casa->y <= scrollY + HEIGHT + 200) {
				casa->draw(scrollX, scrollY);
			}
		}
	}
	centroPokemon->draw(scrollX,scrollY);
	gimnasio->draw(scrollX,scrollY);
	player->draw(scrollX, scrollY);
	SDL_RenderPresent(game->renderer);
}
void GameLayer::mouseToControls(SDL_Event event) {
	// Modificación de coordenadas por posible escalado
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;
	// Cada vez que hacen click
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		controlContinue = true;
		/*/if (pad->containsPoint(motionX, motionY)) {
			pad->clicked = true;
			// CLICK TAMBIEN TE MUEVE
			controlMoveX = pad->getOrientationX(motionX);
		}
		if (buttonShoot->containsPoint(motionX, motionY)) {
			controlShoot = true;
		}
		if (buttonJump->containsPoint(motionX, motionY)) {
			controlMoveY = -1;
		}*/

	}
	// Cada vez que se mueve
	/*if (event.type == SDL_MOUSEMOTION) {
		/if (pad->clicked && pad->containsPoint(motionX, motionY)) {
			controlMoveX = pad->getOrientationX(motionX);
			// Rango de -20 a 20 es igual que 0
			if (controlMoveX > -20 && controlMoveX < 20) {
				controlMoveX = 0;
			}

		}
		else {
			pad->clicked = false; // han sacado el ratón del pad
			controlMoveX = 0;
		}
		if (buttonShoot->containsPoint(motionX, motionY) == false) {
			controlShoot = false;
		}
		if (buttonJump->containsPoint(motionX, motionY) == false) {
			controlMoveY = 0;
		}*/

	//}
	// Cada vez que levantan el click
		/*if (event.type == SDL_MOUSEBUTTONUP) {
		if (pad->containsPoint(motionX, motionY)) {
			pad->clicked = false;
			// LEVANTAR EL CLICK TAMBIEN TE PARA
			controlMoveX = 0;
		}

		if (buttonShoot->containsPoint(motionX, motionY)) {
			controlShoot = false;
		}
		if (buttonJump->containsPoint(motionX, motionY)) {
			controlMoveY = 0;
		}

	}*/
}
void GameLayer::keysToControls(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_ESCAPE:
			game->loopActive = false;
			break;
		case SDLK_1:
			game->scale();
			break;
		case SDLK_d: // derecha
			controlMoveX = 1;
			controlMoveY = 0;

			break;
		case SDLK_a: // izquierda
			controlMoveX = -1;
			controlMoveY = 0;
			break;
		case SDLK_w: // arriba
			controlMoveY = -1;
			controlMoveX = 0;
			break;
		case SDLK_s: // abajo
			controlMoveY = 1;
			controlMoveX = 0;
			break;
		}


	}
	if (event.type == SDL_KEYUP) {
		int code = event.key.keysym.sym;
		// Levantada
		switch (code) {
		case SDLK_d: // derecha
			if (controlMoveX == 1) {
				controlMoveX = 0;

			}
			break;
		case SDLK_a: // izquierda
			if (controlMoveX == -1) {
				controlMoveX = 0;
			}
			break;
		case SDLK_w: // arriba
			if (controlMoveY == -1) {
				controlMoveY = 0;
			}
			break;
		case SDLK_s: // abajo
			if (controlMoveY == 1) {
				controlMoveY = 0;
			}
			break;
		}

	}
}