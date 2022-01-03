//File: Valorant.h
//Lab 6

#ifndef VALORANT_H
#define VALORANT_H

#include <iostream>
#include <string>
using namespace std;

class Valorant
{
 public:

  //Name: Valorant
  //Default constructor
  Valorant();
  //Name: Valorant
  //Overloaded Constructor
  Valorant(string setName, int setHP, bool setSide);
  //Name: SetName
  //Sets the name variable
  void SetName(string toSet);
  //Name: SetHP
  //Sets the HP variable
  void SetHP(int hp);
  //Name: SetSide
  //Sets the isDefender variable
  void SetSide(bool toSet);
  //Name: GetName
  //returns the name variable
  string GetName();
  //Name: GetHP
  //returns the HP variable
  int GetHP();
  //Name: GetSide
  //returns the isDefender variable
  bool GetSide();
  
 private:
  string m_name;
  int m_HP;
  bool m_isDefender;
};
#endif
