#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"


class Character {
	protected:
		std::string Name;
		int HP;
		int MP;
		sf::Sprite sprite;
		b2Body* myBody; 
	public:
		Character(std::string Name, int HP, int MP, sf::Sprite sprite, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, b2World* theWorld);
		virtual void getHit(int Damage) = 0;
		virtual void onDeath();
		std::string getName();
		int& getHP();
		int& getMP();
		//virtual ~Character() = 0;
};