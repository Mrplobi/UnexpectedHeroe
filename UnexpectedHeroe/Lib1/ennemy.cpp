#include "stdafx.h"
#include "ennemy.h"
#include <iostream>

//Ennemy::Ennemy(Spell* attack, std::string Name, int HP, int MP, sf::Sprite sprite, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld) : 
//			Character(Name, HP, MP, posx, posy, sizex, sizey, density, friction, restitution, color, theWorld) {
//	if (attack->available() == false) {
//		this->attack = attack;
//	}
//	myBody->SetUserData(this);
//}

Ennemy::Ennemy(pugi::xml_node &node, b2World& theworld, Spell* attac, sf::Color color) : Character(node, theworld, color) {
	if (attac->available() == false) {
		attack = attac;
	}
	myBody->SetUserData(this);
}

void Ennemy::hit() {
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
