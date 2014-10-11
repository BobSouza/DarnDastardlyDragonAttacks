#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "playerCastle.h"
#include "npCastle.h"
#include "dragon.h"
using namespace std;

#ifndef GAME_H
#define GAME_H
#define MODCAP 16
#define NEIGHBORCAP 5
#define DRAGONARRIVAL 2
#define MOREDRAGONS 5
#define ROUNDCAP 27
class Game{

public:
	
	
	Game();
	//~Game();
	
int playGame();
private:
	map <string, int> dragonMod;
	map <string, int> neighborMod;
	
	int rounds;
	int tastiest;
	int activeDragons;
	vector<NPCastle*> castles;
	vector<Dragon*> dragons;
	PlayerCastle player;

	
	bool gameOver(int quit);
	void spawnDragon(Dragon& dragon, map<string, int>& insults);
	void spawnNeighbors(NPCastle& npc, map<string, int>& neighbors);
	void dragonAttack(Dragon* wyrm);
	void determineTarget();

	//void timePasses();

};

#endif