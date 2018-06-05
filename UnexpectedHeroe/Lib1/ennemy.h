#pragma once
#include "spell.h"
#include "character.h"
#include "steve.h"

class Ennemy : public Character{
private:
	Spell* attack;
public :
	Ennemy(Spell* attack);
	void hit(Steve*	target);
	void getHit(int damage);
	void onDeath();
};