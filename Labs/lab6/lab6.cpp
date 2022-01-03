//File: lab6.cpp
#include <iostream>
#include <string>
#include <vector>
#include "Valorant.h"
using namespace std;

//fillVector prototype here:
//Desc: Prompts the user with the number of characters they want to enter and adds each character to the vector
//Pre-condition: Accepts a vector
//Post-condition: Updates the vector passed to it
void fillVector(vector<Valorant> &vect);
// //printVector
// //Desc: Prints the contents of the vector (without using an iterator)
// //Pre-condition: Accepts a vector (but don't make a copy of it)
// //Post-condition: Displays information about the characters in the vector
void printVector(vector<Valorant> &vect);
  


int main()
{
  
  //Vector that stores the user input
  vector<Valorant> list;

  //fills the vector
  fillVector(list);
  //prints the vector
  printVector(list);
  cout << endl;

  return 0;
}

// //Insert fillVector here - we want to change the vector permanently!

void fillVector(vector<Valorant> &vect){
  int numCharacters;
  string name;
  int hp;
  bool defender;
  cout << "How many Valorant characters?\n";
  cin >> numCharacters;
  for(int i=0;i<numCharacters;i++){
    cout << "Character " << i+1 << " name:\n";
    cin >> name;
    cout << "Character " << i+1 << " HP:\n";
    cin >> hp;
    cout << "Is Character " << i+1 << " a defender? (0 or 1):\n";
    cin >> defender;
    vect.push_back(Valorant(name, hp, defender));
  }
}




//Insert printVector - we do not want to make a copy of the vector

void printVector(vector<Valorant> &vect){
  for(unsigned int i=0;i<vect.size();i++){
    cout << vect[i].GetName() << " is on team " << vect[i].GetSide() << " and has " << vect[i].GetHP() << " HP.\n";
  }
}
