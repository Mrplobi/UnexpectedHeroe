#pragma once
#include <string>
#include <pugixml.hpp>

class Steve;
class Bandana {
	private:
		std::string Name;
		//image
		const int bonusDamage;
		const int bonusCost;
		const int bonusHP;
		const int bonusMP;
		const int bonusJump;
	public:
		Bandana();
		//Bandana(std::string Name, int bonusDamage, int bonusCost, int bonusHP, int bonusMP, int bonusJump);
		Bandana(pugi::xml_node &node);
		const int& getBonusDamage();
		const int& getBonusCost();
		const int& getBonusHP();
		const int& getBonusMP();
		const int& getBonusJump();
		const std::string& getName();
};