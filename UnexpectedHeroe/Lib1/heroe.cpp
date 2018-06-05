#include "stdafx.h"
#include "heroe.h"
#include <iostream>

Heroe::Heroe(std::string textOnHit, std::string textOnSpeak) : Character(Name, HP, MP, sprite){
	this->textOnHit = textOnHit;
	this->textOnSpeak = textOnSpeak;
}

void Heroe::getHit(int Damage) {
	this->HP = 0;
	std::cout << this->textOnHit << std::endl;
}

void Heroe::talkedTo() {
	std::cout << this->textOnSpeak << std::endl;
}

void Heroe::onDeath() {
	std::cout << "je me meurs" << std::endl;
}