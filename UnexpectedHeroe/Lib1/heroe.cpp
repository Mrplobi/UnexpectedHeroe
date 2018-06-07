#include "stdafx.h"
#include "heroe.h"
#include <iostream>

Heroe::Heroe(std::string textOnHit, std::string textOnSpeak, sf::Sprite sprite, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, b2World* theWorld) : 
			Character("Lea", 10000, 1, sprite, posx, posy, sizex, sizey, density, friction, restitution, theWorld){
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