#pragma once
#include "spell.h"
#include "character.h"
#include "steve.h"

class Ennemy : public Character{
private:
	Spell* attack;
public :
	Ennemy(Spell* attack, std::string Name, int HP, int MP, sf::Sprite sprite);
	void hit(Steve*	target);
	void getHit(int damage);
	Spell* getSpell();
	void onDeath();
};