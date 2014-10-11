#include "woodSpikeWall.h"
using namespace std;

woodSpikeWall::woodSpikeWall(){
	walltype="Wood Spikes";
	def=12; 
		atk=6; 
		integrity=11; 
		maxIntegrity=11;
}

void woodSpikeWall::repair(){
	integrity = maxIntegrity;
	def++;
}
void woodSpikeWall::takeDmg(int dmg){
	if(dmg - def >= 0){
	integrity -= (dmg-def);
	if(def -(dmg/2) < 0)
	{def = 0;}
	else
	def -= (dmg/2);
	}
}