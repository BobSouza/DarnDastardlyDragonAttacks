#include <iostream>
#include <string>

using namespace std;
#ifndef WALL_H
#define WALL_H

enum WallState {Hearty, Damaged, Destroyed};
typedef enum WallState Status;
class Wall{

public:
Wall();
virtual void repair() =0;
virtual void takeDmg(int dmg) = 0;
int getDef();
int getAtk();
int getIntegrity();
int getMaxIntegrity();
Status checkWall();
string walltype;
protected:
	int def;
	int atk;
	int integrity;
	int maxIntegrity;

};
#endif