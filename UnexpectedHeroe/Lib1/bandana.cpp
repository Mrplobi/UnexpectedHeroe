#include "stdafx.h"
#include "bandana.h"

Bandana::Bandana(std::string Name, int bonusDamage, int bonusCost, int bonusHP, int bonusMP, int bonusJump) {
	this->Name = Name;
	this->bonusDamage = bonusDamage;
	this->bonusCost = bonusCost;
	this->bonusHP = bonusHP;
	this->bonusMP = bonusMP;
}

int Bandana::getBonusDamage()
{
	return bonusDamage;
}

int Bandana::getBonusCost()
{
	return bonusCost;
}

int Bandana::getBonusHP()
{
	return bonusHP;
}

int Bandana::getBonusMP()
{
	return bonusMP;
}
