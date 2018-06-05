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
		Steve(Bandana* equipement, std::vector<Spell*> listOfSpellAvailable, int numberOfJump, sf::Sprite sprite);
		void getHit(int Damage);
		void jump();
		int getNumberOfJump();
		void attack(Character* target, Spell* spellUsed);
		void newSpell(Spell* spell);
		Spell* getSpell(int indice);
		std::vector<Spell*> getList();
		Bandana* getEquipement();
		void equip(Bandana* bandana);
		void onDeath();
};