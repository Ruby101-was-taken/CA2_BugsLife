#include "Button.h"
#include "shapeDefine.h"

#include <SFML/Graphics.hpp>

Button::Button(int x, int y, int w, int h, sf::Color color, std::string label, std::function<void(Board&)> func) {
	rect = makeRect(x, y, w, h, color);
	text = makeText(label, x, y, h, Color::Black);
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	this->func = func;
}

bool Button::isClicked(int mx, int my) {
	return mx >= x and mx <= x + w and my >= y and my <= y + h;
}

void Button::draw(sf::RenderWindow& win) {
	win.draw(rect);
	win.draw(text);
}

void Button::onClick(Board& board) {
	func(board);
}