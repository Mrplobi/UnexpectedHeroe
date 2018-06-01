#pragma once
#include <string>
#include "character.h"

class Heroe : public Character{
private:
	std::string textOnHit();
	std::string textOnSpeak();
public:
	void getHit();
};