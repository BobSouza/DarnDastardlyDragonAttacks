#include "dragon.h"

using namespace std;

void Dragon::setName(string newName){
name = newName;
}

void Dragon:: takeDmg(int changes){
	if(changes >=0){
	health -= (changes*2);
	}
}
bool Dragon::isAlive(){
	if(health > 0)
		return true;
	else return false;
}
void Dragon::setHealth(int newHealth){
	if(newHealth > 0)
		health = newHealth;

}
void Dragon::setAtk(int newAtk){
	if(atk > 0)
		atk = newAtk;
}

Dragon::Dragon(int mod){
atk = (BASEATK + mod)/10;
health = BASEHP + (mod/2);
active = false;
numDragonsAlive++;
numDragonsSpawned++;
}
Dragon::Dragon():atk(BASEATK), health(BASEHP), active(false){
numDragonsAlive++;
numDragonsSpawned++;
}
Dragon::~Dragon(){
	//numDragonsAlive--;
}


string Dragon::getName(){
	return name;
}
int Dragon::getHealth(){
	return health;
}

int Dragon::getAtk(){
	return atk;
}

int Dragon::numDragonsAlive = 0;
int Dragon::numDragonsSpawned = 0;