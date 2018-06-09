#include "stdafx.h"
#include "villager.h"
#include <iostream>

Villager::Villager(std::string textOnHit, std::string textOnSpeak, std::string Name, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld) :
			Character(Name, 1, 0, posx, posy, sizex, sizey, density, friction, restitution, color, theWorld) {
	textOnHit = textOnHit;
	textOnSpeak = textOnSpeak;
	myBody->SetUserData(this);
}

void Villager::getHit(int Damage) {
	std::cout << textOnHit << std::endl;
}

void Villager::talkedTo() {
	std::cout << textOnSpeak << std::endl;
}