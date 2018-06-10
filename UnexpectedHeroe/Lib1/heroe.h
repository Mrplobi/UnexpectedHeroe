#pragma once
#include <string>
#include "villager.h"

class Heroe : public Villager{
public:
	//Heroe(std::string textOnHit, std::string textOnSpeak, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld);
	Heroe(pugi::xml_node &node, b2World theWorld, sf::Color color);
	void getHit(int Damage);
	void talkedTo();
	void onDeath();
};