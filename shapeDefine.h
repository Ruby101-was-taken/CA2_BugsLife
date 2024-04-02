#ifndef SHAPEDEFINE_H
#define SHAPEDEFINE_H

#include <SFML/Graphics.hpp>

using namespace sf;

CircleShape makeCircle(int x, int y, int r, Color colour = Color::Blue, int outlineW = 0, Color outlineColour = Color::Black);

RectangleShape makeRect(int x, int y, int w, int h, Color colour);


void updateCirPos(CircleShape& circle, const int& x, const int& y);
void updateRectPos(RectangleShape& rect, const int& x, const int& y);

#endif // SHAPEDEFINE_H