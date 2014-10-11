#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include<cstdlib>
#include <time.h>

using namespace std;

int main(){
	srand(time(0));
	char response;
	string clearLine;
	int gamesWon = 0;
	int gamesPlayed = 0;
	cout<<endl<<"\t\tThose Darn Dastardly Dragon Attacks!"<<endl<<endl<<endl;

	cout<<"Do you want to play the game? (Y/N)"<<endl;
	do{
		do{
			cin>>response;
			if(!isalpha(response) || response != 'Y' && response != 'y' && response != 'N' && response != 'n'){
				getline(cin, clearLine);
				cout<< "Please enter Y or N."<<endl;
			}
		}while(!isalpha(response) || response != 'Y' && response != 'y' && response != 'N' && response != 'n');
			if(response == 'Y' || response == 'y'){
				getline(cin, clearLine);
				cout<<"In order to win a game, you will need to survive "<<ROUNDCAP
					<<" rounds with at least one of your defenses still standing."<<endl<<" Good luck!"<<endl<<endl;
				Game gameObject;
				gamesPlayed++;
				gamesWon += gameObject.playGame();
			
				cout<<"Games Played: "<<gamesPlayed<<endl<<"Games Won: "<<gamesWon<<endl;
				cout<<endl<<"Play again? (Y/N)"<<endl;
			}
		}while(response != 'N' && response != 'n');
		return 0;

	
}