//Entity.cpp
#include "Entity.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor
Entity :: Entity(){
  m_name = "";
  m_health = 0;
  m_level = 0;
}

//Overloaded Constructor
Entity :: Entity(string name, int health){
  m_name = name;
  m_health = health;
  m_level = 0;
}

//Destructor
Entity :: ~Entity(){

}

//Getter for m_name
string Entity :: GetName(){
  return m_name;
}

//Getter for m_health
int Entity :: GetHealth(){
  return m_health;
}

//Setter for m_name
void Entity :: SetName(string name){
  m_name = name;
}

//Setter for m_health
void Entity :: SetHealth(int health){
  m_health = health;
}
