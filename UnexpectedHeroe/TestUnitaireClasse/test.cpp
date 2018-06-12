#include "pch.h"
#include <string>
#include "../Lib1/classes.h"
#include "../Lib1/GM.h"


TEST(TestSpell, TestConstruct) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../XML/assets.xml");
	if (result < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	Spell spell = Spell(doc.child("GudShit").child("Spells").child("Spell"));
	EXPECT_EQ(spell.getName(), "Rhum sirop citron");
	EXPECT_EQ(spell.getCost(), 0);
	EXPECT_EQ(spell.getDamage(), 2);
}


TEST(TestBandana, TestDefConstruct) {
	Bandana bandana = Bandana();
	EXPECT_EQ(bandana.getBonusCost(), 0);
	EXPECT_EQ(bandana.getBonusDamage(), 0);
	EXPECT_EQ(bandana.getBonusHP(), 0);
	EXPECT_EQ(bandana.getBonusMP(), 0);
	EXPECT_EQ(bandana.getName(), "");
}

TEST(TestBandana, TestConstruct) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../XML/assets.xml");
	if (result < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	Bandana bandana = Bandana(doc.child("GudShit").child("Bandanas").child("Bandana"));
	EXPECT_EQ(bandana.getBonusCost(), 0);
	EXPECT_EQ(bandana.getBonusDamage(), 0);
	EXPECT_EQ(bandana.getBonusHP(), 0);
	EXPECT_EQ(bandana.getBonusMP(), 0);
	EXPECT_EQ(bandana.getBonusJump(), 1);
	EXPECT_EQ(bandana.getName(), "Bendana of De Ero!");
}

TEST(TestEnnemy, TestConstruct) {
	b2World theWorld(b2Vec2(0, 10));
	std::vector<Spell> listOfSpell;
	pugi::xml_document doc1;
	pugi::xml_document doc2;
	pugi::xml_parse_result result1 = doc1.load_file("../../XML/assets.xml");
	if (result1 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	pugi::xml_parse_result result2 = doc2.load_file("../../XML/The_pit_of_doom.xml");
	if (result2 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc1.child("GudShit").child("Spells").children()) {
		listOfSpell.push_back(Spell(i));
	}
	Ennemy ennemy1 = Ennemy(doc2.child("Da_Pit_of_DOOOOOOOM").child("SpookyScary").child("Ennemy"), theWorld, &listOfSpell[doc2.child("Da_Pit_of_DOOOOOOOM").child("SpookyScary").child("Ennemy").attribute("Spell").as_int()], sf::Color::Black);
	EXPECT_EQ(ennemy1.getHP(), 6);
	EXPECT_EQ(ennemy1.getMP(), 0);
	EXPECT_EQ(ennemy1.getSpell()->getName(), "weak aff punf");
	EXPECT_EQ(ennemy1.getName(), "Bouh");
	EXPECT_EQ(ennemy1.getShape().getPosition(), sf::Vector2f(700, 360));
	EXPECT_EQ(ennemy1.getBody()->GetFixtureList()->GetFriction(), 0);
	EXPECT_EQ(ennemy1.getBody()->GetFixtureList()->GetRestitution(), 0);
	EXPECT_EQ(ennemy1.getBody()->GetFixtureList()->GetDensity(), 1);
	EXPECT_EQ(ennemy1.getShape().getSize(), sf::Vector2f(50, 50));
}

TEST(TestEnnemy, TestGetHit) {
	b2World theWorld(b2Vec2(0, 10));
	std::vector<Spell> listOfSpell;
	pugi::xml_document doc1;
	pugi::xml_document doc2;
	pugi::xml_parse_result result1 = doc1.load_file("../../XML/assets.xml");
	if (result1 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	pugi::xml_parse_result result2 = doc2.load_file("../../XML/The_pit_of_doom.xml");
	if (result2 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc1.child("GudShit").child("Spells").children()) {
		listOfSpell.push_back(Spell(i));
	}
	Ennemy ennemy1 = Ennemy(doc2.child("Da_Pit_of_DOOOOOOOM").child("SpookyScary").child("Ennemy"), theWorld, &listOfSpell[doc2.child("Da_Pit_of_DOOOOOOOM").child("SpookyScary").child("Ennemy").attribute("Spell").as_int()], sf::Color::Black);
	ennemy1.getHit(2);
	EXPECT_EQ(ennemy1.getHP(), 4);
}


//onDeath test impossible cause it only rights in console, i.e not viewable in test

TEST(TestVillager, TestConstruct) {
	b2World theWorld(b2Vec2(0, 10));
	std::vector<Spell> listOfSpell;
	pugi::xml_document doc1;
	pugi::xml_document doc2;
	pugi::xml_parse_result result1 = doc1.load_file("../../XML/assets.xml");
	if (result1 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	pugi::xml_parse_result result2 = doc2.load_file("../../XML/The_pit_of_doom.xml");
	if (result2 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc1.child("GudShit").child("Spells").children()) {
		listOfSpell.push_back(Spell(i));
	}
	Villager villager1 = Villager(doc2.child("Da_Pit_of_DOOOOOOOM").child("folks").child("Villager"), theWorld, sf::Color::Cyan);
	EXPECT_EQ(villager1.getHP(), 1); //not super useful
	EXPECT_EQ(villager1.getMP(), 0); //same
	EXPECT_EQ(villager1.getName(), "Toby");
	EXPECT_EQ(villager1.getTextHit(), "Comme dirait le grand Duke Nukem : *censored*");
	EXPECT_EQ(villager1.getTextTalk(), "eimmet m'I !!!yoH");
}

// Same with GetHit and Talked to for villager/heroe, and I won't make a getterfor the texts just for the tests (and for onDeath of heroe)

TEST(TestSteve, TestConstruct) {
	b2World theWorld(b2Vec2(0, 10));
	std::vector<Spell> listOfSpell;
	pugi::xml_document doc1;
	pugi::xml_document doc2;
	pugi::xml_parse_result result1 = doc1.load_file("../../XML/assets.xml");
	if (result1 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	pugi::xml_parse_result result2 = doc2.load_file("../../XML/The_pit_of_doom.xml");
	if (result2 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc1.child("GudShit").child("Spells").children()) {
		listOfSpell.push_back(Spell(i));
	}
	Steve steve = Steve(&Bandana(), std::vector<Spell*>({}), std::vector<Spell*>({}), 1, 200, 100, 50, 50, 1, 0.5, 0.1, sf::Color::Magenta, theWorld);
	steve.getListEquiped().push_back(&listOfSpell[0]);
	EXPECT_EQ(steve.getHP(), 5);
	EXPECT_EQ(steve.getMP(), 10);
	EXPECT_EQ(steve.getListEquiped()[0]->getName(), "Rhum sirop citron");
	EXPECT_EQ(steve.getName(), "Steve");
	EXPECT_EQ(steve.getEquipement()->getName(), "");
	EXPECT_EQ(steve.getNumberOfJump(), 1);
}

TEST(TestSteve, TestGetHit) {
	b2World theWorld(b2Vec2(0, 10));
	std::vector<Spell> listOfSpell;
	pugi::xml_document doc1;
	pugi::xml_document doc2;
	pugi::xml_parse_result result1 = doc1.load_file("../../XML/assets.xml");
	if (result1 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	pugi::xml_parse_result result2 = doc2.load_file("../../XML/The_pit_of_doom.xml");
	if (result2 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc1.child("GudShit").child("Spells").children()) {
		listOfSpell.push_back(Spell(i));
	}
	Steve steve = Steve(&Bandana(), std::vector<Spell*>({}), std::vector<Spell*>({}), 10, 200, 100, 50, 50, 1, 0.5, 0.1, sf::Color::Magenta, theWorld);
	steve.getHit(2);
	EXPECT_EQ(steve.getHP(), 3);
}

TEST(TestSteve, TestNewSpell) {
	b2World theWorld(b2Vec2(0, 10));
	std::vector<Spell> listOfSpell;
	pugi::xml_document doc1;
	pugi::xml_document doc2;
	pugi::xml_parse_result result1 = doc1.load_file("../../XML/assets.xml");
	if (result1 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	pugi::xml_parse_result result2 = doc2.load_file("../../XML/The_pit_of_doom.xml");
	if (result2 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc1.child("GudShit").child("Spells").children()) {
		listOfSpell.push_back(Spell(i));
	}
	Steve steve = Steve(&Bandana(), std::vector<Spell*>({}), std::vector<Spell*>({}), 10, 200, 100, 50, 50, 1, 0.5, 0.1, sf::Color::Magenta, theWorld);
	EXPECT_EQ(steve.getListSpell().size(), 0);
	steve.newSpell(&listOfSpell[0]);
	EXPECT_EQ(steve.getListSpell().size(), 1);
	steve.newSpell(&listOfSpell[1]);
	EXPECT_EQ(steve.getListSpell().size(), 2);
}

TEST(TestSteve, TestEquip) {
	b2World theWorld(b2Vec2(0, 10));
	std::vector<Bandana> listOfBandana;
	pugi::xml_document doc1;
	pugi::xml_document doc2;
	pugi::xml_parse_result result1 = doc1.load_file("../../XML/assets.xml");
	if (result1 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	pugi::xml_parse_result result2 = doc2.load_file("../../XML/The_pit_of_doom.xml");
	if (result2 < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto& i : doc1.child("GudShit").child("Bandanas").children()) {
		listOfBandana.push_back(Bandana(i));
	}
	Steve steve = Steve(&Bandana(), std::vector<Spell*>({}), std::vector<Spell*>({}), 10, 200, 100, 50, 50, 1, 0.5, 0.1, sf::Color::Magenta, theWorld);
	EXPECT_EQ(steve.getHP(), 5);
	EXPECT_EQ(steve.getMP(), 10);
	steve.equip(&listOfBandana[1]);
	EXPECT_EQ(steve.getHP(), 3);
	EXPECT_EQ(steve.getMP(), 10);
	steve.equip(&listOfBandana[2]);
	EXPECT_EQ(steve.getHP(), 10);
	EXPECT_EQ(steve.getMP(), 20);
}

////can't test on death right now (same problem)
//
////Heroe is basically villager so no tests (on death is the only important part so yeah, same problem)
