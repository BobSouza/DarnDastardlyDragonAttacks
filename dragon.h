#include <iostream>
#include <string>
#include <vector>
#include<cstdlib>
#include <time.h>
using namespace std;
#ifndef DRAGON_H
#define DRAGON_H

#define BASEATK 12
#define BASEHP 35


class Dragon{

public:
static int numDragonsAlive;
static int numDragonsSpawned;
bool active;

void setName(string newName);
void setHealth(int newHealth);
void setAtk(int newAtk);
string getName();
int getHealth();
int getAtk();
void takeDmg(int changes);
bool isAlive();

Dragon();
Dragon(int mod);
~Dragon();
private:
	string name;
	int atk;
	int health;
};





#endif