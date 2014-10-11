#include "reinforcedWall.h"
using namespace std;

reinforcedWall::reinforcedWall(){
	walltype ="Reinforced";
	def=12;
	atk=0;
	integrity=12;
	maxIntegrity=12;
}

void reinforcedWall::repair(){
	integrity = maxIntegrity;
	def++;
}
void reinforcedWall::takeDmg(int dmg){
	if(dmg - def >= 0){
	integrity -= (dmg-def);
	if(def -(dmg/3) < 0)
	{def = 0;}
	else
	def -= (dmg/3);
	}
}