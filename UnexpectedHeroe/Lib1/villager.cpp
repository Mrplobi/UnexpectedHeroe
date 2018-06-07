#include "stdafx.h"
#include "villager.h"
#include <iostream>

Villager::Villager(std::string textOnHit, std::string textOnSpeak, std::string Name, sf::Sprite sprite, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, b2World* theWorld) : 
			Character(Name, 1, 0, sprite, posx, posy, sizex, sizey, density, friction, restitution, theWorld) {
	this->textOnHit = textOnHit;
	this->textOnSpeak = textOnSpeak;
}

void Villager::getHit(int Damage) {
	std::cout << textOnHit << std::endl;
}

void Villager::talkedTo() {
	std::cout << textOnSpeak << std::endl;
}