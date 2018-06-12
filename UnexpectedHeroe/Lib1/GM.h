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
	std::vector<Ennemy> listOfEnnemies;
	std::vector<Wall> walls;
	std::vector<Villager> people;
	Steve steve;
	InputHandler handler;
public:
	GM();
	void gameLoop();
	void pitOfDoom();
	void processInput(sf::RenderWindow& window, sf::Event event);
	void updateGraph(sf::RenderWindow& window, sf::View view);
	void render();
	void worldChange(int levelNb);
};