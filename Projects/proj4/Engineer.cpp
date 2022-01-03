//Engineer.cpp
#include "Engineer.h"
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Engineer :: Engineer(){
  SetName("Engineer");
  SetHealth(ENGINEER_HEALTH);
}

//Overloaded Constructor
Engineer :: Engineer(string name, int hp){
  SetName(name);
  SetHealth(hp);
}

//Uses Enginneer's Special Attack
int Engineer :: SpecialAttack(){
  cout << "Engineer blasts you with their steam blaster!\nEngineer deals 2 damage!\n";
  return 2;
}
