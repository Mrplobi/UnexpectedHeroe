#pragma once
#include <string>
#include <pugixml.hpp>

class Steve;

class Spell {
private:
	std::string Name;
	int cost;
	int damage;
	bool forSteve;
public:
	//Spell(std::string Name, int cost, int damage, bool forSteve);
	Spell(pugi::xml_node &node);
	void graphic(); //affiche l'image de l'attaque
	std::string getName();
	int getDamage();
	int getCost();
	bool available();
};