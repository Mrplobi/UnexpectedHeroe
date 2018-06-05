#include "stdafx.h"
#include "villager.h"
#include <iostream>

Villager::Villager(std::string textOnHit, std::string textOnSpeak) : Character(Name, HP, MP, sprite) {
	this->textOnHit = textOnHit;
	this->textOnSpeak = textOnSpeak;
}

void Villager::getHit() {
	std::cout << textOnHit << std::endl;
}

void Villager::talkedTo() {
	std::cout << textOnSpeak << std::endl;
}