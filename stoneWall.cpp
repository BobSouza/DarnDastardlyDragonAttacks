#include "stoneWall.h"
using namespace std;

stoneWall::stoneWall(){
	walltype="Stone";
	def=15;
	atk=0;
	integrity=15;
	maxIntegrity=15;
}

void stoneWall::repair(){
	integrity = maxIntegrity;
	def++;
}
void stoneWall::takeDmg(int dmg){
	if(dmg - def >= 0){
	integrity -= (dmg-def);
	if(def -(dmg/4) < 0)
	{def = 0;}
	else
	def -= (dmg/4);
	}
}