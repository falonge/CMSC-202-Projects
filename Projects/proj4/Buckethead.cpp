//Buckethead.cpp
#include "Buckethead.h"
#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Buckethead :: Buckethead(){
  SetName("Buckethead");
  SetHealth(BUCKETHEAD_HEALTH);
}

//Overloaded Constructor
Buckethead :: Buckethead(string name, int hp){
  SetName(name);
  SetHealth(hp);
}

//Uses Buckethead's Special Attack
int Buckethead :: SpecialAttack(){
  cout << "Buckethead throws its bucket at you!\nBuckethead deals 1 damage!\n";
  return 1;
}
