#include <iostream>
#include <string>
#include <vector>
#include "wall.h"
using namespace std;
#ifndef CASTLE_H
#define CASTLE_H

class Castle{

public:

	static int castleCount;
	static int seasonCount;

	virtual int takeTurn(int rounds) = 0;
	

	virtual int calcDefValue()=0;
	virtual int calcAtkValue()=0;
	virtual int calcTastiness()=0;

	int atkValue;
	int defValue;
	bool dragonAttack;
	int health;

	void hireKnights(int howMany);
	void hearComplaints();
	void throwBall();
	void raiseTax(int howMuch);
	void observeSubjects();
	void decreeFestival();
	void setCastleSize(int newSize);
	int getNobles();
	int getPeasants();
	int getKnights();
	int getCoffers();
	int getPrincess();
	double getPeasantHappiness();
	string getCastleName();
	int getHarvest();
	int getTax();
	int getCastleSize();
	static string getSeason();
	void setNobles(int newNobles);
	void setPeasants(int newPeasants);
	void setKnights(int newKnights);
	void setCoffers(int newCash);
	void setPrincess(int newPrincess);
	void setPeasantHappiness(double happy);
	void setCastleName(string newName);
	void collectTax();
	void setHarvest(int newHarvest);
	void setTax(int newTax);
	int calcPopMood();
	bool hasPrincess();

	Castle();
	Castle(string name);
	Castle(Castle& a);
	~Castle();

	protected:

	string name;
	int peasants;
	int nobles;
	int knights;
	int princess;
	int coffers;
	double peasantHappiness;//out of 10.0
	int harvest;//out of 12
	int tax;//out of 10
	int tastiness;
	int castleSize;
	int calcTax();
	bool payFor(int item);
	
	bool determineHarvest();
};

#endif 