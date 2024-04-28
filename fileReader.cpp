#include "fileReader.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "generalFunctions.h"
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
// I had too much fun making these
#include "Hooper.h"
#include "Goober.h"
#include "Stoober.h"
#include "Spoober.h"
#include "Voober.h"
#include "Voosher.h"
#include "Hater.h"


std::vector<Bug*> readBugFile(int* w, int* h, Bug* player) {
	std::vector<Bug*> allBugs;

    std::map<std::string, std::string> textures = {
       {"C", "images/crawler.png"},
       {"H", "images/hopper.png"},
       {"HO", "images/hooper.png"},
       {"G", "images/goober.png"},
       {"ST", "images/stoober.png"},
       {"SP", "images/spoober.png"},
       {"V", "images/voober.png"},
       {"VH", "images/voosher.png"},
       {"HA", "images/hater.png"}
    };

    std::ifstream fin("bugs.txt");
    if (fin) {
        std::string name;
        while (!fin.eof()) {
            getline(fin, name);

            if (name.length() > 0) {
                std::vector<std::string> line = splitString(name, ';');

                toUpperCase(line[0]);

                if (line[0] == "C") {
                    allBugs.push_back(new Crawler(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4]))));
                    allBugs.back()->setTexture(textures[line[0]]);
                }
                else if (line[0] == "H") {
                    allBugs.push_back(new Hopper(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4])), intToDir(strToInt(line[6]))));
                    allBugs.back()->setTexture(textures[line[0]]);
                }
                else if (line[0] == "G") {
                    allBugs.push_back(new Goober(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4]))));
                    allBugs.back()->setTexture(textures[line[0]]);
                }
                else if (line[0] == "ST") {
                    allBugs.push_back(new Stoober(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4]))));
                    allBugs.back()->setTexture(textures[line[0]]);
                }
                else if (line[0] == "SP") {
                    allBugs.push_back(new Spoober(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4]))));
                    allBugs.back()->setTexture(textures[line[0]]);
                }
                else if (line[0] == "V") {
                    allBugs.push_back(new Voober(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4]))));
                    allBugs.back()->setTexture(textures[line[0]]);
                }
                else if (line[0] == "VH") {
                    allBugs.push_back(new Voosher(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4]))));
                    allBugs.back()->setTexture(textures[line[0]]);
                }
                else if (line[0] == "HO") {
                    allBugs.push_back(new Hooper(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4]))));
                    allBugs.back()->setTexture(textures[line[0]]);
                }
                else if (line[0] == "HA") {
                    allBugs.push_back(new Hater(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4])), player));
                    allBugs.back()->setTexture(textures[line[0]]);
                }
            }
        }
        fin.close();
    }
    else {
        std::cout << "Error opening the file." << std::endl;
    }

    return allBugs;
}


void writeBugFile(std::vector<Bug*> bugs) {

    std::ofstream fout("bugs_life_history_date_time.out");

    if (fout) {
        std::vector<Bug*>::iterator it;
        for (it = bugs.begin(); it != bugs.end(); it++) {
            fout << (*it)->getInfo() << "\n" << (*it)->getHistory() << "\n============================\n\n";
        }
    }

    fout.close();
}