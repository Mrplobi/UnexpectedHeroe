#include "stdafx.h"
#include "steve.h"

Steve::Steve(Bandana* equipement, std::vector<Spell*> listOfSpellAvailable, int numberOfJump) : Character(Name, HP, MP, sprite) {
	this->equipement = equipement;
	this->listOfSpellAvailable = listOfSpellAvailable;
	this->numberOfJump = numberOfJump;
}

void Steve::jump() {

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
	listOfSpellAvailable.push_back(newSpell);
}

void Steve::equip(Bandana* newBandana) {
	HP -= equipement->getBonusHP();
	MP -= equipement->getBonusMP();
	equipement = newBandana;
	HP += equipement->getBonusHP();
	MP += equipement->getBonusMP();
}