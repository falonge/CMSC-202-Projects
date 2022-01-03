#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "MediaPlayer.h"
using namespace std;

MediaPlayer :: MediaPlayer(){

}

MediaPlayer :: MediaPlayer(string filename){
	LoadCatalog(filename);
}

MediaPlayer :: ~MediaPlayer(){
	for(unsigned int i=0;i<m_mediaCatalog.size();i++){
		delete m_mediaCatalog[i];
	}
}

void MediaPlayer :: LoadCatalog(string filename){
	ifstream mediaFile;
	mediaFile.open(filename);
	string title;
	string artist;
	string type;
	string year;
	string rank;
	while(getline(mediaFile,title,';') && getline(mediaFile,artist,';') && getline(mediaFile,type,';') && getline(mediaFile,year,';') && getline(mediaFile,rank)){
		Media* newMedia = new Media(title,artist,type,stoi(year),stoi(rank));
		m_mediaCatalog.push_back(newMedia);
	}
}

void MediaPlayer :: MainMenu(){
	int response = 0;
	bool quit = false;
	while(quit == false){
		do{
			cout << "What would you like to do?\n1. Display Media by Type and Year\n2. Add Media to Playlist\n3. Display Playlist\n4. Sort Playlist by Year\n5. Quit\n";
			cin >> response;
		}while(response < 1 || response > 5);
		switch(response){
		case 1:
			DisplayMedia();
			break;
		case 2:
			DisplayMedia();
			AddMedia();
			break;
		case 3:
			DisplayPlaylist();
			break;
		case 4:
			SortPlaylist();
			break;
		case 5:
			cout << "Thank you for using the UMBC Media Player\n";
			quit = true;
			break;
		}
	}
}

int MediaPlayer :: DisplayMedia(){
	string type;
	int year;
	int counter;
	do{
		cout << "Which media would you like to display?\nmusic\npodcast\n";
		cin >> type;
	}while(type != "music" && type != "podcast");
	do{
		cout << "Which year would you like to display? (1958 to 2020)\n";
		cin >> year;
	}while(year < 1958 || year > 2020);

	cout << "******" << year << "******\n";
	for(unsigned int i=0;i<m_mediaCatalog.size();i++){
		if(m_mediaCatalog[i]->GetType() == type){
			if(m_mediaCatalog[i]->GetYear() == year){
				cout << i << ". " << *m_mediaCatalog[i];
				counter++;
			}
		}
	}
	return counter;
	return 0;
}

void MediaPlayer :: AddMedia(){
	int index;
	cout << "Choose the media you would like to add to the playlist.\n";
	cin >> index;
	m_playList.Enqueue(m_mediaCatalog[index]);
	cout << m_mediaCatalog[index]->GetTitle() << " by " << m_mediaCatalog[index]->GetArtist() << " has been added to the playlist.\n";
}

void MediaPlayer :: DisplayPlaylist(){
	if(m_playList.Size() == 0){
		cout << "The playlist is currently empty.\n";
	}
	else{
		m_playList.DisplayAll();
	}

}
void MediaPlayer :: SortPlaylist(){
	m_playList.Sort();
}
