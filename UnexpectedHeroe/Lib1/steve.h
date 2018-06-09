#pragma once
#include "bandana.h"
#include "spell.h"
#include "character.h"
#include <vector>

class Steve : public Character{
	private :
		Bandana* equipement;
		std::vector<Spell*> listOfSpellAvailable;
		std::vector<Spell*> spellEquiped;
		int maxNumberOfJump;
		int numberOfJump;
	public :
		Steve(Bandana* equipement, std::vector<Spell*> listOfSpellAvailable, std::vector<Spell*> spellEquiped, int numberOfJump, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld);
		void getHit(int Damage);
		void jump();
		int getNumberOfJump();
		void attack(Spell* spellUsed);
		void attack2(Spell* SpellUsed);
		void newSpell(Spell* spell);
		Spell* getSpell(int indice);
		std::vector<Spell*> getListEquiped();
		std::vector<Spell*> getListSpell();
		Bandana* getEquipement();
		void equip(Bandana* bandana);
		void onDeath();
};