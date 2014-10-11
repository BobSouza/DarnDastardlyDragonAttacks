#include "stoneSpikeWall.h"
using namespace std;

stoneSpikeWall::stoneSpikeWall(){
	walltype= "Stone Spikes";
	def=15; 
		atk=9; 
		integrity=16; 
		maxIntegrity=16;
}

void stoneSpikeWall::repair(){
	integrity = maxIntegrity;
	def++;
}
void stoneSpikeWall::takeDmg(int dmg){
	if(dmg - def >= 0){
	integrity -= (dmg-def);
	if(def -(dmg/4) < 0)
	{def = 0;}
	else
	def -= (dmg/4);
	}
}