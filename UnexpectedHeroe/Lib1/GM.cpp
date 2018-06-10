#include "stdafx.h"
#include "GM.h"


GM::GM() : DAWARUDO(b2Vec2(0, -1)),	steve(Steve(&Bandana(), std::vector<Spell*>({}), std::vector<Spell*>({}), 0, 0, 0, 50, 50, 1, 0.5, 0.1, sf::Color::Magenta, DAWARUDO)) {
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
	pitOfDoom();
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Unexpected Heroe");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		processInput();
		//Gestion des collision et background changes;
		
		window.clear();
		steve.draw(window);
		window.display();
		handler.pile();
	}	
}

void GM::pitOfDoom() {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../XML/The_pit_of_doom.xml");
	if (result < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc.child("Da_Pit_of_DOOOOOOOM").child("Elmundokilébo").children()) {
		walls.push_back(Wall(i, DAWARUDO, sf::Color::Red));
	}
	for (auto& i : doc.child("Da_Pit_of_DOOOOOOOM").child("SpookyScary").children()) {
		listOfEnnemies.push_back(Ennemy(i, DAWARUDO, &listOfSpell[2], sf::Color::Black));
	}
	for (auto& i : doc.child("Da_Pit_of_DOOOOOOOM").child("folks").children()) {
		if (i.name() == "Villager") {
			people.push_back(Villager(i, DAWARUDO, sf::Color::Green));
		}
		else if (i.name() == "Heroe") {
			people.push_back(Heroe(i, DAWARUDO, sf::Color::Blue));
		}
	}
}


void GM::processInput() {
	handler.pile();
	for (auto& i : handler.getPile()) {
		if ( i == Jump )
			steve.jump();
		if (i == SteveAttack1)
			steve.attack();
		if (i == SteveAttack2)
			steve.attack2();
		if (i == MovementRigth)
			steve.moveRight();
		if (i == MovementLeft)
			steve.moveLeft();
	}
}


void GM::worldChange(int nb) {

}