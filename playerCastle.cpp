#include "playerCastle.h"
#include<limits>
using namespace std;

PlayerCastle::PlayerCastle(){
	Wall* buildAwall;
	for (int i = 0; i < castleSize; i++){
		buildAwall = new logWall;
		castleWalls.push_back(buildAwall);
	}

}
PlayerCastle::~PlayerCastle(){
	int j = castleWalls.size()-1;
	for (int i = j; i >=0 ; i--){
		delete(castleWalls[i]);
		castleWalls.erase(castleWalls.end()-1);
	}
}

int PlayerCastle::takeTurn(int rounds){
	char response;
	int digits;
	string clearLine;
	//cout<<"Player Turn:"<<endl;
	do{ 
		cout<<endl<<getSeason()<<endl<<endl;
		cout<<"Castle "<<name<<" has "<< coffers<<" gold in its coffers."<<endl<<"Princesses in residence: "<<princess<<endl<<"Walls standing: "<<castleWalls.size()<<endl<<endl;
		cout<<"Choose from the options below by entering the appropriate number:"<<endl<<endl<<"(1) Observe Castle "<<name<<"'s subjects"<<endl
			<<"(2) Hold a festival"<<endl<<"(3) Throw a ball in Castle "<<name<<endl<<"(4) Hear complaints from Castle "<<name
			<<"'s subjects"<<endl<<"(5) Hire knights to protect Castle "<<name<<endl<<"(6) Raise annual taxes"<<endl
			<<"(7) Build a new wall"<<endl/*<<"(8) Upgrade an existing wall"<<endl*/<<"(8) Repair a damaged wall"<<endl<<"(0) Quit"<<endl;
		do{
			cin>> response;
			if(!isdigit(response) || response > '8' || response < '0'){
				cout<<"Please enter a number from 0 to 8."<<endl;
			}
			getline(cin, clearLine);
		}while(!isdigit(response)|| response > '8' || response < '0');
		switch(response){
case '1':
	observeSubjects();
	break;
case '2':
	decreeFestival();
	break;
case '3':
	throwBall();
	break;
case '4':
	hearComplaints();
	break;
case '5': 
		cout<<"How many knights do you wish to hire?(1-9)"<<endl;
		while (!(cin >> digits)||digits > 9 || digits < 1){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Please enter a number from 1 to 9."<<endl;
	}
	getline(cin, clearLine);
hireKnights(digits);
//getline(cin, clearLine);
	break;
case '6':
	cout<<"By how much do you wish to raise the tax?(0-6%)"<<endl;
	while (!(cin >> digits) || digits > 6 || digits < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Please enter a number from 0 to 6."<<endl;
	}
	getline(cin, clearLine);
	raiseTax(digits);
	//getline(cin, clearLine);
	break;
case '7':
	seasonCount += buildAwall();
	break;
case '8':
	seasonCount += repairAwall();
	break;
case '0':
	return 1;
	break;
default:
	cout<<"No idea how we got here... error on player menu input!"<<endl;
	return 0;
	break;

		};
		if(rounds == 0){
			seasonCount = 4;
		}
	}while (seasonCount%4 != 0);
	return 0;
}

//ostream& operator <<(ostream& out, PlayerCastle& pc){
//	out<<"Your castle ";
//	return out;
//}

int PlayerCastle::calcDefValue(){
	return 5;

}
int PlayerCastle::calcAtkValue(){
	return 5;

}
int PlayerCastle::calcTastiness(){
	tastiness = coffers + princess;
	return tastiness;

}

int PlayerCastle::repairAwall(){
	int k;
	for(int i = 0; i < castleWalls.size(); i++){
		if(castleWalls[i]->checkWall()== Damaged){
			if(castleWalls[i]->walltype =="Log")
				k = 25;
			else if(castleWalls[i]->walltype =="Stone")
				k = 60;
			else if(castleWalls[i]->walltype =="Stone Spikes")
				k = 90;
			else if(castleWalls[i]->walltype =="Wood Spikes")
				k = 40;
			else //(castleWalls[i]->wallType =="Reinforced")
				k = 60;
			if(payFor(k)){
				castleWalls[i]->repair();
				cout<<"One wall of Castle "<<name<<" repaired."<<endl;
				return (k/20);
			}
			else{
				cout<<"Cannot afford repairs at this time. "<<endl<<"Amount in Castle "<<name<<"'s coffers is: "<<coffers<<endl;
				return 0;
			}
		}
	}
	cout<<"There are currently no walls in need of repair."<<endl;
	//iterate through walls, comparing integrity to maxintegrity; repair first encountered damaged wall
	//if none are damaged, print message saying so and return 0
	//if cannot afford action, say so and return 0
	return 0;
}

int PlayerCastle::buildAwall(){
	if(castleWalls.size()< SIZECAP){
		int k, m;
		string clearLine;
		Wall* buildIt;
		cout<<"Wall Types Available:"<<endl<<"(1) Wood"<<endl<<"(2) Stone"<<endl<<"(3) Reinforced"<<endl<<"(4) Wood Spikes"<<endl<<"(5) Stone Spikes"<<endl<<"(0) Exit Build Menu"<<endl;
		cin>>m;
		getline(cin, clearLine);
		switch(m){
			case 1:
				k = 35;
				if(payFor(k)){
					buildIt = new logWall;
					castleWalls.push_back(buildIt);
					return 2;
				}
				else 
					cout<<"You cannot afford to build this wall. It costs "<<k<<" gold, and "<<endl<<"Castle "<<name<<" only has "<<coffers<<" gold in its coffers."<<endl;
				return 0;
				break;
			case 2:
				k = 80;
				if(payFor(k)){
					buildIt = new stoneWall;
					castleWalls.push_back(buildIt);

					return 4;
				}
				else 
					cout<<"You cannot afford to build this wall. It costs "<<k<<" gold, and "<<endl<<"Castle "<<name<<" only has "<<coffers<<" gold in its coffers."<<endl;
				return 0;
				break;
			case 3:
				k = 50;
				if(payFor(k)){
					buildIt = new reinforcedWall;
					castleWalls.push_back(buildIt);

					return 3;
				}
				else 
					cout<<"You cannot afford to build this wall. It costs "<<k<<" gold, and "<<endl<<"Castle "<<name<<" only has "<<coffers<<" gold in its coffers."<<endl;
				return 0;
				break;
			case 4:
				k = 45;
				if(payFor(k)){
					buildIt = new woodSpikeWall;
					castleWalls.push_back(buildIt);

					return 2;
				}
				else 
					cout<<"You cannot afford to build this wall. It costs "<<k<<" gold, and "<<endl<<"Castle "<<name<<" only has "<<coffers<<" gold in its coffers."<<endl;
				return 0;
				break;
			case 5:
				k = 120;
				if(payFor(k)){
					buildIt = new stoneSpikeWall;
					castleWalls.push_back(buildIt);
					return 4;
				}
				else 
					cout<<"You cannot afford to build this wall. It costs "<<k<<" gold, and "<<endl<<"Castle "<<name<<" only has "<<coffers<<" gold in its coffers."<<endl;
				return 0;

				break;
			case 0:
				return 0;
				break;
			default:
				cout<<"No idea how we got here... error!"<<endl;
				return 0;
				break;

		};

	}
	else
		cout<<"Your estate does not have the space to build another wall."<<endl;
	//check if we can afford this wall.
	//if not, let us know and offer choices again (remember to include option to abort attempts to build wall
	//if we've reached SIZECAP, say we're out of room on the property or something and return 0
	//if we cannot afford ANY of the walls, say so and return 0
	return 0;
}


//int PlayerCastle::upgradeAwall(){
//	//iterate through walls, looking for walls that are upgradable
//	//if there aren't any, say so and return 0
//	//if there are, list off the types 
//	//also offer wall replacement
//return 0;
//	}

void hireHelper(){

}
