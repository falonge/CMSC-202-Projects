//Train .cpp
#include <string>
#include <fstream>
#include <iostream>
#include "Train.h"
using namespace std;

//Constructor for train
Train :: Train(Route* route){
  m_route = route;
  m_head = nullptr;
  m_totalCars = 0;
}

//Destructor for train
Train :: ~Train(){ //iterates through each car, then in each car iterates through each passenger and deletes each one, then deletes the car
  Car* previous = m_head;
  Car* current = m_head;
  while(current != m_head){
    for(unsigned int i=0;i<current->m_passengers.size();i++){
      delete current->m_passengers[i];
    }
    current = current->m_next;
    delete previous;
    previous = current;
  }
}

//Adds Car to the end of the train
void Train :: AddCar(){
  //integer to count how many cars there are to get the right car number
  int numCars = 0;
  if(m_head != nullptr){
    Car* temp = m_head;
    while(temp != nullptr){
      numCars += 1;
      temp = temp->m_next;
    }
  }
  Car* newCar = new Car(0, (numCars+1));
  Car* temp = m_head;
  //iterates through the train and then sets the last car to the a car
  if(m_head == nullptr){
    m_head = newCar;
  }
  else{
    while(temp->m_next != nullptr){
      temp = temp->m_next;
    }
    temp->m_next = newCar;
  }
  m_totalCars += 1;
}

//Removes Car from anywhere in the train
void Train :: RemoveCar(Car* car){
  Car* previous = nullptr;
  Car* current = m_head;
  while(current != nullptr){
    if(current->m_carNumber == car->m_carNumber){
      previous->m_next = current->m_next;
      delete current;
    }
    else{
      current = current->m_next;
    }
  }
}

//Prints the current status of train
void Train :: TrainStatus(){
  cout << "Number of cars: " << m_totalCars << endl;
  Car* temp = m_head;
  while(temp != nullptr){
    cout << "Car " << temp->m_carNumber << ": Number of passengers: " << temp->m_capacity << endl;
    temp = temp->m_next;
  }
  cout << "Current stop is: " << m_route->GetCurrentStop()->GetName() << " (" << m_route->GetCurrentStop()->GetNumber() << ")\n";
  cout << "Next stop is: " << m_route->GetCurrentStop()->GetNextStop()->GetName() << " (" << m_route->GetCurrentStop()->GetNextStop()->GetNumber() << ")\n";
}

//Reads in passengers from the file and boards them if they are at the correct start destination
void Train :: LoadPassengers(string passName){
  //Similar code to LoadRoute() see (Route.cpp)
  ifstream passFile;
  passFile.open(passName);
  int dataType = 1;
  int wordSize = 0;
  string name;
  int age;
  string start;
  string end;
  char endOfWord = ' ';
  int counter = 0;
  int boarded = 0;
  while(counter < 300){
    char currWord[100] = {};
    wordSize = 0;
    while(endOfWord != ',' && endOfWord != '\n'){
      passFile.get(endOfWord);
      if(endOfWord != ',' && endOfWord != '\n'){
	currWord[wordSize] = endOfWord;
	wordSize++;
      }
    }
    switch(dataType){
    case 1:
      name = currWord;
      dataType++;
      break;
    case 2:
      name += ' ';
      name += currWord;
      dataType++;
      break;
    case 3:
      age = atoi(currWord);
      dataType++;
      break;
    case 4:
      start = currWord;
      dataType++;
      break;
    case 5:
      end = currWord;
      dataType++;
      break;
    }
    if(dataType == 6){
      //checks if the start destination of the passenger matches the current location
      if(m_route->GetCurrentStop()->GetName() == start){
	Passenger* p = new Passenger(name, age, start, end);
	BoardPassenger(p);
	boarded++;
	cout << name << " boards the train (Destination: " << end << ")\n";
      }
      dataType = 1;
      counter++;
    }
    endOfWord = ' ';
  }
  cout << "Boarded " << boarded << " passengers\n";
}

//Boards passenger on the first availble space on the train, and adds a new car if all the cars are full
void Train :: BoardPassenger(Passenger* newPassenger){
  if(m_head == nullptr){
    AddCar();
  }
  Car* temp = m_head;
  //bool to stop the while loop when a car is added to the end
  bool addedCar = false;
  while(temp->m_capacity >= CAR_CAPACITY && !addedCar){
    if(temp->m_next == nullptr){
      AddCar();
      addedCar = true;
    }
    temp = temp->m_next;
  }
  temp->AddPassenger(newPassenger);
  temp->m_capacity += 1;
}

//Iterates through the train and removes passengers if they are at the correct final destination
void Train :: DisembarkPassengers(){
  Car* temp = m_head;
  int passengers = 0;
  while(temp != nullptr){
    for(unsigned int i=0;i<temp->m_passengers.size();i++){
      if(temp->m_passengers[i]->GetFinalDestination() == m_route->GetCurrentStop()->GetName()){
	cout << temp->m_passengers[i]->GetName() << " disembarked the train. (Destination: " << m_route->GetCurrentStop()->GetName() << ")\n";
	passengers++;
	delete temp->m_passengers[i];
	temp->m_passengers.erase(temp->m_passengers.begin()+(i));
      }
    }
    temp = temp->m_next;
  }
  cout << passengers << " passengers disembarked.\n";
}

//Moves the rain to the next stop
void Train :: TravelToNextStop(){
  if(m_route->GetCurrentStop()->GetNextStop() == nullptr){
    cout << "You're at the end of the route.\n";
  }
  else{
    m_route->SetCurrentStop(m_route->GetCurrentStop()->GetNextStop());
    cout << "Arriving at " << m_route->GetCurrentStop()->GetName() << endl;
  }
}

//Reverses the route if the train is at the last stop
void Train :: TurnTrainAround(){
  if(m_route->GetCurrentStop()->GetNextStop() == nullptr){
    cout << "30 routes reversed";
    m_route->ReverseRoute();
  }
  else{
    cout << "You can only reverse the route when at the end of the route.\n";
  }
}

//Checks if train is full
bool Train :: IsTrainFull(){
  Car* temp = m_head;
  while(temp != nullptr){
    if(temp->m_capacity < CAR_CAPACITY){
      return false;
    }
  }
  return true;
}
