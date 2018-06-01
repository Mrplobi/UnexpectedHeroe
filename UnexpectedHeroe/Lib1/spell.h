#pragma once
#include <string>

class Steve;

class Spell {
public:
	std::string Name;
	int cost;
	int damage;
	int range;
private:
	void effect();
};