#include <iostream>
#include <string>
#include <vector>
#include "wall.h"
#include "logWall.h"
#include "stoneWall.h"
#include "reinforcedWall.h"
#include "woodSpikeWall.h"
#include "stoneSpikeWall.h"
#include "castle.h"
using namespace std;

#ifndef PLAYERCASTLE_H
#define PLAYERCASTLE_H

#define SIZECAP 10
class PlayerCastle: public Castle{


public:
int calcDefValue();
int calcAtkValue();
int calcTastiness();

PlayerCastle();
~PlayerCastle();
//friend ostream& operator <<(ostream& out, PlayerCastle& pc);
int takeTurn(int rounds);
vector<Wall*> castleWalls;

private:
	int repairAwall();
	int buildAwall();
	//int upgradeAwall();
	//get how many seasons pass for each type of wall as return value; 
	//0 if cannot take build/upgrade/repair action

	
//
//int totalHirelings;
//int engineers;
//int saboteurs;
//
//int calcTotalHirelings();


};

#endif