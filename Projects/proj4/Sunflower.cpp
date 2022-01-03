//Sunflower.cpp
#include "Sunflower.h"
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Sunflower :: Sunflower(){
  SetName(" ");
  SetHealth(SUNFLOWER_HEALTH);
}

//Overloaded Constructor
Sunflower :: Sunflower(string name, int hp){
  SetName(name);
  SetHealth(hp);
}
//Destructor
Sunflower :: ~Sunflower(){

}

//Uses Sunflower's Special Attack
int Sunflower :: SpecialAttack(){
  int damage = rand()%8+1;
  cout << GetName() << " uses a high beam turret - **SUNBEAM**\n" << GetName() << " deals " << damage << " damage!\n";
  return damage;
}
