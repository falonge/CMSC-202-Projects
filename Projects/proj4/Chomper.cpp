//Chomper.cpp
#include "Chomper.h"
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Chomper :: Chomper(){
  SetName(" ");
  SetHealth(CHOMPER_HEALTH);
}
// Overloaded Constructor
Chomper :: Chomper(string name, int hp){
  SetName(name);
  SetHealth(hp);
}

//Destructor
Chomper :: ~Chomper(){

}

//Uses Chomper's Special Attack
int Chomper :: SpecialAttack(){
  int damage = rand()%12+1;
  if(damage == 1){
    damage = 2;
  }
  cout << GetName() << " performs a sneak attack! CHOMP\n" << GetName() << " deals " << damage << " damage!\n";
  return damage;
}
