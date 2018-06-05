#pragma once
#include "bandana.h"
#include "spell.h"
#include "character.h"
#include <vector>

class Steve : public Character{
	private :
		Bandana* equipement;
		std::vector<Spell*> listOfSpellAvailable;
		int numberOfJump;
	public :
		Steve(Bandana* equipement, std::vector<Spell*> listOfSpellAvailable, int numberOfJump);
		void getHit(int Damage);
		void jump();
		void attack(Character* target, Spell* spellUsed);
		void newSpell(Spell* spell);
		void equip(Bandana* bandana);
};