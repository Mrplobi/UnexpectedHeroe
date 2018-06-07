#pragma once
#include <string>
#include "character.h"

class Villager : public Character {
private:
	std::string textOnHit;
	std::string textOnSpeak;
public:
	Villager(std::string textOnHit, std::string textOnSpeak, std::string Name, sf::Sprite sprite, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, b2World* theWorld);
	void getHit(int Damage);
	void talkedTo();
};