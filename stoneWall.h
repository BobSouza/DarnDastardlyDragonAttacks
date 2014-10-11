#include "wall.h"

using namespace std;
#ifndef STONEWALL_H
#define STONEWALL_H
class stoneWall: public Wall{

public:
	//string walltype;
	stoneWall();
	void repair();
	void takeDmg(int dmg);

};

#endif