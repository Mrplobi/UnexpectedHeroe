#pragma once
#include <string>
#include <SFML\Graphics.hpp>


class Character {
	protected:
		std::string Name;
		int HP;
		int MP;
		sf::Sprite sprite;
	public:
		Character(std::string Name, int HP, int MP, sf::Sprite sprite);
		virtual void getHit(int Damage) = 0;
		virtual void onDeath() = 0;
		virtual ~Character() = 0;
};