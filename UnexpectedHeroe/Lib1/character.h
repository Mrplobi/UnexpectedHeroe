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
		Character(std::string Name, int HP, int MP, int Damage, int range);
		virtual ~Character();
		virtual void getHit();
};