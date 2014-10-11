#include "npCastle.h"

using namespace std;

NPCastle::NPCastle(){
health = 45;
}

int NPCastle::takeTurn(int rounds){
	setCoffers(getCoffers()- (rand()%(coffers/2)));
	//cout<<"..."<<endl;
	
	return 0;

}

//ostream& operator <<(ostream& out, NPCastle& npc){
//out<< "Castle "<<npc.getCastleName();
//return out;
//}

int NPCastle::calcDefValue(){
	defValue = 2*(rand()%castleSize);
	return defValue;

}
int NPCastle::calcAtkValue(){
	atkValue = ((rand()%castleSize)/3);
	return atkValue;

}
int NPCastle::calcTastiness(){
	tastiness = coffers + princess;
	return tastiness;

}
