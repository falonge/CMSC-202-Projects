//Passenger.cpp
#include "Passenger.h"
using namespace std;

//Constructor for passenger
Passenger :: Passenger(string name, int age, string start, string end){
  m_fullName = name;
  m_age = age;
  m_startLocation = start;
  m_finalDestination = end;
}

//Getter for name
string Passenger :: GetName(){
  return m_fullName;
}


//Getter for start location
string Passenger :: GetStartLocation(){
  return m_startLocation;
}

//Getter for final destination
string Passenger :: GetFinalDestination(){
  return m_finalDestination;
}
