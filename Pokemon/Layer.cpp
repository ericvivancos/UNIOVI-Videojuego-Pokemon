
#include "Layer.h"

Layer::Layer(Game* game) {
	if (game) {
		this->game = game;
	}
	else {
		std::cerr << "Error: Se intent� crear una capa sin un objeto Game v�lido.\n";
	}
	
}