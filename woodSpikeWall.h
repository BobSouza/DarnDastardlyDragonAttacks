#include "wall.h"

using namespace std;
#ifndef WOODSPIKEWALL_H
#define WOODSPIKEWALL_H
class woodSpikeWall: public Wall{

public:
	//string walltype;
	woodSpikeWall();
	void repair();
	void takeDmg(int dmg);

};

#endif