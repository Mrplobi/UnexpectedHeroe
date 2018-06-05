#include "stdafx.h"
#include "ennemy.h"
#include <iostream>

Ennemy::Ennemy(Spell* attack) : Character(Name, HP, MP, sprite) {
	this->attack = attack;
}

void Ennemy::hit(Steve* target) {
	target->getHit(attack->getDamage());
	attack->graphic();
}

void Ennemy::getHit(int damage){
	this->HP -= damage;
	if (this->HP <= 0) {
		this->onDeath();
	}
}

void Ennemy::onDeath() {
	//tout le bordel quand il meurt
	std::cout << "chuis mort" << std::endl;
}
