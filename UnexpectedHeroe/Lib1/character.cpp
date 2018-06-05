#include "stdafx.h"
#include "character.h"

Character::Character(std::string Name, int HP, int MP, sf::Sprite sprite){
	this->Name = Name;
	this->HP = HP;
	this->MP = MP;
	this->sprite = sprite;
}

void Character::getHit(int Damage)
{
}

void Character::onDeath()
{
}
