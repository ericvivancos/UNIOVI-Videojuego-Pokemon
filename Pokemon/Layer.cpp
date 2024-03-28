
#include "Layer.h"

Layer::Layer(Game* game) {
	if (game) {
		this->game = game;
	}
	else {
		std::cerr << "Error: Se intentó crear una capa sin un objeto Game válido.\n";
	}
	
}