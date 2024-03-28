#include "DialogManager.h"
#include <iostream>

DialogManager::DialogManager()
	: currentDialogIndex(0) {
	dialogs.push_back("¡Hola, soy el primer diálogo!");
	dialogs.push_back("¡Me alegra que pienses así!");
	dialogs.push_back("¡Vaya! ¡Eso es inesperado!");
}
void DialogManager::startDialog()
{
	currentDialogIndex = 0;
}
void DialogManager::advanceDialog() {
	if (currentDialogIndex < dialogs.size() - 1) {
		currentDialogIndex++;
	}
	else {
		std::cout << "Fin de los diálogos." << std::endl;
	}
}
const std::string& DialogManager::getCurrentDialog() const {
	return dialogs[currentDialogIndex];
}