#include <iostream>
using namespace std;

const int BAIT_COST = 5;
const int SELL_PRICE = 10;
const int START_GOLD = 500;

void goFishing(int &fish, int &gold){
  bool answered = false;
  int response = 0;
  do{
    if(answered && response > (BAIT_COST*gold)){
      cout << "You don't have enough gold for that much bait.\n";
      answered = false;
    }
    cout << "How much bait would you like to buy? (5 gold per bait)\n";
    cin >> response;
    answered = true;
  }while(response > (BAIT_COST*gold));
  fish += response;
  gold -= (response*BAIT_COST);
}

void sellFish(int* fish, int* gold){
  *gold += (*fish*SELL_PRICE);
  *fish = 0;
}

int main()
{
  int fish = 0;
  int gold = START_GOLD;
  int* fishPtr = &fish;
  int* goldPtr = &gold;

  cout << "You wake up at 6 am." << endl;
  cout << "You have " << fish << " fish" << endl;
  cout << "You have " << gold << " gold coins" << endl;
  cout << endl;

  goFishing(fish,gold);

  // Call goFishing by reference

  cout << endl;
  cout << "You now have " << fish << " fish" << endl;
  cout << "You now have " << gold << " gold coins" << endl;
  cout << endl;

  // Call sellFish by pointer
  sellFish(fishPtr,goldPtr);

  cout << endl;
  cout << "It is 10 pm and you decide to go to bed" << endl;
  cout << "You end the day with " << fish << " fish" << endl;
  cout << "You end the day with " << gold << " gold coins" << endl;

  return 0;
}

// Implement goFishing and sellFish below
