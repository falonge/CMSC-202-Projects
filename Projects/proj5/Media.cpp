#include <iostream>
#include <string>
#include "Media.h"
using namespace std;

Media :: Media(){
	m_title = "Title";
	m_artist = "Artist";
	m_type = "Music";
	m_year = 0;
	m_rank = 0;
}

Media :: Media(string title, string artist, string type, int year, int rank){
	m_title = title;
	m_artist = artist;
	m_type = type;
	m_year = year;
	m_rank = rank;
}

string Media :: GetTitle()const{
	return m_title;
}

string Media :: GetArtist()const{
	return m_artist;
}

string Media :: GetType()const{
	return m_type;
}

int Media :: GetYear()const{
	return m_year;
}

int Media :: GetRank()const{
	return m_rank;
}

void Media :: SetTitle(string title){
	m_title = title;
}

void Media :: SetArtist(string artist){
	m_artist = artist;
}

void Media :: SetType(string type){
	m_type = type;
}

void Media :: SetYear(int year){
	m_year = year;
}

void Media :: SetRank(int rank){
	m_rank = rank;
}

ostream& operator<<(ostream& out, Media& m){
	out << m.m_title << " by " << m.m_artist << " from " << m.m_year << endl;
	return out;
}

bool Media :: operator<(const Media& m){
	if(m.m_year < m_year){
		return true;
	}
	return false;
}
