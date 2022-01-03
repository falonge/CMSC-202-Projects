#include "Valorant.h"
#include <iostream>
#include <string>
using namespace std;

Valorant :: Valorant(){
  m_name = "Default";
  m_HP = 1;
  m_isDefender = true;
}

Valorant :: Valorant(string setName, int setHP, bool setSide){
  m_name = setName;
  m_HP = setHP;
  m_isDefender = setSide;
}

void Valorant :: SetName(string toSet){
  m_name = toSet;
}

void Valorant :: SetHP(int hp){
  m_HP = hp;
}

void Valorant :: SetSide(bool toSet){
  m_isDefender = toSet;
}

string Valorant :: GetName(){
  return m_name;
}

int Valorant :: GetHP(){
  return m_HP;
}

bool Valorant :: GetSide(){
  return m_isDefender;
}


  
