#include "wall.h"

using namespace std;
Wall::Wall():def(8), atk(0), integrity(10), maxIntegrity(10), walltype(""){}

int Wall::getDef(){
	return def;
}
int Wall::getAtk(){
return atk;
}
int Wall::getIntegrity(){
	return integrity;
}
int Wall::getMaxIntegrity(){
	return maxIntegrity;
}
Status Wall::checkWall(){
if(integrity <= 0)
return Destroyed;
else if(integrity < maxIntegrity)
return Damaged;
else return Hearty;
}