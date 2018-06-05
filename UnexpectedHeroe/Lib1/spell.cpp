#include "stdafx.h"
#include "spell.h"

Spell::Spell(std::string Name, int cost, int damage, float range) {
	this->Name = Name;
	this->cost = cost;
	this->damage = damage;
	this->range = range;
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