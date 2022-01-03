#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int FIRSTWORDLENGTH = 6;

void countLetters(char wordList[][6]){
  int count;
  for(int i=0;i<3;i++){
    char currWord[100] = {};
    count = 0;
    for(int j=0;j<FIRSTWORDLENGTH;j++){
      if(wordList[i][j]){
        count++;
	currWord[j] = wordList[i][j];
      }
    }
    cout << i+1 << ". " << currWord << "(" << count << " letters)\n";
  }
}

bool checkLetter(char letter, char word[], int size){
  for(int i=0;i<size;i++){
    if(word[i] == letter){
      return true;
    }
  }
  return false;
}

bool compareWords(char wordOne[], char wordTwo[]){
  int wordSize = 0;
  for(int i=0;i<FIRSTWORDLENGTH;i++){
    if(wordOne[i]){
      wordSize++;
    }
  }
  bool removed = false;
  int removeCounter = 0;
  for(int i=0;i<wordSize;i++){
    removed = false;
    if(checkLetter(wordTwo[i], wordOne, wordSize)){
      for(int j=0;j<wordSize;j++){
        if(wordTwo[i] == wordOne[j] && !removed){
	  wordOne[j] = '.';
	  removeCounter++;
	  removed = true;
	}
      }
    }
  }
  if(removeCounter == (wordSize-1)){
    return true;
  }
  else{
    return false;
  }
}

bool checkWordCount(char wordOne[], char wordTwo[], int wordOneSize){
  int wordTwoSize = 0;
  for(int i=0;i<FIRSTWORDLENGTH;i++){
    if(wordTwo[i]){
      wordTwoSize++;
    }
  }
  if(wordTwoSize == (wordOneSize - 1)){
    return true;
  }
  return false;
}

char validateInput(char response){
  while(response != 'n' && response != 'y' && response != 'N' && response != 'Y'){
    cout << "Please type y/n ";
    cin.clear();
    cin.ignore(256,'\n');
    cin >> response;
  }
  if(response == 'n' or response == 'N'){
    return 'n';
  }
  return 'y';
}

int main() {
  char playAgain;
  string fileName;
  cout << "Welcome to Escalators\n";
  do{
    ifstream textFile;
    do{
      cout << "What is the file name of the list of words? ";
      cin >> fileName;
      textFile.open(fileName);
      if(textFile.fail()){
	cout << "No file found\n";
      }
    }
    while(textFile.fail());
    char charList[3][6] = {};
    char currChar;
    for(int i=0;i<3;i++){
      int j = 0;
      while(currChar != '\n'){
        textFile.get(currChar);
        if(currChar != '\n'){
          charList[i][j] = currChar;
          j++;
        }
      }
      currChar = '.';
    }
    textFile.close();
    countLetters(charList);
    bool wordCount;
    if(checkWordCount(charList[0], charList[1], 6)){
      if(checkWordCount(charList[1], charList[2], 5)){
        wordCount = true;
      }
      else{
        wordCount = false;
      }
    }
    else{
      wordCount = false;
    }
    if(!wordCount){
      cout << "Words are not correct length\nThis list is not valid!\n";
    }
    bool letterFrequency;
    if(wordCount){
      if(compareWords(charList[0], charList[1])){
        if(compareWords(charList[1], charList[2])){
  	  letterFrequency = true;
        }
        else{
	  letterFrequency = false;
        }
      }
      else{
        letterFrequency = false;
      }
      if(letterFrequency){
        cout << "The list is valid!\n";
      }
      else{
        cout << "Words do not share appropriate letter frequency\n";
      }
    }
    cout << "Check another list? (y/n) ";
    cin >> playAgain;
    playAgain = validateInput(playAgain);
  }
  while(playAgain != 'n');
  cout << "Thank you for playing Escalators!\n";
  return 0;
}
