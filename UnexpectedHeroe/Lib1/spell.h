#pragma once
#include <string>

class Steve;

class Spell {
private:
	std::string Name;
	int cost;
	int damage;
	float range;
public:
	Spell(std::string Name, int cost, int damage, float range);
	void graphic(); //affiche l'image de l'attaque
	int getDamage();
	float getRange();
	int getCost();
};