#pragma once
#include <string>
#include "character.h"

class Villager : public Character {
private:
	std::string textOnHit;
	std::string textOnSpeak;
public:
	Villager(std::string textOnHit, std::string textOnSpeak);
	void getHit();
	void talkedTo();
};