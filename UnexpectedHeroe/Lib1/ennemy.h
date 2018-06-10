#pragma once
#include "spell.h"
#include "character.h"
#include "steve.h"

class Ennemy : public Character{
private:
	Spell* attack;
public :
	//Ennemy(Spell* attack, std::string Name, int HP, int MP, sf::Sprite sprite, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld);
	Ennemy(pugi::xml_node &node, b2World& theWorld, Spell* attac, sf::Color color);
	void hit();
	void getHit(int damage);
	Spell* getSpell();
	void onDeath();
};