#include "pch.h"
#include "gtest/gtest.h"
#include "../Lib1/classes.h"
#include <pugixml.hpp>

TEST(TestXML, Bandana) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../../XML/assets.xml");
	if (result < 0) {
		std::cout << "error parsing" << std::endl;
		exit(EXIT_FAILURE);
	}
	Spell bandana = Spell(doc.child("GudShit").child("Spells").child("Spell"));
	EXPECT_EQ(bandana.getName(), "Rhum sirop citron");
}