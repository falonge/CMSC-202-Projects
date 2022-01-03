#include "Game.h"
#include "Pirate.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

Game :: Game(){
  GameTitle();
  LoadShips();
  LoadPirates();
}

void Game :: LoadShips(){
  ifstream shipFile;
  shipFile.open(PROJ2_SHIPS);
  //These 3 variables will be used to keep track of various things while reading in the file
  int dataType = 1;
  int wordSize = 0;
  int listSize = 0;
  char endOfWord;
  while(listSize < MAX_SHIPS){
    //A character list that will be used to store the current word being built for each iteration of this loop
    char currWord[1000] = {};
    wordSize = 0;
    /*This will look for a comma as a representation of a completed word/data entry if the data type is 1-4 (first through fourth word in the line) or a "\n" if the data type is 5*/
    if(dataType < 5){
      //Continually checks a new character until it runs into a comma
      while(endOfWord != ','){
	shipFile.get(endOfWord);
	//Checks for a comma again and adds the character to the list
	if(endOfWord != ','){
	  currWord[wordSize] = endOfWord;
	  wordSize++;
	}
      }
    }
    else{
      //Essentially the same thing as the loop above but for a '\n' instead
      while(endOfWord != '\n'){
	shipFile.get(endOfWord);
	if(endOfWord != '\n'){
	  currWord[wordSize] = endOfWord;
	  wordSize++;
	}
      }
    }
    //Stores the created word in a spot depending on the current data type
    switch(dataType){
    case 1:
      m_ships[listSize].m_type = currWord;
      break;
    case 2:
      m_ships[listSize].m_cannon = atoi(currWord);
      break;
    case 3:
      m_ships[listSize].m_toughness = atoi(currWord);
      break;
    case 4:
      m_ships[listSize].m_speed = atoi(currWord);
      break;
    case 5:
      m_ships[listSize].m_desc = currWord;
      listSize++;
      break;
    }
    // Changes to the next data type before the loop restarts
    dataType++;
    if(dataType == 6){
      dataType = 1;
    }
    //clearing the current character being checked
    endOfWord = ' ';
  }
  shipFile.close();
  //Sets the toughness of each ship
  for(int i=0;i<MAX_SHIPS;i++){
    m_ships[i].m_curToughness = m_ships[i].m_toughness;
  }
}

void Game :: LoadPirates(){
  //Basically the same code from LoadShips but with pirates instead
  ifstream pirateFile;
  pirateFile.open(PROJ2_PIRATES);
  int dataType = 1;
  int wordSize = 0;
  int listSize = 0;
  string name;
  int rating;
  string origin;
  string description;
  char endOfWord;
  while(listSize < MAX_PIRATES){
    char currWord[1000] = {};
    wordSize = 0;
    if(dataType < 4){
      while(endOfWord != ','){
	pirateFile.get(endOfWord);
	if(endOfWord != ','){
	  currWord[wordSize] = endOfWord;
	  wordSize++;
	}
      }
    }
    else{
      while(endOfWord != '\n'){
	pirateFile.get(endOfWord);
	if(endOfWord != '\n'){
	  currWord[wordSize] = endOfWord;
	  wordSize++;
	}
      }
    }
    switch(dataType){
    case 1:
      name = currWord;
      break;
    case 2:
      rating = atoi(currWord);
      break;
    case 3:
      origin = currWord;
      break;
    case 4:
      description = currWord;
      break;
    }
    dataType++;
    if(dataType == 5){
      m_allPirates[listSize] = Pirate(name, rating, origin, description);
      listSize++;
      dataType = 1;
    }
    endOfWord = ' ';
  }
  pirateFile.close();
}

void Game :: StartGame(){
  //Giving the user a random pirate and ship
  int randPirate = rand()%(MAX_PIRATES+1);
  int randShip = rand()%(MAX_SHIPS+1);
  m_myPirate = m_allPirates[randPirate];
  m_myPirate.SetCurShip(m_ships[randShip]);
  cout << "Congratulations! " << m_myPirate.GetName() << " is now available to plunder!\n";
  cout << m_myPirate.GetName() << " is aboard a " << m_ships[randShip].m_type << ".\n";
  int response;
  do{
    response = MainMenu();
    switch(response){
    case 1:
      SearchTreasure();
      break;
    case 2:
      m_myPirate.RepairShip();
      break;
    case 3:
      m_myPirate.DisplayScore();
      break;
    }
  }while(response != 4);
  m_myPirate.DisplayScore();
  cout << m_myPirate.GetName() << " sails off into retirement!\nThanks for playing Pirates!\n";
}

int Game :: MainMenu(){
  int response;
  cout << "What would you like to do?\n1. Search for Treasure\n2. Repair Ship\n3. See Score\n4. Retire\n";
  cin >> response;
  //Input validation
  while(response < 1 ||  response > 4){
    cout << "What would you like to do?\n1. Search for Treasure\n2. Repair Ship\n3. See Score\n4. Retire\n(Please choose a number from 1 o 4)\n" ;
    cin >> response;
  }
  return response;
}

void Game :: SearchTreasure(){
  m_myPirate.Battle(m_allPirates[rand()%(MAX_PIRATES+1)], m_ships[rand()%(MAX_SHIPS+1)]);
}
