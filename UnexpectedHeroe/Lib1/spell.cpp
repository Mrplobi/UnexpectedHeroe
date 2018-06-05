#include "stdafx.h"
#include "spell.h"

Spell::Spell(std::string Name, int cost, int damage, float range, bool forSteve) {
	this->Name = Name;
	this->cost = cost;
	this->damage = damage;
	this->range = range;
	this->forSteve = forSteve;
}

void Spell::graphic()
{
}

std::string Spell::getName()
{
	return std::string(Name);
}

int Spell::getCost() {
	return this->cost;
}

int Spell::getDamage() {
	return this->damage;
}

float Spell::getRange() {
	return this->range;
}

bool Spell::available() {
	return forSteve;
}