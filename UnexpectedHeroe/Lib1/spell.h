#pragma once
#include <string>

class Steve;

class Spell {
private:
	std::string Name;
	int cost;
	int damage;
	float range;
	bool forSteve;
public:
	Spell(std::string Name, int cost, int damage, float range, bool forSteve);
	void graphic(); //affiche l'image de l'attaque
	std::string getName();
	int getDamage();
	float getRange();
	int getCost();
	bool available();
};