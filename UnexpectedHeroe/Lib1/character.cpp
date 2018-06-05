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

std::string Character::getName()
{
	return std::string(Name);
}

int& Character::getHP()
{
	return HP;
}

int& Character::getMP()
{
	return MP;
}
