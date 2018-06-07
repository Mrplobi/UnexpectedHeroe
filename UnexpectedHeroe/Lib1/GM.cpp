#include "stdafx.h"
#include "GM.h"

GM::GM() : DAWARUDO(b2Vec2(0, -1)) {
	Spell spell1 = Spell("normalAtack", 0, 2, 2, true);	
	listOfSpell.push_back(spell1);
	sf::Texture texture;
	texture.loadFromFile("../../Sprite/sprite_test");
	sf::Sprite sprite(texture);
	Steve steve = Steve(&Bandana(), std::vector<Spell*>({ &spell1 }), 0, sprite, 0, 0, 1, 1, 1, 0.5, 0.1, &DAWARUDO);
}

void GM::gameLoop() {
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Unexpected Heroe");
	while (1) {

	}
}