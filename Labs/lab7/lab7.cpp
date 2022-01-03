/******************************
** File: lab7.cpp
** Lab: CMSC 202 Lab8
** Author: Nathenael Dereb
** Date: 09/05/2020
** Email: ndereb1@umbc.edu
**
** Lab8 for cmsc 202
**
** Checks if a linked list is a palindrome.
******************************/

#include <string>
#include <vector>
#include "LinkedList.h"
using namespace std;

int main() {
  LinkedList* linkedLetters;
  vector<string> wordList;
  wordList.push_back("tenet");
  wordList.push_back("LOLO");
  wordList.push_back("Zendaya");
  wordList.push_back("kayak");
  wordList.push_back("step on no pets");
  wordList.push_back("I did did I");
  wordList.push_back("CMSC 202");
  wordList.push_back("wasitacatisaw");
  
  // Test Cases
  for(unsigned int i = 0; i < wordList.size(); i++) {
    linkedLetters = new LinkedList();
    for (unsigned int j = 0; j < wordList.at(i).size(); j++) {
      linkedLetters->insertAtEnd(wordList.at(i).at(j));
    }
    cout << "The word: " << wordList.at(i) << " " << (linkedLetters->isPalindrome()?"is ": "is not ") << "a palindrome." << endl; 
    delete linkedLetters;
  }
 
  return 0;
}
