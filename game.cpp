#include "game.h"
#include<limits>
using namespace std;

Game::Game():rounds(0), tastiest(0), activeDragons(0){

	map<string, int>::iterator it;

	dragonMod["Jerkface"]=(rand()% MODCAP)+1;
	dragonMod["Big Meanie"]=(rand()% MODCAP)+2;
	dragonMod["Smells-of-Elderberries"]=(rand()% MODCAP)+1;
	dragonMod["Little Meanie"]=(rand()% MODCAP)+3;
	dragonMod["Cranky"]=(rand()% MODCAP)+1;

	neighborMod["Blackwood"]=(rand()% MODCAP)+1;
	neighborMod["Greenlake"]=(rand()% MODCAP)+3;
	neighborMod["Blue Pine"]=(rand()% MODCAP)+1;
	neighborMod["Eyrie"]=(rand()% MODCAP)+6;
	neighborMod["Whitestone"]=(rand()% MODCAP)+1;


	it = neighborMod.begin();
	static PlayerCastle player;
	//castles.push_back(&player);
	static NPCastle npc1;
	spawnNeighbors(npc1, neighborMod);
	static NPCastle npc2;
	spawnNeighbors(npc2, neighborMod);
	static NPCastle npc3;
	spawnNeighbors(npc3, neighborMod);
	static NPCastle npc4;
	spawnNeighbors(npc4, neighborMod);
	static NPCastle npc5;
	spawnNeighbors(npc5, neighborMod);
	castles.push_back(&npc1);
	castles.push_back(&npc2);
	castles.push_back(&npc3);
	castles.push_back(&npc4);
	castles.push_back(&npc5);

	it = dragonMod.begin();
	static Dragon dragon1;
	spawnDragon(dragon1, dragonMod);
	static Dragon dragon2;
	spawnDragon(dragon2, dragonMod);
	static Dragon dragon3;
	spawnDragon(dragon3, dragonMod);
	static Dragon dragon4;
	spawnDragon(dragon4, dragonMod);
	static Dragon dragon5;
	spawnDragon(dragon5, dragonMod);
	dragons.push_back(&dragon1);
	dragons.push_back(&dragon2);
	dragons.push_back(&dragon3);
	dragons.push_back(&dragon4);
	dragons.push_back(&dragon5);
}



void Game:: spawnNeighbors(NPCastle& npc, map<string, int>& neighbors){
	map<string, int>::iterator it;
	int thing = rand()%(neighbors.size());
	it = neighbors.begin();
	for( int i = 0; i < thing ;i++, it++){}//make iterator point to a random element of the map
	npc.setCastleName( it->first);
	npc.setCastleSize((it->second));
	npc.setCoffers((npc.getCoffers())+ it->second);
	neighbors.erase(it);

}
void Game::spawnDragon(Dragon& dragon, map<string, int>& insults){
	map<string, int>::iterator it;
	int thing = rand()%(insults.size());
	it = insults.begin();
	for( int i = 0; i < thing ;i++, it++){}//make iterator point to a random element of the map
	dragon.setName(it->first);
	dragon.setHealth( BASEHP + (it->second));
	dragon.setAtk(BASEATK + 2*((it->second)/3));
	insults.erase(it);
}



void Game::dragonAttack(Dragon* wyrm){
	int initialDamage = wyrm->getAtk();

	if(tastiest > castles.size() && player.castleWalls.size() > 0)//that means player's castle is target
	{
		int pick;
		cout<<wyrm->getName()<<" Dragon has attacked Castle "<<player.getCastleName()<<"!"<<endl;

		player.dragonAttack = true;
		pick = rand()% player.castleWalls.size();
		(*player.castleWalls[pick]).takeDmg(initialDamage);
		wyrm->takeDmg((*player.castleWalls[pick]).getAtk()+ player.atkValue);
		//deal damage to dragon
			if((*player.castleWalls[pick]).checkWall()==Destroyed){
			delete (player.castleWalls.at(pick));
			(player.castleWalls.erase(player.castleWalls.begin()+pick));
			cout<<"One of Castle "<<player.getCastleName()<<"'s walls was destroyed in the attack!"<<endl;
		}
	}
	 if(tastiest < castles.size() && player.castleWalls.size() > 0){
		int pickAwall;
		cout<<wyrm->getName()<<" Dragon has attacked Castle "<<(*castles[tastiest]).getCastleName()<<"!"<<endl;
		pickAwall = rand()%((*castles[tastiest]).calcDefValue()+1)+1;
		pickAwall -= initialDamage;
		if(pickAwall <0)
			pickAwall*= -1;
		(*castles[tastiest]).health -= pickAwall;//damage dealt to npc castle
		(*castles[tastiest]).defValue -= (pickAwall/2);//damage dealt to npc castle walls
		wyrm->takeDmg(rand()%((*castles[tastiest]).calcAtkValue()+1)+1);//make sure it's not dividing by zero for teh modulo: first +1
		(*castles[tastiest]).dragonAttack = true;
		if((*castles[tastiest]).health <= 0){
			cout<<"Castle "<<(*castles[tastiest]).getCastleName()<<" was destroyed by "<<wyrm->getName()<<"!"<<endl;
			castles.erase(castles.begin()+ tastiest);
		}
		
	}

}


int Game::playGame(){
	string holder;
	string clearLine;
	char response;
	int k = 0;
	int i ,j;
	int checkPlayerQuit = 0;
	vector<Dragon*>::iterator it;
	cout<<"Hello, friend!  I'm pleased to present to you your very own castle! "<<endl<<"What would you like to name it?"<<endl;
	getline(cin, holder);
	if(holder == ""){
		cout<<"You chose not to name your castle, so it has been named for you.  Your new castle is called: "<<endl<<"Castle Not!Castle Greyskull."<<endl;
		player.setCastleName("Not!Castle Greyskull");
	}
	else
	player.setCastleName(holder);
	cout<<"Right. So your castle name is Castle "<< player.getCastleName()<<"."<<endl;
	cout<<"How many neighbors do you see from your castle? (0-5)"<<endl;
	while (!(cin >> j)||j > 5 || j < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Please enter a number of neighbors from 0 to 5."<<endl;
	}
	getline(cin, clearLine);
	castles.resize(j);
cout<< endl<<"Now, in order to be secure in your castle, you'll need to have good, "<<endl<<"sturdy walls. " 
<<"Make sure that you keep your walls in good condition; perhaps "<<endl<< "you'll also want to upgrade your walls."
<<" In any case, be on the lookout "<<endl<<"for dragon attacks; those dastardly menaces will be sure to show up "<<endl<<"sooner or later."<<endl<<endl;
	//actual gameplay here
	do{
		cout<<endl<<"Round "<<rounds+1<<endl;
		player.dragonAttack = false;
		checkPlayerQuit = player.takeTurn(rounds);//player turn
		if(!checkPlayerQuit){
		cout<<endl;
		for(i=0; i < castles.size(); i++){
			cout<<"Now taking Castle "<<(*castles[i]).getCastleName()<<"'s turn."<<endl;
			(*castles[i]).dragonAttack = false;
			(*castles[i]).takeTurn(i);//npc turn
		}
		if(rounds == DRAGONARRIVAL)
		{
			(*dragons.begin())->active = true;
			cout<<(*dragons.begin())->getName()<<" Dragon just woke up."<<endl;
			k = 1;
			activeDragons++;
		}
		 if(rounds!= DRAGONARRIVAL && (rounds-DRAGONARRIVAL) % MOREDRAGONS == 0)//five rounds have passed since we spawned a dragon. Time for another menace!
		{
			(dragons[k])->active = true;
			cout<<(*dragons[k]).getName()<<" Dragon just woke up."<<endl;
			k++;
			activeDragons++;
		}
		 cout<<endl;
		/************dragons attacking... **************/
		determineTarget();
		int j = k-1;
		//vector<int> numberAttacks;
		//int y;
		for(i = 0; i < activeDragons; i++, j--){
			dragonAttack((dragons[j]));
			//numberAttacks.push_back(y);
		}


		j = k;

		/****************Collect taxes from populace*********************************/
		player.collectTax();
		for(i=0; i < castles.size(); i++){
			(*castles[i]).collectTax();
		}
		/****************Check to see if player castle's population revolts****************/

		if(player.calcPopMood() < 2){
			cout<<"In response to your cruel tyranny (or possibly just horrible luck), your peasants"<<endl<< "have revolted"
				<<" against you and raised a new ruler in your place. You have been "<<endl<<"evicted from Castle "
				<<player.getCastleName()<<"."<<endl<<"Game Over."<<endl;
			checkPlayerQuit = 1;
		}
		for(i = 0; i < activeDragons; i++){
			if((dragons[i])->isAlive()== false){
				activeDragons--;
				k--;
				Dragon::numDragonsAlive--;
				cout<<(*dragons[i]).getName()<<" Dragon is dead from its wounds after its last attack."<<endl;
				dragons.erase(dragons.begin()+i);
			}
			
		}
//Castle::seasonCount +=3;
rounds++;
player.hasPrincess();
		}
	}while(!gameOver(checkPlayerQuit));

	cout<<endl<<"Rounds survived: "<<rounds<<endl;
	cout<<"Dragons withstood: "<<k<<endl;
	cout<<"Dragons killed: "<<(5-Dragon::numDragonsAlive)<<endl;

	if(rounds == ROUNDCAP && player.calcDefValue()> 0){
		cout<<"Congratulations! You won this game of Those Darn Dastardly Dragon Attacks!"<<endl;
		return 1;
	}
	else{
		cout<<"Those Darn Dastardly Dragons have won this game of "<<endl<<"Those Darn Dastardly Dragon Attacks!"<<endl;
		return 0;
	}


}
bool Game::gameOver(int quit){

	if(rounds == ROUNDCAP || player.castleWalls.size() == 0 || quit)
		return true;
	return false;
}
void Game::determineTarget(){
	tastiest = 0;
	int hi = 0;
	
	
	for( int i = 0; i < castles.size(); i++){
		if((*castles[i]).calcTastiness()>= hi){
			tastiest = i;
			hi = (*castles[i]).calcTastiness();
		}
	}
	if(player.calcTastiness() >= hi)
		//hi = player.calcTastiness();
		tastiest = castles.size()+1;

}