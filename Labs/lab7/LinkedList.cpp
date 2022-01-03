/******************************
** File: LinkedList.cpp
** Lab: CMSC 202 Lab8
** Author: Nathenael Dereb
** Date: 09/05/2020
** Email: ndereb1@umbc.edu
**
** Lab8 for cmsc 202
**
** Checks if a linked list is a palindrome.
******************************/

#include "LinkedList.h"

LinkedList::LinkedList(): m_head(nullptr) {};

LinkedList::~LinkedList() {
    Node* current = m_head;
    while (m_head) {
        m_head = m_head->next;
        delete current;
        current = m_head;
    }
}

// Inserts node at the end of the linked list
void LinkedList::insertAtEnd(char letter){
    if(m_head == nullptr) {
        m_head = new Node(letter);
    }
    else {
        Node *current = m_head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(letter);
    }
}

// Inserts node at the front of the linked list
void LinkedList::insertAtFront(char letter) {
    if(m_head == nullptr) {
        m_head = new Node(letter);
    }
    else {
        m_head = new Node(letter, m_head);
    }
}

// Displays/Prints the linked list
void LinkedList::display() {
    Node* current = m_head;
    while(current) {
        cout << current->letter;
        current = current->next;
    }
    cout << endl;
}

// *** TODO ***
// Implement reverse function - reverses the linked list
// Should return the reversed linked list
// Note: Keep this->m_head in position.
LinkedList* LinkedList::reverse() {
  //making a copy of the linked list
  LinkedList* reverseList = this;
  //making 3 different nodes to iterate through the linked list
  Node* current = m_head;
  Node* previous = nullptr;
  Node* next = nullptr;
  while(current != nullptr){
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  m_head = previous;
  return reverseList;
}

// *** TODO ***
// Implement isPalindrome function
// Utilize reverse function to implement this function
// Note: Keep this->m_head in position.
bool LinkedList::isPalindrome() {
  Node* current1 = m_head;
  Node* current2 = this->reverse()->m_head;
  //goes through both lists and compares each letter to see if they are identical
  while(current1){
    if(current1->letter != current2->letter){
      return false;
    }
    current1 = current1->next;
    current2 = current2->next;
  }
  return true;
}
