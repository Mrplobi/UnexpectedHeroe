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
		void attack();
		void attack2();
		void moveRight();
		void moveLeft();
		void newSpell(Spell* spell);
		Spell* getSpell(int indice);
		std::vector<Spell*>& getListEquiped();
		std::vector<Spell*>& getListSpell();
		Bandana* getEquipement();
		void equip(Bandana* bandana);
		void onDeath();
};