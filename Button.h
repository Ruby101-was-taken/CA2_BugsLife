#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"
#include <functional>

class Button
{
protected:
	sf::RectangleShape rect;
	sf::Text text;

	int x, y, w, h;

	std::function<void(Board&)> func;
public:
	Button(int x, int y, int w, int h, sf::Color color, std::string label, std::function<void(Board&)> func);

	void draw(sf::RenderWindow& win);
	bool isClicked(int x, int y);

	virtual void onClick(Board& board);

};

