#pragma once
#include <string>
#include "character.h"

class Heroe : public Character{
private:
	std::string textOnHit;
	std::string textOnSpeak;
public:
	Heroe(std::string textOnHit, std::string textOnSpeak, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld);
	void getHit(int Damage);
	void talkedTo();
	void onDeath();
};