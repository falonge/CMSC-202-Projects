/******************************
** File: LinkedList.h
** Lab: CMSC 202 Lab7
** Author: Nathenael Dereb
** Date: 09/05/2020
** Email: ndereb1@umbc.edu
**
** Lab8 for cmsc 202
**
** Checks if a linked list is a palindrome.
******************************/

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
using namespace std;

struct Node {
    char letter;
    Node* next;
    
    Node() : next(nullptr) {}
    
    Node(char letter) {
        this->letter = letter;
        next = nullptr;
    }
    
    Node(char letter, Node* next) {
        this->letter = letter;
        this->next = next;
    }
};

class LinkedList {
public:
    // Default Constructor
    LinkedList();
    
    // Destructor
    ~LinkedList();
    
    // Inserts node at the end of the linked list
    void insertAtEnd(char);
    
    // Inserts node at the front of the linked list
    void insertAtFront(char);
    
    // Displays/Prints the linked list
    void display();
    
    // Reverses the linked list
    LinkedList* reverse();
    
    // Checks if the linked list is a palindrome
    bool isPalindrome();
    
private:
    Node* m_head;
};

#endif /* LinkedList_h */
