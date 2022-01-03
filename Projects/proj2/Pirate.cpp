#include "Pirate.h"
#include "Ship.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

Pirate :: Pirate(){
  m_pirateName = "";
  m_pirateRating = 0;
  m_pirateOrigin = "";
  m_pirateDesc = "";
  m_pirateCargo = 0;
  m_pirateDays = 0;
}

Pirate :: Pirate(string name, int rating, string origin, string desc){
  m_pirateName = name;
  m_pirateRating = rating;
  m_pirateOrigin = origin;
  m_pirateDesc = desc;
  m_pirateCargo = 0;
  m_pirateDays = 0;
}

string Pirate :: GetName(){
  return m_pirateName;
}

int Pirate :: GetRating(){
  return m_pirateRating;
}

void Pirate :: SetRating(int rating){
  m_pirateRating = rating;
}

string Pirate :: GetOrigin(){
  return m_pirateOrigin;
}

string Pirate :: GetDesc(){
  return m_pirateDesc;
}

void Pirate :: SetCurShip(Ship curShip){
  m_curShip = curShip;
}

void Pirate :: CalcTreasure(Ship enemyShip){
  m_pirateCargo += (enemyShip.m_cannon + enemyShip.m_toughness +enemyShip.m_speed)/3;
}

void Pirate :: Battle(Pirate enemyPirate, Ship enemyShip){
  //Checks to see if the player is on 0 toughness before allowing them to fight
  if(m_curShip.m_curToughness > 0){
    int response;
    cout << "You scan the horizon for prospective targets...\nOff in the distance, you see " << enemyPirate.GetName() << " on a " << enemyShip.m_type << "!\n";
    cout << "What would you like to do?\n1. Attack " << enemyPirate.GetName() << "\n2. Attempt to flee from " << enemyPirate.GetName() << endl;
    cin >> response;
    //Input validation
    while(response != 1 && response != 2){
      cout << "What would you like to do?\n1. Attack " << enemyPirate.GetName() << "\n2. Attempt to flee from " << enemyPirate.GetName() << endl;
      cout << "(Please choose an option 1 or 2)\n";
      cin >> response;
    }
    if(response == 1){
      m_pirateDays += 1;
      //Turn counter to keep track of whether the player or the enemy is attacking
      int turn = 1;
      int shotsHit = 0;
      cout << "A naval battle of the ages commences between " << m_pirateName << "and " << enemyPirate.GetName() << endl;
      do{
	if(turn == 1){
	  cout << m_pirateName << " fires " << m_curShip.m_cannon << " cannons!\n";
	  for(int i=0;i<m_curShip.m_cannon;i++){
	    //Using rand in a loop to determine the amount of shots that are hit
	    if((rand()%100+1) <= m_pirateRating){
	      shotsHit += 1;
	    }
	  }
	  cout << shotsHit << " shots hit!\n";
	  m_curShip.m_curToughness -= shotsHit;
	  shotsHit = 0;
	  turn = 2;
	}
	else{
	  cout << enemyPirate.GetName() << " fires " << enemyShip.m_cannon << " back!\n";
	  for(int i=0;i<enemyShip.m_cannon;i++){
	    if((rand()%100+1) <= enemyPirate.GetRating()){
	      shotsHit += 1;
	    }
	  }
	  cout << shotsHit << " shots hit!\n";
	  enemyShip.m_curToughness -= shotsHit;
	  shotsHit = 0;
	  turn = 1;
	}
      }while(m_curShip.m_curToughness > 0 && enemyShip.m_curToughness > 0);
    
      if(m_curShip.m_curToughness > 0){
	cout << "You win!\n" << m_pirateName << " shares " << (enemyShip.m_cannon + enemyShip.m_toughness +enemyShip.m_speed)/3 << " treasure with their crew!\n";
	CalcTreasure(enemyShip);
      }
      else{
	cout << "You lose!\n";
	m_pirateCargo /= 2;
      }
    }
    else{
      Flee(enemyPirate, enemyShip);
    }
  }
  else{
    cout << "You need to repair your ship before you can battle!\n";
  }
}

void Pirate :: RepairShip(){
  int repairDays = m_curShip.m_toughness - m_curShip.m_curToughness;
  cout << "It takes " << repairDays << " days to repair your " << m_curShip.m_type << endl;
  m_pirateDays += repairDays;
  m_curShip.m_curToughness = m_curShip.m_toughness;
}

void Pirate :: Flee(Pirate enemyPirate, Ship enemyShip){
  m_pirateDays += 1;
  cout << "You attempt to flee from " << enemyPirate.GetName() << endl;
  if(enemyShip.m_speed > m_curShip.m_speed){
    cout << "They're too quick! You can't escape!\n";
    Battle(enemyPirate, enemyShip);
  }
  else{
    cout << "You narrowly escape from " << enemyPirate.GetName() << endl;
  }
}

void Pirate :: DisplayScore(){
  cout << "******************************\n";
  cout << "Name  " << m_pirateName << endl;
  cout << "Rating: " << m_pirateRating << endl;
  cout << "Description: " << m_pirateDesc << endl;
  cout << "Days Sailing: " << m_pirateDays << endl;
  cout << "Cargo Captured: " << m_pirateCargo << endl;
  cout << "Cargo Per Day " << double(m_pirateCargo)/double(m_pirateDays) << endl;
  cout << "Ship Type: " << m_curShip.m_type << endl;
  cout << "Ship Cannons: " << m_curShip.m_cannon << endl;
  cout << "Ship Current Toughness: " << m_curShip.m_curToughness << endl;
  cout << "Ship Max Toughness: " << m_curShip.m_toughness << endl;
  cout << "Ship Speed: " << m_curShip.m_speed << endl;
  cout << "******************************\n";
}
