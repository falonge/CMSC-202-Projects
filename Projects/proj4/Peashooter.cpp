//Peashooter.cpp
#include "Peashooter.h"
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Peashooter :: Peashooter(){
  SetName(" ");
  SetHealth(PEASHOOTER_HEALTH);
}

//Overloaded Constructor
Peashooter :: Peashooter(string name, int hp){
  SetName(name);
  SetHealth(hp);
}

//Destructor
Peashooter :: ~Peashooter(){

}

//Uses Peashooter's Special Attack
int Peashooter :: SpecialAttack(){
  int damage = rand()%12+1;
  if(damage < 3){
    damage = 3;
  }
  cout << GetName() << " sneaks up doing GATLING DAMAGE!\n" << GetName() << " deals " << damage << " damage!\n";
  return damage;
}
