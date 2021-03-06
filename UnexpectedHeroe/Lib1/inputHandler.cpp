#include "stdafx.h"
#include "inputHandler.h"
#include "allCommands.h"
#include "SFML\System.hpp"
#include <iostream>

InputHandler::InputHandler()
{
	JumpCommand jump;
	Attack1Command attack1;
	Attack2Command attack2;
	MoveRight right;
	MoveLeft left;
	Button1 = std::make_unique<JumpCommand>(jump);
	Button2 = std::make_unique<Attack1Command>(attack1);
	Button3 = std::make_unique<Attack2Command>(attack2);
	AxisXp = std::make_unique<MoveRight>(right);
	AxisXm = std::make_unique<MoveLeft>(left);
	pressed = false;
}

void InputHandler::pile() {
	if (sf::Joystick::isConnected(0))
	{
		//Gamepad
		if (sf::Joystick::isButtonPressed(0, 1))
		{
			commandPile.push_back(Button1->getAction());
		}
		if (sf::Joystick::isButtonPressed(0, 2))
		{
			commandPile.push_back(Button2->getAction());
		}
		if (sf::Joystick::isButtonPressed(0, 3))
		{
			commandPile.push_back(Button3->getAction());
		}
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		if (x > 0.2) {
			commandPile.push_back(AxisXp->getAction());
		}
		if (x < 0.2) {
			commandPile.push_back(AxisXm->getAction());
		}
	}
	else {
		//Keyboard
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			commandPile.push_back(Button1->getAction());
			//std::cout << "jump" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
			commandPile.push_back(Button2->getAction());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			commandPile.push_back(Button3->getAction());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			commandPile.push_back(AxisXp->getAction());
			std::cout << "urg" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			commandPile.push_back(AxisXm->getAction());
			std::cout << "NOOOOO" << std::endl;
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			commandPile.push_back(stopXMove);
		}
	}
}

std::vector<Actions>& InputHandler::getPile() {
	return commandPile;
}