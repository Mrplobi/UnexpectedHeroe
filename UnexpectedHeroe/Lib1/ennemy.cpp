#include "stdafx.h"
#include "ennemy.h"
#include <iostream>

Ennemy::Ennemy(Spell* attack, std::string Name, int HP, int MP, sf::Sprite sprite) : Character(Name, HP, MP, sprite) {
	if (attack->available() == false) {
		this->attack = attack;
	}
}

void Ennemy::hit(Steve* target) {
	target->getHit(attack->getDamage());
	attack->graphic();
}

void Ennemy::getHit(int damage){
	HP -= damage;
	if (HP <= 0) {
		onDeath();
	}
}

Spell * Ennemy::getSpell()
{
	return attack;
}

void Ennemy::onDeath() {
	//tout le bordel quand il meurt
	std::cout << Name << "dead" << std::endl;
}
