#include "stdafx.h"
#include "steve.h"
#include <iostream>

Steve::Steve(Bandana* equipement, std::vector<Spell*> listOfSpellAvailable, std::vector<Spell*> spellEquiped, int numberOfJump, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld) :
			Character("Steve", 5, 10, posx, posy, sizex, sizey, density, friction, restitution, color, theWorld), 
			equipement(equipement), listOfSpellAvailable(listOfSpellAvailable),
			maxNumberOfJump(numberOfJump),
			numberOfJump(numberOfJump) {
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

void Steve::attack() { 
	spellEquiped[0]->graphic();
	MP -= (spellEquiped[0]->getCost() - equipement->getBonusCost());
}

void Steve::attack2() {
	spellEquiped[1]->graphic();
	MP -= (spellEquiped[1]->getCost() - equipement->getBonusCost());
}

void Steve::moveRight() {
	myBody->SetLinearVelocity(b2Vec2(10, 0));
}

void Steve::moveLeft() {
	myBody->SetLinearVelocity(b2Vec2(-10, 0));
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

std::vector<Spell*> Steve::getListEquiped()
{
	return spellEquiped;
}

std::vector<Spell*> Steve::getListSpell()
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