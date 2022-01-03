//Route.cpp
#include <string>
#include <fstream>
#include <iostream>
#include "Route.h"
using namespace std;

//Constructor for Route
Route :: Route(){
  m_head = nullptr;
  m_tail = nullptr;
  m_currentStop = nullptr;
  m_totalStops = 0;
}

//Destructor for Route
Route :: ~Route(){
  //setting two stops to keep iterate through the list
  Stop* previous = m_head;
  Stop* current = m_head;
  //moving the current to the next node, and then deleting the last node
  while(current != nullptr){
    current = current->GetNextStop();
    delete previous;
    // cout << previous->GetName()<<endl;
    previous = current;
    }
}

//Reads routes from the file and adds them to the program
void Route :: LoadRoute(string file){
  ifstream dataFile;
  dataFile.open("proj3_routes.txt");
  //making new variables to keep store the data from the file
  int dataType = 1;
  int wordSize = 0;
  int currentStops = 0;
  string stop;
  int stopNum;
  char endOfWord;
  while(currentStops < 30){
    char currWord[100] = {};
    wordSize = 0;
    //Adds new letters until it gets to a comma or the end of the line
    while(endOfWord != ',' && endOfWord != '\n'){
      dataFile.get(endOfWord);
      if(endOfWord != ',' && endOfWord != '\n'){
	currWord[wordSize] = endOfWord;
	wordSize++;
      }
    }
    //stores created word in a variable based on what the current datatype is
    switch(dataType){
    case 1:
      stop = currWord;
      dataType++;
      break;
    case 2:
      stopNum = atoi(currWord);
      dataType++;
      break;
    }
    if(dataType == 3){
      AddStop(stop, stopNum);
      currentStops++;
      dataType = 1;
    }
    endOfWord = ' ';
  }
  m_currentStop = m_head;
  cout << "Route loaded with 30 stops\n";
}

//Adds a stop to the end of the route
void Route :: AddStop(string stop, int stopNum){
  Stop* newStop = new Stop(stop, stopNum);
  if(m_head == nullptr){
    m_head = newStop;
    m_head->SetNextStop(nullptr);
  }
  else if(m_head->GetNextStop() == nullptr){
    m_tail = newStop;
    m_head->SetNextStop(m_tail);
    m_tail->SetNextStop(nullptr);
  }
  else{
    m_tail->SetNextStop(newStop);
    m_tail = newStop;
  }
}

//Prints the current stop and next stop
void Route :: PrintRouteDetails(){
  if(m_currentStop->GetNextStop() == nullptr){
    cout << "Current Stop: " << endl;
  }
  else{
    cout << "Current Stop: " << m_currentStop->GetName() << "\nNext Stop: " << m_currentStop->GetNextStop()->GetName() << endl;
  }
}

//Getter for current stop
Stop* Route :: GetCurrentStop(){
  return m_currentStop;
}

//Setter for current stop
void Route :: SetCurrentStop(Stop* stop){
  m_currentStop = stop;
}

//Reverses the route
void Route :: ReverseRoute(){
  //making three stops to iterate through the list. Sets the current node to the last node for each one
  Stop* current = m_head;
  Stop* prev = nullptr;
  Stop* next = nullptr;
  while(current != nullptr){
    next = current->GetNextStop();
    current->SetNextStop(prev);
    prev = current;
    current = next;
  }
  m_head = prev;
  m_currentStop = prev;
  Stop* temp = m_head;
  //Goes to the last node and sets the tail to the last one
  for(int i=0;i<29;i++){
    temp = temp->GetNextStop();
  }
  m_tail = temp;
}
