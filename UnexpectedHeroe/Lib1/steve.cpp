#include "stdafx.h"
#include "steve.h"
#include <iostream>

Steve::Steve(Bandana* equipement, std::vector<Spell*> listOfSpellAvailable, std::vector<Spell*> spellEquiped, int numberOfJump, sf::Sprite sprite, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, b2World* theWorld) :
			Character("Steve", 5, 10, sprite, posx, posy, sizex, sizey, density, friction, restitution, theWorld) {
	this->equipement = equipement;
	this->listOfSpellAvailable = listOfSpellAvailable;
	this->numberOfJump = numberOfJump;
	myBody->SetUserData(this);
}

void Steve::jump() {
	if (numberOfJump > 0) {
		float impulse = myBody->GetMass() * 10;
		myBody->ApplyLinearImpulse(b2Vec2(0, impulse), myBody->GetWorldCenter(), true);
	}
}

int Steve::getNumberOfJump()
{
	return numberOfJump;
}

void Steve::attack(Spell* spellUsed) { 
	spellUsed->graphic();
	MP -= (spellUsed->getCost() - equipement->getBonusCost());
}

void Steve::attack2(Spell* spellUsed) {
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
