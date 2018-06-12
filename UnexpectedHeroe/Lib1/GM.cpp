#include "stdafx.h"
#include "GM.h"
#include <iostream>

GM::GM() : DAWARUDO(b2Vec2(0, 10)), steve(Steve(&Bandana(), std::vector<Spell*>({}), std::vector<Spell*>({}), 1, 200, 100, 50, 50, 1, 0.5, 0.1, sf::Color::Magenta, DAWARUDO)) {
	InputHandler handler;
}

void GM::gameLoop() {

	//initialisation des assets

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../XML/assets.xml");
	if (result < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc.child("GudShit").child("Bandanas").children()) {
		listOfBandana.push_back(Bandana(i));
	}
	for (auto& i : doc.child("GudShit").child("Spells").children()) {
		listOfSpell.push_back(Spell(i));
	}

	sf::RenderWindow window(sf::VideoMode(1500, 900), "Unexpected Heroe");

	pitOfDoom();

	sf::View view;
	view.setSize(sf::Vector2f(700, 700));
	//window.setView(view2);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();			
		}
		handler.pile();
		processInput(window, event);
		//Gestion des collision et background changes;
		window.clear(sf::Color::White);
		updateGraph(window, view);
		view.setCenter(sf::Vector2f(steve.getBody()->GetPosition().x, steve.getBody()->GetPosition().y));
		window.setView(view);
		window.display();
		DAWARUDO.Step(1/30.f, 8, 3);
	}	
}

void GM::pitOfDoom() {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../XML/The_pit_of_doom.xml");
	if (result < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc.child("Da_Pit_of_DOOOOOOOM").child("World").children()) {
		walls.push_back(Wall(i, DAWARUDO));
	}
	for (auto& i : doc.child("Da_Pit_of_DOOOOOOOM").child("SpookyScary").children()) {
		listOfEnnemies.push_back(Ennemy(i, DAWARUDO, &listOfSpell[2], sf::Color::Black));
	}
	for (auto& i : doc.child("Da_Pit_of_DOOOOOOOM").child("folks").children()) {
		if (strcmp(i.name(),"Villager") == 0) {
			people.push_back(Villager(i, DAWARUDO, sf::Color::Green));
		}
		else if (strcmp(i.name(),"Heroe") == 0 ) {
			people.push_back(Heroe(i, DAWARUDO, sf::Color::Blue));
		}
	}
	//steve.getBody()->GetPosition().Set();
}


void GM::processInput(sf::RenderWindow& window, sf::Event event) {
	for (auto& i : handler.getPile()) {
		if (i == Jump) {
			steve.jump();
		}
		if (i == SteveAttack1)
			steve.attack();
		if (i == SteveAttack2)
			steve.attack2();
		if (i == MovementRigth)
			steve.moveRight();
		if (i == MovementLeft)
			steve.moveLeft();
		if (i == stopXMove)
			steve.getBody()->SetLinearVelocity(b2Vec2(0, steve.getBody()->GetLinearVelocity().y));
	}
	handler.getPile().clear();
}

void GM::updateGraph(sf::RenderWindow &window, sf::View view) {
	steve.getShape().setPosition(steve.getBody()->GetPosition().x - steve.getShape().getSize().x/2, steve.getBody()->GetPosition().y - steve.getShape().getSize().y/2);
	steve.draw(window);
	if (!(listOfEnnemies.size() == 0)) {
		for (auto& i : listOfEnnemies) {
			i.getShape().setPosition(i.getBody()->GetPosition().x - i.getShape().getSize().x/2, i.getBody()->GetPosition().y - i.getShape().getSize().y/2);
			i.draw(window);
		}
	}
	if (!people.size() == 0) {
		for (auto& i : people) {
			i.getShape().setPosition(i.getBody()->GetPosition().x - i.getShape().getSize().x/2, i.getBody()->GetPosition().y - i.getShape().getSize().y/2);
			i.draw(window);
		}
	}
	if (!walls.size() == 0) {
		for (auto& i : walls) {
			i.getShape().setPosition(i.getBody()->GetPosition().x - i.getShape().getSize().x/2, i.getBody()->GetPosition().y - i.getShape().getSize().y/2);
			i.draw(window);
		}
	}
	for (int i = 1; i <= steve.getHP(); i++) {
		sf::RectangleShape rect(sf::Vector2f(10.f, 20.f));
		rect.setPosition(steve.getBody()->GetPosition().x - view.getSize().x/2 + 20*i, steve.getBody()->GetPosition().y - view.getSize().y/2 + 20);
		rect.setFillColor(sf::Color::Cyan);
		rect.setOutlineThickness(-1);
		window.draw(rect);
	}
}

void GM::worldChange(int nb) {

}