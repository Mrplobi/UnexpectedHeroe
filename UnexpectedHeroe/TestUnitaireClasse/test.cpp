#include "pch.h"
//#include <string>
//#include "../Lib1/classes.h"
//
//TEST(TestSpell, TestConstruct) {
//	Spell spell = Spell("bouh", 10, 100, 50, true);
//	EXPECT_EQ(spell.getName(), "bouh");
//	EXPECT_EQ(spell.getCost(), 10);
//	EXPECT_EQ(spell.getDamage(), 100);
//	EXPECT_EQ(spell.getRange(), 50);
//}
//
//
//TEST(TestEnnemy, TestConstruct) {
//	sf::Texture texture;
//	texture.loadFromFile("../../Sprite/sprite_test");
//	sf::Sprite sprite(texture);
//	Spell spell1 = Spell("attack1", 0, 1, 1.0, false);
//	Ennemy ennemy1 = Ennemy(&spell1, "blob", 1, 0, sprite);
//	EXPECT_EQ(ennemy1.getHP(), 1);
//	EXPECT_EQ(ennemy1.getMP(), 0);
//	EXPECT_EQ(ennemy1.getSpell()->getName(), "attack1");
//	EXPECT_EQ(ennemy1.getName(), "blob");
//}
//
//TEST(TestEnnemy, TestGetHit) {
//	Bandana bandana1 = Bandana("bite", 0, 1, 2, 3);
//	sf::Texture texture;
//	texture.loadFromFile("../../Sprite/sprite_test");
//	sf::Sprite sprite(texture);
//	Spell spell1 = Spell("attack1", 0, 1, 1.0, false);
//	Ennemy ennemy1 = Ennemy(&spell1, "blob", 15, 0, sprite);
//	ennemy1.getHit(10);
//	EXPECT_EQ(ennemy1.getHP(), 5);
//}
//
//TEST(TestEnnemy, TestHit) {
//	Bandana bandana1 = Bandana("bite", 0, 1, 2, 3);
//	sf::Texture texture;
//	texture.loadFromFile("../../Sprite/sprite_test");
//	sf::Sprite sprite(texture);
//	Spell spell1 = Spell("attack1", 0, 1, 1.0, true);
//	Spell spell2 = Spell("attack1", 0, 1, 1.0, false);
//	Ennemy ennemy1 = Ennemy(&spell2, "blob", 15, 0, sprite);
//	Steve steve = Steve(&bandana1, std::vector<Spell*>({ &spell1 }), 2, sprite);
//	ennemy1.hit(&steve);
//	EXPECT_EQ(steve.getHP(), 99);
//}
//
////onDeath test impossible cause it only rights in console, i.e not viewable in test
//
//TEST(TestVillager, TestConstruct) {
//	sf::Texture texture;
//	texture.loadFromFile("../../Sprite/sprite_test");
//	sf::Sprite sprite(texture);
//	Villager villager1 = Villager("You hit me, you beatch", "I help u, but not because i like u", "boris", sprite);
//	EXPECT_EQ(villager1.getHP(), 1); //not super useful
//	EXPECT_EQ(villager1.getMP(), 0); //same
//	EXPECT_EQ(villager1.getName(), "boris");
//}
//
//// Same with GetHit and Talked to for villager/heroe, and I won't make a getterfor the texts just for the tests (and for onDeath of heroe)
//
//TEST(TestSteve, TestConstruct) {
//	Bandana bandana1 = Bandana("bite", 0, 1, 2, 3);
//	sf::Texture texture;
//	texture.loadFromFile("../../Sprite/sprite_test");
//	sf::Sprite sprite(texture);
//	Spell spell1 = Spell("attack1", 0, 1, 1.0, true);
//	Steve steve = Steve(&bandana1, std::vector<Spell*>({ &spell1 }), 2, sprite);
//	EXPECT_EQ(steve.getHP(), 100);
//	EXPECT_EQ(steve.getMP(), 50);
//	EXPECT_EQ(steve.getSpell(0)->getName(), "attack1");
//	EXPECT_EQ(steve.getName(), "Steve");
//	EXPECT_EQ(steve.getEquipement()->getName(), "bite");
//	EXPECT_EQ(steve.getNumberOfJump(), 2);
//}
//
//TEST(TestSteve, TestGetHit) {
//	Bandana bandana1 = Bandana("bite", 0, 1, 2, 3);
//	sf::Texture texture;
//	texture.loadFromFile("../../Sprite/sprite_test");
//	sf::Sprite sprite(texture);
//	Spell spell1 = Spell("attack1", 0, 1, 1.0, true);
//	Steve steve = Steve(&bandana1, std::vector<Spell*>({ &spell1 }), 2, sprite);
//	steve.getHit(10);
//	EXPECT_EQ(steve.getHP(), 90);
//}
//
//TEST(TestSteve, TestAttack) {
//	Bandana bandana1 = Bandana("bite", 1, 1, 2, 3);
//	sf::Texture texture;
//	texture.loadFromFile("../../Sprite/sprite_test");
//	sf::Sprite sprite(texture);
//	Spell spell1 = Spell("attack1", 0, 2, 1.0, true);
//	Spell spell2 = Spell("attack2", 0, 1, 1.0, false);
//	Ennemy ennemy1 = Ennemy(&spell2, "blob", 15, 0, sprite);
//	Steve steve = Steve(&Bandana(), std::vector<Spell*>({ &spell1 }), 2, sprite);
//	steve.attack(&ennemy1, steve.getSpell(0));
//	EXPECT_EQ(ennemy1.getHP(), 13);
//	steve.equip(&bandana1);
//	steve.attack(&ennemy1, steve.getSpell(0));
//	EXPECT_EQ(ennemy1.getHP(), 10);
//}
//
//TEST(TestSteve, TestNewSpell) {
//	Bandana bandana1 = Bandana("bite", 0, 1, 2, 3);
//	sf::Texture texture;
//	texture.loadFromFile("../../Sprite/sprite_test");
//	sf::Sprite sprite(texture);
//	Spell spell1 = Spell("attack1", 0, 1, 1.0, true);
//	Spell spell2 = Spell("attack1", 0, 1, 1.0, false);
//	Steve steve = Steve(&bandana1, std::vector<Spell*>({}), 2, sprite);
//	EXPECT_EQ(steve.getList().size(), 0);
//	steve.newSpell(&spell1);
//	EXPECT_EQ(steve.getList().size(), 1);
//	steve.newSpell(&spell2);
//	EXPECT_EQ(steve.getList().size(), 1);
//}
//
//TEST(TestSteve, TestEquip) {
//	Bandana bandana1 = Bandana("caca", 0, 0, 5, 0);
//	Bandana bandana2 = Bandana("prout", 0, 0, 0, 5);
//	sf::Texture texture;
//	texture.loadFromFile("../../Sprite/sprite_test");
//	sf::Sprite sprite(texture);
//	Steve steve = Steve(&Bandana(), std::vector<Spell*>({}), 2, sprite);
//	EXPECT_EQ(steve.getHP(), 100);
//	EXPECT_EQ(steve.getMP(), 50);
//	steve.equip(&bandana1);
//	EXPECT_EQ(steve.getHP(), 105);
//	EXPECT_EQ(steve.getMP(), 50);
//	steve.equip(&bandana2);
//	EXPECT_EQ(steve.getHP(), 100);
//	EXPECT_EQ(steve.getMP(), 55);
//	steve.equip(&bandana2);
//	EXPECT_EQ(steve.getHP(), 100);
//	EXPECT_EQ(steve.getMP(), 55);
//}
//
////can't test on death right now (same problem)
//
////Heroe is basically villager so no tests (on death is the only important part so yeah, same problem)
//
//TEST(TestBandana, TestDefConstruct) {
//	Bandana bandana = Bandana();
//	EXPECT_EQ(bandana.getBonusCost(), 0);
//	EXPECT_EQ(bandana.getBonusDamage(), 0);
//	EXPECT_EQ(bandana.getBonusHP(), 0);
//	EXPECT_EQ(bandana.getBonusMP(), 0);
//	EXPECT_EQ(bandana.getName(), "");
//}
//
//TEST(TestBandana, TestConstruct) {
//	Bandana bandana = Bandana("POWA", 2, 5, 8, 9);
//	EXPECT_EQ(bandana.getBonusCost(), 5);
//	EXPECT_EQ(bandana.getBonusDamage(), 2);
//	EXPECT_EQ(bandana.getBonusHP(), 8);
//	EXPECT_EQ(bandana.getBonusMP(), 9);
//	EXPECT_EQ(bandana.getName(), "POWA");
//}