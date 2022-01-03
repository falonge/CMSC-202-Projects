#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <string>

using namespace std;

class Song{
public:
  Song(string songName, string artist);
  virtual void Play();
  virtual void Request();
  virtual void Like();
protected:
  string m_song;
  string m_artist;
};

class Hiphop: public Song{
public:
  Hiphop(string songName, string artist): Song(songName, artist){}
  void Play(){
    cout << "Alright, we got some more hip-hop heat for yall today, here's " << m_song << " by " << m_artist << ".\n";
  }
  void Request(){
    cout << "We got someone on the line requesting some more hip-hop.\n";
  }
  void Like(){
    cout << "You liked that one? Alright adding " << m_song << "by " << m_artist << " to your hip-hop playlist.\n";
  }
};

class Pop: public Song{
public:
  Pop(string songName, string artist): Song(songName, artist){}
  void Play(){
    cout << "Alright, time for some pop music, here's " << m_song << " by " << m_artist << ".\n";
  }
  void Request(){
    cout << "We got calling requesting some pop music.\n";
  }
  void Like(){
    cout << "We knew you'd be into that one, adding " << m_song << " by " << m_artist << " to your pop playlist.\n";
  }
};

#endif
  
