#include <SFML/Graphics.hpp>
#include "shapeDefine.h"

using namespace sf;

CircleShape makeCircle(int x, int y, int r, Color colour, int outlineW, Color outlineColour) {
    CircleShape circle(r);
    circle.setFillColor(colour);
    circle.setPosition(x, y);
    circle.setOutlineThickness(outlineW);
    circle.setOutlineColor(outlineColour);

    return circle;
}

RectangleShape makeRect(int x, int y, int w, int h, Color colour) {
    RectangleShape rect(Vector2f(w, h));
    rect.setFillColor(colour);
    rect.setPosition(x, y);

    return rect;
}


void updateCirPos(CircleShape& circle, const int& x, const int& y) {
    circle.setPosition(x, y);
}
void updateRectPos(RectangleShape& rect, const int& x, const int& y) {
    rect.setPosition(x, y);
}
