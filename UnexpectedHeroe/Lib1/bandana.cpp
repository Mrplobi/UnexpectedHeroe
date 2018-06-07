#include "stdafx.h"
#include "bandana.h"

Bandana::Bandana() : Name(""), bonusCost(0), bonusDamage(0), bonusHP(0), bonusMP(0), bonusJump(0){
}

Bandana::Bandana(std::string Name, int bonusDamage, int bonusCost, int bonusHP, int bonusMP, int bonusJump)
	: Name(Name), bonusCost(bonusCost), bonusDamage(bonusDamage), bonusHP(bonusHP), bonusMP(bonusMP), bonusJump(bonusJump){
}

const int& Bandana::getBonusDamage()
{
	return bonusDamage;
}

const int& Bandana::getBonusCost()
{
	return bonusCost;
}

const int& Bandana::getBonusHP()
{
	return bonusHP;
}

const int& Bandana::getBonusMP()
{
	return bonusMP;
}

const std::string& Bandana::getName() {
	return Name;
}