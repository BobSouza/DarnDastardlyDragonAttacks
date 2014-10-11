#include "wall.h"

using namespace std;
#ifndef LOGWALL_H
#define LOGWALL_H
class logWall: public Wall{

public:
	//string walltype;
	logWall();
	void repair();
	void takeDmg(int dmg);
};

#endif