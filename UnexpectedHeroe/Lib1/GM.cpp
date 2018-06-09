#include "stdafx.h"
#include "GM.h"


GM::GM() : DAWARUDO(b2Vec2(0, -1)), steve(Steve(&Bandana(), std::vector<Spell*>({}), std::vector<Spell*>({}), 0, 540, 0, 1, 1, 1, (float)0.5, (float)0.1, sf::Color::Magenta, DAWARUDO)) {
	Spell spell1 = Spell("normalAtack", 0, 2, true);	
	listOfSpell.push_back(spell1);
	steve.getListSpell().push_back(&spell1);
	steve.getListSpell().push_back(&spell1);
	InputHandler handler;
}

void GM::gameLoop() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Unexpected Heroe", sf::Style::Default, settings);
	Wall wall1(0, 300, 700, 500, 0, 0, 0, sf::Color::Red, &DAWARUDO);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		//wall1.draw(window);
		steve.draw(window);
		window.display();
		handler.pile();
	}	
}

void GM::worldChange(int nb) {

}