#pragma once
#include "allCommands.h"
#include <vector>
#include <memory>

class InputHandler {
private:
	std::vector<Actions> commandPile;
	std::unique_ptr<Command> Button1;
	std::unique_ptr<Command> Button2;
	std::unique_ptr<Command> Button3;
	std::unique_ptr<Command> AxisXp;
	std::unique_ptr<Command> AxisXm;
	bool pressed;
public:
	InputHandler();
	void pile();
	std::vector<Actions>& getPile();
};