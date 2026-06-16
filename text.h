#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
struct Textobj {
	sf::Text text;
	sf::Font font;
};
void TextobjInit(Textobj& textobj, int score) {
	textobj.font.loadFromFile("DS-DIGIB.ttf");
	textobj.text.setFont(textobj.font);
	textobj.text.setString(std::to_string(score));
	textobj.text.setCharacterSize(FONT_SIZE);
	textobj.text.setPosition(TEXT_POS);
}
void TextobjUpdate(Textobj& textobj, int score) {
	textobj.text.setString(std::to_string(score));
}
void textDraw(sf::RenderWindow& window, const Textobj& textobj) {
	window.draw(textobj.text);
}
