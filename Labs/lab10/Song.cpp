#include "Song.h"
#include <string>
#include <iostream>

using namespace std;

Song :: Song(string songName, string artist){
  m_song = songName;
  m_artist = artist;
}

/*Hiphop :: Hiphop(string songName, string artist){
  m_song = songName;
  m_artist = artist;
}

Pop :: Pop(string songName, string artist){
  m_song = songName;
  m_artist = artist;
  }*/

void Song :: Play(){
  cout << "Alright y'all, here we go with " << m_song << " by " << m_artist << " only on Quarantine Radio!\n";
}

void Song :: Request(){
  cout << "Someone's calling in asking for another song\n";
}

void Song :: Like(){
  cout << "We knew you'd like that one, adding " << m_song << " by " << m_artist << " to your playlist.\n";
}
