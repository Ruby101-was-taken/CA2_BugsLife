#include <iostream>

#include "Bug.h"
#include "direction.h"

#include "generalFunctions.h"

#include "Board.h"

#include "Crawler.h"
#include "Hopper.h"

#include <random>

#include <SFML/Graphics.hpp>

#include "shapeDefine.h"

#include "fileReader.h"

#include "Button.h"

using namespace std;

int w = 10, h = 10;


int winW = 853, winH = 480;

int gridSize = 48;

int scrollPos = 0;

pair<float, float> winScale = { 1,1 };

sf::Text sideBugInfoText = makeText("Click a bug to see it's info and history", 480, 0, 20, sf::Color::White);
sf::Text sideBugHistoryText = makeText("", 680, 0, 20, sf::Color::White);

void tapBoard(Board& board) {
    board.moveBugs();
    board.removeDeadBugs();
} 
void viewCells(Board& board) {
    sideBugHistoryText.setString(board.getAllCellInfo());
    sideBugInfoText.setString("All cell info");
    sideBugHistoryText.setPosition(640, 0);
}

void resetText() {
    sideBugInfoText.setString("Click a bug to see it's info and history");
    sideBugHistoryText.setString("");
    sideBugHistoryText.setPosition(680, 0);
}

int main() {
    int* wPtr = &w, * hPtr = &h;

    

    Board board(w, h, gridSize);

    srand(time(NULL));

    vector<Button> buttons;
    buttons.push_back(Button(480, 450, 100, 30, sf::Color::White, "TAP", tapBoard));
    buttons.push_back(Button(590, 450, 200, 30, sf::Color::White, "View Cell Info", viewCells));

    sf::RenderWindow win(sf::VideoMode(853, 480), "Bugs Life!");

    sf::RectangleShape infoWindow = makeRect(480, 0, 373, 480, sf::Color(0, 30, 0));

    while (win.isOpen()){

        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
            if (event.type == Event::MouseButtonPressed) { 

                Vector2i mousePosition = Mouse::getPosition(win);

                
                scrollPos = 0;

                if (not board.checkClicked(mousePosition.x / winScale.first, mousePosition.y / winScale.second, sideBugInfoText, sideBugHistoryText)) {
                    resetText();
                }

                for (auto& b : buttons) {
                    if (b.isClicked(mousePosition.x/ winScale.first, mousePosition.y/ winScale.second)) {
                        b.onClick(board);
                    }
                }
            }
            if (event.type == sf::Event::MouseWheelMoved)
            {
                scrollPos += event.mouseWheel.delta*25;
                if (scrollPos > 0) scrollPos = 0;

                sideBugHistoryText.setPosition(sideBugHistoryText.getPosition().x, scrollPos);
            }

            if (event.type == sf::Event::Resized) {
                winScale.first = win.getSize().x / (float)winW;
                winScale.second = win.getSize().y / (float)winH;


            }
        }
        // https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Keyboard.php

        if (board.getPlayer()->isAlive()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                board.getPlayer()->setDir(west);
                resetText();
                sideBugInfoText.setString(board.getPlayer()->getInfo());
                sideBugHistoryText.setString(board.getPlayer()->getHistory());
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                board.getPlayer()->setDir(east);
                resetText();
                sideBugInfoText.setString(board.getPlayer()->getInfo());
                sideBugHistoryText.setString(board.getPlayer()->getHistory());
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                board.getPlayer()->setDir(north);
                resetText();
                sideBugInfoText.setString(board.getPlayer()->getInfo());
                sideBugHistoryText.setString(board.getPlayer()->getHistory());
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                board.getPlayer()->setDir(south);
                resetText();
                sideBugInfoText.setString(board.getPlayer()->getInfo());
                sideBugHistoryText.setString(board.getPlayer()->getHistory());
            }
        }


        board.updateBugs();
        

        win.clear();

        

        board.draw(win);
        win.draw(infoWindow);

        win.draw(sideBugInfoText);
        win.draw(sideBugHistoryText);



        for (auto& b : buttons) {
            b.draw(win);
        }

        win.setFramerateLimit(60); //fps to 60

        win.display();
    }



    return 0;
}
