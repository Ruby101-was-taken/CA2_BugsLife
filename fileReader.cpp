#include "fileReader.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "generalFunctions.h"
#include "Bug.h"
#include "Crawler.h"


std::vector<Bug> readBugFile(int* w, int* h) {
	std::vector<Bug> allBugs;

    std::ifstream fin("bugs.txt");
    if (fin) {
        std::string name;
        while (!fin.eof()) {
            getline(fin, name);

            std::vector<std::string> line = splitString(name, ';');

            toUpperCase(line[0]);

            if (line[0] == "C") {
                allBugs.push_back(Crawler(strToInt(line[1]), strToInt(line[2]), strToInt(line[3]), strToInt(line[5]), w, h, intToDir(strToInt(line[4]))));
            }
        }
        fin.close();
    }
    else {
        std::cout << "Error opening the file." << std::endl;
    }

    return allBugs;
}