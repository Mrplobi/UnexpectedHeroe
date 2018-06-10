#include "stdafx.h"
#include "wall.h"

Wall::Wall(float xtopL, float ytopL, float xbotR, float ybotR, bool floor, float friction, float restitution, sf::Color color, b2World* DAWARUDO) : XtopLeft(xtopL), YtopLetf(ytopL), XbotRight(xbotR), YbotRight(ybotR), isFloor(floor), color(color) {
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set((XbotRight - XtopLeft) / 2, (YtopLetf - YbotRight) / 2);
	b2FixtureDef myFixtureDef;
	b2PolygonShape boxShape;
	boxShape.SetAsBox(XbotRight - XtopLeft, YtopLetf - YbotRight);
	myFixtureDef.shape = &boxShape;
	myFixtureDef.friction = friction,
	myFixtureDef.restitution = restitution;
	myBody = DAWARUDO->CreateBody(&myBodyDef);
	myBody->CreateFixture(&myFixtureDef);
	myShape = sf::RectangleShape(sf::Vector2f((XbotRight - XtopLeft), (YtopLetf - YbotRight)));
	myShape.setPosition(XtopLeft, YtopLetf);
	myShape.setFillColor(color);
	myShape.setOutlineColor(sf::Color::Black);
	myShape.setOutlineThickness(-1);
};

Wall::Wall(pugi::xml_node &node, b2World& DAWARUDO, sf::Color color) : 
		XtopLeft(node.attribute("xtopL").as_float()), 
		YtopLetf(node.attribute("ytopL").as_float()), 
		XbotRight(node.attribute("xbotR").as_float()), 
		YbotRight(node.attribute("xbotR").as_float()), 
		isFloor(node.attribute("floor").as_bool()) {
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set((XbotRight - XtopLeft) / 2, (YtopLetf - YbotRight) / 2);
	b2FixtureDef myFixtureDef;
	b2PolygonShape boxShape;
	boxShape.SetAsBox(XbotRight - XtopLeft, YtopLetf - YbotRight);
	myFixtureDef.shape = &boxShape;
	myFixtureDef.friction = friction,
	myFixtureDef.restitution = restitution;
	myBody = DAWARUDO.CreateBody(&myBodyDef);
	myBody->CreateFixture(&myFixtureDef);
	myShape = sf::RectangleShape(sf::Vector2f((XbotRight - XtopLeft), (YtopLetf - YbotRight)));
	myShape.setPosition(XtopLeft, YtopLetf);
	myShape.setFillColor(color);
	myShape.setOutlineColor(sf::Color::Black);
	myShape.setOutlineThickness(-1);
}

void Wall::draw(sf::RenderWindow& window) {
	window.draw(myShape);
}