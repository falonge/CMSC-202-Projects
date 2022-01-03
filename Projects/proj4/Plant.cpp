//Plant.cpp
#include "Plant.h"
#include <string>
#include <iostream>
using namespace std;

//Constructor
Plant :: Plant(){
  SetName(" ");
  //SetHealth(PLANT_HEALTH);
}

//Overloaded Constructor
Plant :: Plant(string name, int hp){
  SetName(name);
  SetHealth(hp);
}

//Destructor
Plant :: ~Plant(){

}

//Uses plant's attack
int Plant :: Attack(){
  int damage = rand()%6+1;
  cout << GetName() << " attacks dealing " << damage << " damage!\n";
  return damage;
}

//Uses plants Special Attack (Only if they choose no class, where they won't have a special attack.)
int Plant :: SpecialAttack(){
  cout << "Regular plants can't use a special attack.\n";
  return 0;
}
