
#ifndef CA2_BUGSLIFE_GENERALFUNCTIONS_H
#define CA2_BUGSLIFE_GENERALFUNCTIONS_H

#include <vector>
#include <string>

#include "direction.h"

int randInt(int min, int max);

std::vector<std::string> splitString(const std::string& str, const char delimiter);

void toUpperCase(std::string& str);

int strToInt(std::string);

direction intToDir(int i);

bool pairInVector(const std::vector<std::pair<int, int>>& v, const std::pair<int, int>& p);

std::string dirToStr(direction d);

#endif //CA2_BUGSLIFE_GENERALFUNCTIONS_H
