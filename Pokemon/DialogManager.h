#pragma once
#include <vector>
#include <string>
class DialogManager
{
public:
	DialogManager();
	void startDialog();
	void advanceDialog();
	const std::string& getCurrentDialog() const;
	std::vector<std::string> dialogs;
	size_t currentDialogIndex;
};

