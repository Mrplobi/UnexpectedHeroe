#include "stdafx.h"
#include "character.h"

Character::Character(std::string Name, int HP, int MP, sf::Sprite sprite, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, b2World* theWorld){
	Name = Name;
	HP = HP;
	MP = MP;
	sprite = sprite;
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(posx, posy);
	b2FixtureDef myFixtureDef;
	b2PolygonShape boxShape;
	boxShape.SetAsBox(sizex, sizey);
	myFixtureDef.shape = &boxShape;
	myFixtureDef.density = density;
	myFixtureDef.friction = friction,
	myFixtureDef.restitution = restitution;
	myBody = theWorld->CreateBody(&myBodyDef);
	myBody->CreateFixture(&myFixtureDef);
}

void Character::getHit(int Damage)
{
}

void Character::onDeath()
{
}

std::string Character::getName()
{
	return std::string(Name);
}

int& Character::getHP()
{
	return HP;
}

int& Character::getMP()
{
	return MP;
}
