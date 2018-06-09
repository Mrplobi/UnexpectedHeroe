#include "stdafx.h"
#include "GM.h"


GM::GM() : DAWARUDO(b2Vec2(0, -1)) {
	Spell spell1 = Spell("normalAtack", 0, 2, 2, true);	
	listOfSpell.push_back(spell1);
	sf::Texture texture;
	texture.loadFromFile("../../Sprite/sprite_test");
	sf::Sprite sprite(texture);
	Steve steve = Steve(&Bandana(), std::vector<Spell*>({&spell1}), std::vector<Spell*>({ &spell1 }), 0, sprite, 0.f, 0.f, 1.f, 1.f, 1.f, (float)0.5, (float)0.1, &DAWARUDO);
	InputHandler handler;
}

void GM::gameLoop() {
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Unexpected Heroe");
	while (1) {
		handler.pile();
	}
}