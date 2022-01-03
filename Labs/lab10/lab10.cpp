#include "Song.h"
#include <iostream>
#include <string>
using namespace std;

int main () {

  Song newSong ("Go Crazy", "Chris Brown");
  Hiphop hiphop1("POPSTAR(feat. Drake)", "DJ Khaled");
  Pop pop1("In Your Eyes", "The Weeknd");

  Song * song1 = &newSong;
  Song * song2 = &hiphop1;
  Song * song3 = &pop1;

  cout << "*** QUARANTINE QUARANTINE QUARANTINE!!! ***" << endl;
  cout << "Yo this is Quarantine Radio live with your boy DJ Pain." << endl; 
  song1->Play();
  song1->Like();
  
  cout << endl << "*** QUARANTINE QUARANTINE QUARANTINE!!! ***" << endl;
  cout << "Hold on folks, we are live back on Quarantine Radio."
      << " Hit us up man, (850) 321-8692." << endl;
  song2->Request();
  song2->Play();
  song2->Like();

  cout << endl << "*** QUARANTINE QUARANTINE QUARANTINE!!! ***" << endl;
  cout << "Ladies and gentlemen, you heard it here first, Quarantine Radio live." << endl;
  song3->Request();
  song3->Play();
  song3->Like();

  cout << endl << "*** QUARANTINE QUARANTINE QUARANTINE!!! ***" << endl;
  cout << "I gotta get out of here man." << endl;
  cout << "This is your boy DJ Pain from Quarantine Radio." << endl;
  cout << "I just wanna leave with saying I hope everyone stays corona-free." << endl;
  cout << "We, love, you." << endl;
  
  return 0;
}
