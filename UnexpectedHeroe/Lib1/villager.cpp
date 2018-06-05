#include "stdafx.h"
#include "villager.h"
#include <iostream>

Villager::Villager(std::string textOnHit, std::string textOnSpeak, std::string Name, sf::Sprite sprite) : Character(Name, 1, 0, sprite) {
	this->textOnHit = textOnHit;
	this->textOnSpeak = textOnSpeak;
}

void Villager::getHit(int Damage) {
	std::cout << textOnHit << std::endl;
}

void Villager::talkedTo() {
	std::cout << textOnSpeak << std::endl;
}