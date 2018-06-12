#include "stdafx.h"
#include "bandana.h"
#include <pugixml.hpp>

Bandana::Bandana() : Name(""), bonusCost(0), bonusDamage(0), bonusHP(0), bonusMP(0), bonusJump(0){
}

//Bandana::Bandana(std::string Name, int bonusDamage, int bonusCost, int bonusHP, int bonusMP, int bonusJump)
//	: Name(Name), bonusCost(bonusCost), bonusDamage(bonusDamage), bonusHP(bonusHP), bonusMP(bonusMP), bonusJump(bonusJump){
//}

Bandana::Bandana(pugi::xml_node &node) : 
	Name(node.attribute("Name").as_string()), 
	bonusCost(node.attribute("bonusCost").as_int()), 
	bonusDamage(node.attribute("bonusDamage").as_int()), 
	bonusHP(node.attribute("bonusHP").as_int()), 
	bonusMP(node.attribute("bonusMP").as_int()), 
	bonusJump(node.attribute("bonusJump").as_int()) {
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

const int& Bandana::getBonusJump()
{
	return bonusJump;
}

const std::string& Bandana::getName() {
	return Name;
}