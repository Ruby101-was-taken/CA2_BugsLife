
#ifndef FILEREADER_H
#define FILEREADER_H

#include "Bug.h"
#include <vector>


std::vector<Bug*> readBugFile(int* w, int* h, Bug* player);

void writeBugFile(std::vector<Bug*> bugs);


#endif // FILEREADER_H
