#pragma once
#include "classes.h"
#include "Box2D\Box2D.h"
#include <vector>
#include <string>
#include <SFML\Graphics.hpp>

class GM {
private:
	b2World DAWARUDO;
	std::vector<Spell> listOfSpell;
	std::vector<Bandana> listOfBandana;
	std::vector<Ennemy*> listOfEnnemies;
	Steve* steve;
public:
	GM();
	void gameLoop();
	void processInput();
	void updateAll();
	void render();
	void worldChange(int levelNb);
};