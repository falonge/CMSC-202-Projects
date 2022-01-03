#include <iostream>
#include <string>
using namespace std;

int main(){
  string name;
  int age;
  cout << "What is your dog's name?\n";
  cin >> name;
  cout << "How old is your dog?\n";
  cin >> age;
  while(cin.fail() || age < 0 || age > 22){
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Please enter your dog's age, it should be an integer between 0 and 22\n";
    cin >> age;
  }
  cout << "Dog Name = " << name << "\nDog's age = " << age << "\n\n";
  int response;
  for(int i=0;i<3;i++){
    cout << "What would you like to do?\n1. Pet " << name << "\n2. Feed " << name << "\n3. Chase " << name << "\nEnter your choice:\n";
    cin >> response;
    while(cin.fail() || response < 1 || response > 3){
      cout << "Enter your choice(1-3)\n";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> response;
    }
    if(response == 1){
      cout << "You pet " << name << " and they are happy.\n";
    }
    else if(response == 2){
      cout << name << " growls gently as you feed them.\n";
    }
    else if(response == 3){
      cout << "You chase after " << name << " and they wag their tail.\n";
    }
  }
  cout << "That is enough for today. Good-bye.";
  return 0;
}
