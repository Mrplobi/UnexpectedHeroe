#pragma once
#include <string>
#include "character.h"

class Villager : public Character {
protected:
	std::string textOnHit;
	std::string textOnSpeak;
public:
	//Villager(std::string textOnHit, std::string textOnSpeak, std::string Name, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld);
	Villager(pugi::xml_node &node, b2World& theWorld, sf::Color color);
	virtual void getHit(int Damage);
	void talkedTo();
	std::string getTextHit();
	std::string getTextTalk();
};