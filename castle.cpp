#include <iostream>
#include <string>
//#include<cstdlib>
#include "castle.h"
using namespace std;





string Castle::getSeason(){
	string seasonReport;
	seasonCount = (seasonCount%4);
	switch(Castle::seasonCount){
		case 0:
			seasonReport = "Spring";
			return seasonReport;
			break;
		case 1:
			seasonReport = "Summer";
			return seasonReport;
			break;
		case 2:
			seasonReport = "Autumn";
			return seasonReport;
			break;
		case 3:
			seasonReport = "Winter";
			return seasonReport;
			break;
		default:
			seasonReport = "No idea how we got here; invalid season?";
			return seasonReport;
			break;
	};
}


int Castle:: calcPopMood(){
	int mood = 4;
	if(tax < 4 && determineHarvest()){
		mood +=2;
	}
	if(tax > 4 && tax <= 6)
	{
		mood --;
	}
	if(tax >= 7)
	{
		mood -= 3;
	}
	if(peasantHappiness >=5.5){
		mood +=2;
	}	
	if(peasantHappiness <=2){
		mood --;
	}
		if(peasantHappiness < 5.5 && peasantHappiness >2){
		mood ++;
	}
		if(dragonAttack){
			mood -=2;
		}
		if(princess){
			mood ++;
		}
if(mood > 8)
mood = 8;

if (mood < 0)
mood = 0;
	//MAX MOOD IS 8
	return mood;
}

int Castle::calcTax(){

	unsigned int total;
	total = peasants*harvest;
	total *=(tax*.1);

return total;
}
void Castle::collectTax(){
coffers += calcTax();

}

bool Castle::payFor(int item){
	if(coffers < item){	
		return false;
	}
	else{
		coffers -=item;
		return true;
	}
}
bool Castle::hasPrincess(){
	if(coffers/100 >= 1){
		princess = (coffers/100);
	}
	if(princess > 0){
		return true;
	}
	else
		return false;
}

int Castle::getCastleSize(){
	return castleSize;
}

void Castle::setCastleSize(int newSize){
	castleSize = newSize;
}

bool Castle::determineHarvest(){
	harvest = 6;
	if(peasantHappiness>=7.0){
		if(harvest <= 7)
		{
			harvest = 7;
		}
		else if(harvest > 7 && harvest < 12)
		{
			harvest++;
		}
	}
if(dragonAttack)
	harvest -=4;

if (harvest >=7)
return true;
//if the harvest was good, returns true
else return false;
}




void Castle::hireKnights(int howMany){
	int hireAKnight = 4*howMany;
	if(hasPrincess()){//valid only if a princess exists
		if(payFor(hireAKnight))
		{
			cout<<"Congratulations! You hired "<<howMany<<" new knight(s) to defend "<<name<<" and its inhabitants!"<<endl;
			seasonCount++;
			atkValue += howMany;
		}
		else
		{
			cout<<"You cannot afford to hire a knight! "<<endl<<"The amount of gold in Castle "<<name<<"'s coffers is: "
				<<coffers<<" gold. Feel free to try again when you can afford this expense."<<endl;
		}
	}
	else
	{
		cout<<name<<" has no princess with which to entice any knights to defend Castle "<<name<<"."<<endl;
	}
	
	//only works if there is enough in the coffers to pay for the knight(s)
	//(opens some options in regards to responses with dragons and wizards)
}
void Castle::hearComplaints(){
	//increase peasant and noble happiness, slight decrease in harvest
	harvest -=1;
	peasantHappiness += 2.2;
	seasonCount++;


}
void Castle::throwBall(){
	int ball = 9;
	if(payFor(ball)){
		//peasant happiness increase
		peasantHappiness += 2.1;
		seasonCount++;
		//noble happiness lesser increase
		//coffers slight decrease
	}
	else{
		cout<<endl<<"You cannot afford to hold a ball! The amount of gold in Castle"<<name<<"'s coffers is: "
			<<coffers<<" gold. Feel free to try again when you can afford this expense."<<endl;
	}
	//noble happiness increases
	//peasant happiness lesser increase
	//(chance for magical hijinks)
	//larger cost from coffers

}
void Castle::raiseTax(int howMuch){
	if(10 > howMuch + tax){
		cout<<"The tax on the people of the land has been raised to "<<howMuch + tax<<" from "<<tax<<"."<<endl;
		tax +=howMuch;
		seasonCount++;
	}
	else
		cout<<"You cannot raise the tax by "<<howMuch<<", as it exceeds the total annual harvest."<<endl;
	//raise tax, lowers peasant happiness, slight increase of noble happiness
}
void Castle::observeSubjects(){
	int popMood = calcPopMood();
	switch(popMood){
		case 0:
			//fall through here
		case 1:
			cout<<"Your subjects seem unhappy and may be planning a revolt.  Those pitchforks do -not- look friendly."<<endl;
			break;
		case 2:
		cout<<"Your subjects seem slightly disgruntled."<<endl;
		break;
	case 3:
		cout<<"Your subjects seem vaguely okay."<<endl;
		break;
	case 4:
		cout<<"Your subjects seem moderately content."<<endl;
		break;
	case 5:
		cout<<"Your subjects seem content."<<endl;
		break;
	case 6://fall through
	case 7:
		cout<<"Your subjects seem very content."<<endl;
		break;
	case 8:
		cout<<"Your subjects seem unnaturally ecstatic; is there something in the water?."<<endl;
		break;
	default:
	cout<<"How odd; we seem to have reached an error in mood calculation.  Your population has an invalid mood..."<<endl;
	break;
	};
	seasonCount++;
}

void Castle::decreeFestival(){
	int festival = 6;
	if(payFor(festival)){
		//peasant happiness increase
		peasantHappiness += 3.3;
		seasonCount++;
		//noble happiness lesser increase
		//coffers slight decrease
	}
	else{
		cout<<endl<<"You cannot afford to hold a festival! The amount of gold in Castle "<<name<<"'s coffers is: "
			<<coffers<<" gold. Feel free to try again when you can afford this expense."<<endl;
	}
	//(chance for magical hijinks)
}




int Castle::getNobles(){
	return nobles;
}
int Castle::getPeasants(){
	return peasants;
}
int Castle::getKnights(){

	return knights;
}
int Castle::getCoffers(){
	return coffers;
}
int Castle::getPrincess(){
	return princess;
}

double Castle::getPeasantHappiness(){
	return peasantHappiness;
}
string Castle::getCastleName(){
	return name;
}

int Castle::getHarvest(){
	return harvest;
}
int Castle::getTax(){
	return tax;
}

//int Castle::getPopGrowth(){
//	return popGrowth;
//}




void Castle::setNobles(int newNobles){
	if (newNobles >= 0){
		nobles = newNobles;
	}
}
void Castle::setPeasants(int newPeasants){
	if (newPeasants >= 0){
		peasants = newPeasants;
	}
}
void Castle::setKnights(int newKnights){
	if (newKnights >= 0){
		knights = newKnights;
	}
}
void Castle::setCoffers(int newCash){
	if(newCash >= 0){
		coffers = newCash;
	}
}
void Castle::setPrincess(int newPrincess){
	if(newPrincess >= 0){
		princess = newPrincess;
	}
}

void Castle::setPeasantHappiness(double happy){
	if(happy >= 0 && happy <= 10.0){
		peasantHappiness = happy;
	}
}
void Castle::setCastleName(string newName){
	name = newName;
}

void Castle::setHarvest(int newHarvest){
	if(newHarvest >= 0 && newHarvest <= 12){
		harvest = newHarvest;
	}
}
void Castle::setTax(int newTax){
	if(newTax > 0 && newTax < 10){
		tax = newTax;
	}
}

//void Castle::setPopGrowth(int newGrowth){
//	if(newGrowth >= 1 && newGrowth < 50){
//		popGrowth = newGrowth;
//	}
//}

Castle::Castle(){
	castleCount++;
	name = "Default Castle";
	castleSize = 6;
	atkValue = 0;
	defValue = 6;
	health = 45;
	//cout<< "A castle has been built in the "<<Castle::getSeason()<<", named "<<name<<"."<<endl;
	peasants = 30;
	nobles= 6;
	knights = 0;
	princess = 0;
	coffers= 10;

	peasantHappiness = 5.0;//out of 10.0
	harvest = 6;//out of 12
	tax = 2;//out of 10

	tastiness = 3;
	//popGrowth = 2;//percent
	//seasonCount +=5;
	dragonAttack = false;

};
Castle::Castle(string u_name){
	castleCount++;
	name = u_name;
	castleSize = 6;
	atkValue = 0;
	defValue = 6;
	peasants = 30;
	nobles= 6;
	health = 45;
	knights = 0;
	princess = 0;
	coffers= 10;

	peasantHappiness = 5.0;
	harvest = 6;
	tax = 2;
	
	tastiness = 3;
	//popGrowth = 2;
	//seasonCount +=5;
	//cout<< "A castle by the name of "<<name<<" has been built by "<<ruler<<" in "<<Castle::getSeason()<<"."<<endl;
	//cout<< "This is castle number: "<<castleCount<<endl;
	dragonAttack = false;
}
Castle::Castle(Castle& a){
	//cout<< "A wizard has made a copy of the castle "<<a.name<<"!"<<endl;
	castleCount++;
	name = "Not!"+a.name;
	peasants = a.peasants;
	nobles = a.nobles;
	knights = a.knights;
	princess = a.princess;
	coffers= a.coffers;
	castleSize = 6;
	health = 45;
	atkValue = 0;
	defValue = 6;
	peasantHappiness= a.peasantHappiness;
	harvest=a.harvest;
	tax= a.tax;

	tastiness = 3;
	//popGrowth= a.popGrowth;
	//cout<<"He has unimaginatively named it: "<< name << endl;
	//cout<< "This is castle number: "<<castleCount<<endl;
	dragonAttack = false;
}


Castle::~Castle(){
	//cout<< "A castle has been destroyed."<<endl;
	castleCount--;
}

int Castle:: seasonCount = 1;
int Castle:: castleCount = 0;