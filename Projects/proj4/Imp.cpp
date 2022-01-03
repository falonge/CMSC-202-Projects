//Imp.cpp
#include "Imp.h"
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Imp :: Imp(){
  SetName("Imp");
  SetHealth(IMP_HEALTH);
}

//Overloaded Constructor
Imp :: Imp(string name, int hp){
  SetName(name);
  SetHealth(hp);
}
//Uses Imp's Special Attack
int Imp :: SpecialAttack(){
  cout << "Imp blasts you with their Impkata attack!\nImp deals 4 damage!\n";
  return 4;
}
