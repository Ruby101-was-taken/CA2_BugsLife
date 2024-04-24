#include "generalFunctions.h"
#include "direction.h"
#include <random>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

int randInt(int min, int max) {
	return min + (rand() % (max - min + 1));
}

std::vector<std::string> splitString(const std::string& str, const char delimiter) {
	std::vector<std::string> returnStrings;
	std::string tempStr = "";
	for (int i = 0;i < str.length();i++) {
		if (str[i] == delimiter) {
			returnStrings.push_back(tempStr);
			tempStr = "";
		}
		else {
			tempStr += str[i];
		}
	}

	if(tempStr.length() > 0) //adds the last string is there is no delimiter at the end :3
		returnStrings.push_back(tempStr);

	return returnStrings;
}


// https://stackoverflow.com/a/34946858
void toUpperCase(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

int strToInt(std::string str) {
	// https://cplusplus.com/reference/string/stoi/
	return std::stoi(str);
}

direction intToDir(int i) {
	switch (i) {
		case 1:
			return north;
			break;
		case 2:
			return east;
			break;
		case 3:
			return south;
			break;
		case 4:
			return west;
			break;
		default:
			return north;
			break;
	}
}

bool pairInVector(const std::vector<std::pair<int, int>>& v, const std::pair<int, int>& p) {
	std::vector<std::pair<int, int>>::const_iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		if (*it == p) {
			return true;
		}
	}
	return false;
}
