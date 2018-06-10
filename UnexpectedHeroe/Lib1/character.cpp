#include "stdafx.h"
#include "character.h"

Character::Character(std::string Name, int HP, int MP, float posx, float posy, float sizex, float sizey, float density, float friction, float restitution, sf::Color color, b2World& theWorld) :
			Name(Name), HP(HP), MP(MP), color(color){

	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(posx + sizex / 2, posy + sizey / 2);
	b2FixtureDef myFixtureDef;
	b2PolygonShape boxShape;
	boxShape.SetAsBox(sizex/2, sizey/2);
	myFixtureDef.shape = &boxShape;
	myFixtureDef.density = density;
	myFixtureDef.friction = friction;
	myFixtureDef.restitution = restitution;
	myBody = theWorld.CreateBody(&myBodyDef);
	myBody->CreateFixture(&myFixtureDef);
	myShape = sf::RectangleShape(sf::Vector2f(sizex, sizey));
	myShape.setPosition(posx, posy);
	myShape.setFillColor(color);
	myShape.setOutlineColor(sf::Color::Black);
	myShape.setOutlineThickness(-1);
}

Character::Character(pugi::xml_node &node, b2World& theWorld, sf::Color color) :
	Name(node.attribute("Name").as_string()),
	HP(node.attribute("HP").as_int()),
	MP(node.attribute("MP").as_int()) {
	float posx = node.attribute("posx").as_float();
	float posy = node.attribute("posy").as_float();
	float sizex = node.attribute("sizex").as_float();
	float sizey = node.attribute("sizey").as_float();
	float density = node.attribute("density").as_float();
	float friction = node.attribute("friction").as_float();
	float restitution = node.attribute("restitution").as_float();
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(posx + sizex/2, posy + sizey/2);
	b2FixtureDef myFixtureDef;
	b2PolygonShape boxShape;
	boxShape.SetAsBox(sizex/2, sizey/2);
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

b2Body* Character::getBody() {
	return myBody;
}

sf::RectangleShape& Character::getShape() {
	return myShape;
}

void Character::jump()
{
}
