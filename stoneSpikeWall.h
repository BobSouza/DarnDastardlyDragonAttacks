#include "wall.h"

using namespace std;
#ifndef STONESPIKEWALL_H
#define STONESPIKEWALL_H
class stoneSpikeWall: public Wall{

public:
	//string walltype;
	stoneSpikeWall();
	void repair();
	void takeDmg(int dmg);

};

#endif