//Zombie.cpp
#include "Zombie.h"
#include "Zombie.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Zombie :: Zombie(){
	SetName(" ");
	//SetHealth(ZOMBIE_HEALTH);
}

//Overloaded Constructor
Zombie :: Zombie(string name, int hp){
	SetName(name);
	SetHealth(hp);
}

//Uses Zombie's Attack
int Zombie :: Attack(){
	cout << GetName() << " attacks doing 1 damage!\n";
	return 1;
}
