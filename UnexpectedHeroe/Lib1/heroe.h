#pragma once
#include <string>
#include "character.h"

class Heroe : public Character{
private:
	std::string textOnHit;
	std::string textOnSpeak;
public:
	Heroe(std::string textOnHit, std::string textOnSpeak);
	void getHit(int Damage);
	void talkedTo();
	void onDeath();
};