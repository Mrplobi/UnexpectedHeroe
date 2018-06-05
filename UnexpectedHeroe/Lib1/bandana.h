#pragma once
#include <string>

class Steve;
class Bandana {
	private:
		std::string Name;
		//image
		const int bonusDamage;
		const int bonusCost;
		const int bonusHP;
		const int bonusMP;
	public:
		Bandana();
		Bandana(std::string Name, int bonusDamage, int bonusCost, int bonusHP, int bonusMP);
		const int& getBonusDamage();
		const int& getBonusCost();
		const int& getBonusHP();
		const int& getBonusMP();
		const std::string& getName();
};