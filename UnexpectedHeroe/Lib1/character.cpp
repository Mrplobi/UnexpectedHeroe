#include "stdafx.h"
#include "character.h"

Character::Character(std::string Name, int HP, int MP, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld) :
			Name(Name), HP(HP), MP(MP), color(color){

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
	myBody = theWorld.CreateBody(&myBodyDef);
	myBody->CreateFixture(&myFixtureDef);
	myShape = sf::RectangleShape(sf::Vector2f(sizex, sizey));
	myShape.setPosition(posx, posy);
	myShape.setFillColor(color);
	myShape.setOutlineColor(sf::Color::Black);
	myShape.setOutlineThickness(-1);
}

void Character::draw(sf::RenderWindow& window) {
	window.draw(myShape);
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

void Character::jump()
{
}
