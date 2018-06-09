#pragma once
#include <string>

class Steve;

class Spell {
private:
	std::string Name;
	int cost;
	int damage;
	bool forSteve;
public:
	Spell(std::string Name, int cost, int damage, bool forSteve);
	void graphic(); //affiche l'image de l'attaque
	std::string getName();
	int getDamage();
	int getCost();
	bool available();
};