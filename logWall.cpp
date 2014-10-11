#include "logWall.h"
using namespace std;

logWall::logWall(){
walltype = "Log";
}

void logWall::repair(){
	integrity = maxIntegrity;
	def++;
}
void logWall::takeDmg(int dmg){
	if(dmg - def >= 0){
	integrity -= (dmg-def);
	if(def -(dmg/2) < 0)
	{def = 0;}
	else
	def -= (dmg/2);
	}
}