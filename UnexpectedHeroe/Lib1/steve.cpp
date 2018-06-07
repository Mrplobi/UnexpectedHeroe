#include "stdafx.h"
#include "steve.h"
#include <iostream>

Steve::Steve(Bandana* equipement, std::vector<Spell*> listOfSpellAvailable, int numberOfJump, sf::Sprite sprite, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, b2World* theWorld) : 
			Character("Steve", 100, 50, sprite, posx, posy, sizex, sizey, density, friction, restitution, theWorld) {
	equipement = equipement;
	listOfSpellAvailable = listOfSpellAvailable;
	numberOfJump = numberOfJump;
	myBody->SetUserData(this);
}

void Steve::jump() {

}

int Steve::getNumberOfJump()
{
	return numberOfJump;
}

void Steve::attack(Character* target, Spell* spellUsed) {
	target->getHit(spellUsed->getDamage() + equipement->getBonusDamage());
	spellUsed->graphic();
	MP -= (spellUsed->getCost() - equipement->getBonusCost());
}

void Steve::getHit(int Damage) {
	HP -= Damage;
}

void Steve::newSpell(Spell* newSpell) {
	if (newSpell->available() == true) {
		listOfSpellAvailable.push_back(newSpell);
	}
}

Spell* Steve::getSpell(int indice)
{
	return listOfSpellAvailable[indice];
}

std::vector<Spell*> Steve::getList()
{
	return listOfSpellAvailable;
}

Bandana * Steve::getEquipement()
{
	return equipement;
}

void Steve::equip(Bandana* newBandana) {
	HP -= equipement->getBonusHP();
	MP -= equipement->getBonusMP();
	equipement = newBandana;
	HP += equipement->getBonusHP();
	MP += equipement->getBonusMP();
}

void Steve::onDeath()
{
	std::cout << "WASTED" << std::endl;
}
