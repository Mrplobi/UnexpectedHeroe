#include "stdafx.h"
#include "steve.h"
#include <iostream>

Steve::Steve(Bandana* equipement, std::vector<Spell*> listOfSpellAvailable, int numberOfJump, sf::Sprite sprite) : Character("Steve", 100, 50, sprite) {
	this->equipement = equipement;
	this->listOfSpellAvailable = listOfSpellAvailable;
	this->numberOfJump = numberOfJump;
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
