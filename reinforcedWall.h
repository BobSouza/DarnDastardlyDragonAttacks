#include "wall.h"

using namespace std;
#ifndef REINFORCEDWALL_H
#define REINFORCEDWALL_H
class reinforcedWall: public Wall{

public:
	//string walltype;
	reinforcedWall();
	void repair();
	void takeDmg(int dmg);

};

#endif