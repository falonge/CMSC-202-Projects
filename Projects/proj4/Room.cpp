//Room.cpp
#include <iostream>
#include <string>
#include "Room.h"
using namespace std;

//Constructor
Room :: Room(int id, string name, string desc, int north, int east, int south, int west){
  m_ID = id;
  m_name = name;
  m_desc = desc;
  m_direction[0] = north;
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west;
}

//Getter for m_name
string Room :: GetName(){
  return m_name;
}

//Getter for m_ID
int Room :: GetID(){
  return m_ID;
}

//Getter for m_desc
string Room :: GetDesc(){
  return m_desc;
}

//Checks room and returns the ID is the player can exit that way, -1 if there are no exits
int Room :: CheckDirection(char myDirection){
	direction dir;
	//Turns character into enum type
	switch(myDirection){
	case 'N':
		dir = N;
		break;
	case 'n':
		dir = N;
		break;
	case 'E':
		dir = E;
		break;
	case 'e':
		dir = E;
		break;
	case 'S':
		dir = S;
		break;
	case 's':
		dir = S;
		break;
	case 'W':
		dir = W;
		break;
	case 'w':
		dir = W;
		break;
	}

	//Returns -1 if there's no exit that way, and the ID if there is one
	switch(dir){
	case 0:
		if(m_direction[0] == -1){
			return -1;
		}
		else{
			return m_direction[0];
		}
		break;
	case 1:
		if(m_direction[1] == -1){
			return -1;
		}
		else{
			return m_direction[1];
		}
		break;
	case 2:
		if(m_direction[2] == -1){
			return -1;
		}
		else{
			return m_direction[2];
		}
		break;
	case 3:
		if(m_direction[3] == -1){
			return -1;
		}
		else{
			return m_direction[3];
		}
		break;
	}
	return -1;
}

//Prints description and possible exits
void Room :: PrintRoom(){
	cout << m_name << endl << m_desc << endl << "Possible Exits: ";
	for(int i=0; i<4;i++){
		if(m_direction[i] != -1){
			switch(i){
			case 0:
				cout << "N";
				break;
			case 1:
				cout << "E";
				break;
			case 2:
				cout << "S";
				break;
			case 3:
				cout << "W";
				break;
			}
		}
	}
	cout << endl;
}
