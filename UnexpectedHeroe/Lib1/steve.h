#pragma once
#include "bandana.h"
#include "spell.h"
#include "character.h"
#include <vector>

class steve : public Character{
	private :
		Bandana* equipement;
		std::vector<Spell> listOfSpellAvailable;
		int numberOfJump;
		int jumpHeight;
	public :
		void getHit(int Damage);
		void Jump();
		void attack(Spell* spell);
		void newSpell(Spell* spell);
		void equip(Bandana* bandana);
		void setHP();
		void setJump();
		void setMP();
};