#include "stdafx.h"
#include "heroe.h"
#include <iostream>

//Heroe::Heroe(std::string textHit, std::string textSpeak, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld) : 
//			Character("Lea", 10000, 1, posx, posy, sizex, sizey, density, friction, restitution, color, theWorld){
//	textHit = textOnHit;
//	textSpeak = textOnSpeak;
//	myBody->SetUserData(this);
//}

Heroe::Heroe(pugi::xml_node &node, b2World theWorld, sf::Color color) : Villager(node, theWorld, color){
	myBody->SetUserData(this);
}

void Heroe::getHit(int Damage) {
	HP = 0;
	std::cout << textOnHit << std::endl;
}

void Heroe::talkedTo() {
	std::cout << textOnSpeak << std::endl;
}

void Heroe::onDeath() {
	std::cout << "je me meurs" << std::endl;
}