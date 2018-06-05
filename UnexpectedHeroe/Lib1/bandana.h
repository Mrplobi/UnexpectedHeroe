#pragma once
#include <string>

class Steve;
class Bandana {
	private:
		std::string Name;
		//image
		int bonusDamage;
		int bonusCost;
		int bonusHP;
		int bonusMP;
	public:
		Bandana(std::string Name, int bonusDamage, int bonusCost, int bonusHP, int bonusMP, int bonusJump);
		int getBonusDamage();
		int getBonusCost();
		int getBonusHP();
		int getBonusMP();
};