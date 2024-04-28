#include <SFML/Graphics.hpp>
#include "shapeDefine.h"
#include <iostream>

using namespace sf;

CircleShape makeCircle(int x, int y, int r, Color colour, int outlineW, Color outlineColour) {
    CircleShape circle(r);
    circle.setFillColor(colour);
    circle.setPosition(x, y);
    circle.setOutlineThickness(outlineW);
    circle.setOutlineColor(outlineColour);

    return circle;
}

RectangleShape makeRect(int x, int y, int w, int h, Color colour, int outlineW, Color outlineColour) {
    RectangleShape rect(Vector2f(w, h));
    rect.setFillColor(colour);
    rect.setPosition(x, y);

    if (outlineW > 0) {
        rect.setOutlineThickness(outlineW);
        rect.setOutlineColor(outlineColour);
    }

    return rect;
}

Text makeText(std::string words, int x, int y, int fontSize, Color colour) {
    Text text;
    
    static Font font; //font is static so that it can persist even after the function ends, otherwise the text will attempt to use a font that does not exist
    static bool fontLoaded = false;
    
    if (not fontLoaded) {
        if (!font.loadFromFile("arial.ttf"))
        {
            std::cout << "Font file could not be loaded" << std::endl;
        }
    }

    text.setFont(font);

    text.setString(words);
    text.setFillColor(colour);
    text.setCharacterSize(fontSize);
    text.setPosition(x, y);

    return text;
}


void updateCirPos(CircleShape& circle, const int& x, const int& y) {
    circle.setPosition(x, y);
}
void updateRectPos(RectangleShape& rect, const int& x, const int& y) {
    rect.setPosition(x, y);
}
