//Game.cpp
#include "Game.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//Default constructor
Game :: Game(){
  string filename;
  cout << "What is the name of the file?\n";
  cin >> filename;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  LoadMap(filename);
  PlantCreation();
  StartGame();
}

//Overloaded Constructor
Game :: Game(string file){
  LoadMap(file);
  PlantCreation();
  StartGame();
}

//Destructor
Game :: ~Game(){
  delete m_myPlant;
  delete m_curZombie;
  for(unsigned int i=0; i<m_myMap.size();i++){
    delete m_myMap[i];
  }
}

//Loads in the map by reading in the file and adding new rooms to the m_myMap vector
void Game :: LoadMap(string file){
  ifstream mapFile;
  mapFile.open(file); 
  //Initializing variables to store the values for rooms
  string currWord;
  string id;
  string name;
  string desc;
  string north;
  string east;
  string south;
  string west;
  while(getline(mapFile, id, '|') && getline(mapFile, name, '|') && getline(mapFile, desc, '|') && getline(mapFile, north, '|') && getline(mapFile, east, '|') && getline(mapFile, south, '|') && getline(mapFile, west)){
    Room* newRoom = new Room(stoi(id), name, desc, stoi(north), stoi(east), stoi(south), stoi(west));
    m_myMap.push_back(newRoom);
  }
}

//Creates a plant by askng the user for a name and class
void Game :: PlantCreation(){
  string name;
  cout << "Plant name: ";
  cin >> name;
  int type;
  do{
    cout << "Select a class:\n1. Peashooter\n2. Chomper\n3. Sunflower\n4. No Class\n";
    cin >> type;
  }while(type < 1 || type > 4);
  
  //Makes a new plant based on response
  switch(type){
  case 1:
    m_myPlant = new Peashooter(name, PEASHOOTER_HEALTH);
    break;
  case 2:
    m_myPlant = new Chomper(name, CHOMPER_HEALTH);
    break;
  case 3:
    m_myPlant = new Sunflower(name, SUNFLOWER_HEALTH);
    break;
  case 4:
    m_myPlant = new Plant(name, PLANT_HEALTH);
    break;
  }
}

//Sets the intital values for rests and special, starts player at first room, and calls Action()
void Game :: StartGame(){
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_curRoom = 0;
  Action();
}

//Controls the menu and allows the user to play the main part of the game
void Game :: Action(){//Boolean to keep track if a zombie is in the current room
  //Creating a 25% chance of spawning a zombie in a new room
  m_curZombie = RandomZombie();
  m_myMap[m_curRoom]->PrintRoom();
  //Tells the player which zombie is in the room if a zombie spawns
  if(m_curZombie){
    if(m_curZombie->GetName() == "Buckethead"){
      cout << "A buckethead zombie teaters here with a bucket on his head.\n";
    }
    else if(m_curZombie->GetName() == "Engineer"){
      cout << "A large zombie stands here wearing khakis with a sign that says ENGINEER.\n";
    }
    else if(m_curZombie->GetName() == "Imp"){
      cout << "A dirty imp licks his lips and glares at you.\n";
    }
  }
  bool quit = false;
  int response;
  //Continually displays the menu until the player dies or quits
  while(!quit){
    do{
      cout << "What would you like to do?\n\n1. Look\n2. Move\n3. Attack Zombie\n4. Rest\n5. Check Stats\n6. Quit\n";
      cin >> response;
    }while(response < 0 || response > 6);

    //Does various actions based on user response
    switch(response){
    case 1:
      m_myMap[m_curRoom]->PrintRoom();
      break;
    case 2:
      delete m_curZombie;
      Move();
	m_curZombie = RandomZombie();
      m_myMap[m_curRoom]->PrintRoom();
      if(m_curZombie){
	if(m_curZombie->GetName() == "Buckethead"){
	  cout << "A buckethead zombie teaters here with a bucket on his head.\n";
	}
	else if(m_curZombie->GetName() == "Engineer"){
		cout << "A large zombie stands here wearing khakis with a sign that says ENGINEER.\n";
	}
	else if(m_curZombie->GetName() == "Imp"){
	  cout << "A dirty imp licks his lips and glares at you.\n";
	}
      }
      break;
    case 3:
      if(m_curZombie){
	Attack();
      }
      else{
	cout << "There's no zombie to attack.\n";
      }
      if(m_myPlant->GetHealth() <= 0){
	quit = true;
      }
      break;
    case 4:
      //Prevents the player from resting if a zombie is in the room
      if(m_curZombie){
	cout << "You cannot rest while a zombie is in the room.\n";
      }
      else{
	Rest();
      }
      break;
    case 5:
      cout << "Name: " << m_myPlant->GetName() << "\nHP: " << m_myPlant->GetHealth() << "\nRests: " << m_numRests << "\nSpecial: " << m_numSpecial << endl;
      break;
    case 6:
      cout << "Good bye!\n";
      quit = true;
    }
  }
}

//Gets a random zombie type
Entity* Game :: RandomZombie(){
  Entity* newZombie;
  int randomType = rand()%4+1;
  switch(randomType){
  case 1:
    newZombie = new Buckethead();
    break;
  case 2:
    newZombie = new Engineer();
    break;
  case 3:
    newZombie = new Imp();
    break;
  case 4:
    newZombie = nullptr;
  }
  return newZombie;
}

//Heals the player for 10 hp if they have rests available
void Game :: Rest(){
  if(m_numRests <= 0){
    cout << "You are out of rests.\n";
  }
  else{
    m_myPlant->SetHealth(m_myPlant->GetHealth() + REST_HEAL);
    cout << "You rested and healed for 10 hp.\n Current health: " << m_myPlant->GetHealth() << endl;
    m_numRests -= 1;
  }
}

//Asks the player which room they want to move to before moving to a new room
void Game :: Move(){
  bool inputVal = false;
  char response;
  //Checks for valid input, whether the player actually picks from NESW and if the player chooses a direction with an exit
  while(!inputVal){
    do{
      cout << "Which direction? (N E S W)\n";
      cin >> response;
    }while(response != 'N' && response != 'n' && response != 'E' && response != 'e' && response != 'S' && response != 's' && response != 'W' && response != 'w');
    inputVal = true;
    if(m_myMap[m_curRoom]->CheckDirection(response) == -1){
      cout << "There's no exit that way.\n";
      inputVal = false;
    }
  }
  m_curRoom = m_myMap[m_curRoom]->CheckDirection(response);
}

//Manages the attack sequence between the player and a zombie
void Game :: Attack(){
  //Continues until the player or the zombie dies
  while(m_myPlant->GetHealth() > 0 && m_curZombie->GetHealth() > 0){
    cout << m_myPlant->GetName() << "'s health: " << m_myPlant->GetHealth() << endl << m_curZombie->GetName() << "'s health: " << m_curZombie->GetHealth() << endl;
    int response;
    //do-while loop for input validation
    do{
      cout << "1. Normal Attack\n2. Special Attack\n";
      cin >> response;
      if(response == 2 && m_numSpecial <= 0){
	cout << "You're out of special attacks!\n";
	response = 3;
      }
    }while(response != 1 && response != 2);
    if(response == 1){
      m_curZombie->SetHealth(m_curZombie->GetHealth()-m_myPlant->Attack());
    }
    else{
      m_curZombie->SetHealth(m_curZombie->GetHealth()-m_myPlant->SpecialAttack());
      m_numSpecial -= 1;
    }
    //Creates a 25% chance for the zombie to do a special attack
    if(rand()%4+1 == 1){
      m_myPlant->SetHealth(m_myPlant->GetHealth()-m_curZombie->SpecialAttack());
    }
    else{
      m_myPlant->SetHealth(m_myPlant->GetHealth()-m_curZombie->Attack());
    }
  }
  if(m_myPlant->GetHealth() <= 0){
    cout << "You lost!\n";
  }
  else{
    cout << "You have defeated the " << m_curZombie->GetName() << ".\n";
  }
  delete m_curZombie;
  m_curZombie = nullptr;
}
