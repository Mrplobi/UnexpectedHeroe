#include "stdafx.h"
#include "heroe.h"
#include <iostream>

Heroe::Heroe(std::string textOnHit, std::string textOnSpeak, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld) : 
			Character("Lea", 10000, 1, posx, posy, sizex, sizey, density, friction, restitution, color, theWorld){
	textOnHit = textOnHit;
	textOnSpeak = textOnSpeak;
	myBody->SetUserData(this);
}

void Heroe::getHit(int Damage) {
	HP = 0;
	std::cout << this->textOnHit << std::endl;
}

void Heroe::talkedTo() {
	std::cout << this->textOnSpeak << std::endl;
}

void Heroe::onDeath() {
	std::cout << "je me meurs" << std::endl;
}