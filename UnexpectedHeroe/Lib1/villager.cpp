#include "stdafx.h"
#include "villager.h"
#include <iostream>

//Villager::Villager(std::string textOnHit, std::string textOnSpeak, std::string Name, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld) :
//			Character(Name, 1, 0, posx, posy, sizex, sizey, density, friction, restitution, color, theWorld) {
//	textOnHit = textOnHit;
//	textOnSpeak = textOnSpeak;
//	myBody->SetUserData(this);
//}

Villager::Villager(pugi::xml_node &node, b2World& theWorld, sf::Color color ) : Character(node, theWorld, color),
		textOnHit(node.attribute("textHit").as_string()),
		textOnSpeak(node.attribute("textSpeak").as_string()){
	myBody->SetUserData(this);
}

void Villager::getHit(int Damage) {
	std::cout << textOnHit << std::endl;
}

void Villager::talkedTo() {
	std::cout << textOnSpeak << std::endl;
}

std::string Villager::getTextHit()
{
	return textOnHit;
}

std::string Villager::getTextTalk()
{
	return textOnSpeak;
}
