
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

#endif //CA2_BUGSLIFE_GENERALFUNCTIONS_H
