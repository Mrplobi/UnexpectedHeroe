#pragma once
#include "spell.h"

class Ennemy : public Character{
private:
	int damage;
	int range;
public :
	void getHit(Spell spell);
};