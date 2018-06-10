#include "stdafx.h"
#include "spell.h"

//Spell::Spell(std::string Name, int cost, int damage, bool forSteve) {
//	this->Name = Name;
//	this->cost = cost;
//	this->damage = damage;
//	this->forSteve = forSteve;
//}

Spell::Spell(pugi::xml_node &node) : 
	Name(node.attribute("Name").as_string()), 
	cost(node.attribute("cost").as_int()), 
	damage(node.attribute("damage").as_int()), 
	forSteve(node.attribute("forSteve").as_bool()) {
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

bool Spell::available() {
	return forSteve;
}