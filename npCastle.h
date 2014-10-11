#include <iostream>
#include <string>
#include <vector>
#include "wall.h"
#include "castle.h"
using namespace std;

#ifndef NPCASTLE_H
#define NPCASTLE_H


class NPCastle: public Castle{


public:

NPCastle();
//~NPCastle();

int calcDefValue();
int calcAtkValue();
int calcTastiness();
//friend ostream& operator <<(ostream& out, NPCastle& npc);
int takeTurn(int rounds);


//int totalHirelings;
//int engineers;
//int saboteurs;

};

#endif