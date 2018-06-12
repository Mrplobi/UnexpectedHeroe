#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"
#include <iostream>
#include <pugixml.hpp>


class Character {
	protected:
		std::string Name;
		int HP;
		int MP;
		b2Body* myBody;
		sf::Color color;
		sf::RectangleShape myShape;
	public:
		Character(std::string Name, int HP, int MP, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld);
		Character(pugi::xml_node &node, b2World& theWorld, sf::Color color);
		virtual void getHit(int Damage) = 0;
		virtual void onDeath();
		std::string& getName();
		int& getHP();
		int& getMP();
		virtual void jump();
		void draw(sf::RenderWindow& window);
		b2Body* getBody();
		sf::RectangleShape& getShape();
		//virtual ~Character() = 0;
};