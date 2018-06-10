#pragma once
#include <SFML\Graphics.hpp>
#include <pugixml.hpp>
#include <time.h>
#include "Box2D\Box2D.h"

class Wall {
private:
	float XtopLeft;
	float YtopLetf;
	float XbotRight;
	float YbotRight;
	bool isFloor;
	float friction;
	float restitution;
	b2Body* myBody;
	sf::Color color;
	sf::RectangleShape myShape;
public:
	Wall(float xtopL, float ytopL, float xbotR, float ybotR, bool floor, float friction, float restitution, sf::Color color, b2World* DAWARUDO);
	Wall(pugi::xml_node &node, b2World& DAWARUDO);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape getShape();
	b2Body* getBody();
};