
//1- Pseudocode of your function. Can be added as a comment in your source code file.
//1- Your program source code files (e.g., .cpp extension file).
//2- Screenshots of your test program output (.png or jpeg file)
//3- (optionally) you can include the executable file (e.g., .exe file)//
//  main.cpp
//  Project 1 - CS 136
//
//  Created by Taylor Spencer on 2/19/26.
//

#include <iostream>
using namespace std;

//define node
struct Node {
    
    int data;
    Node* link;
    Node(int val) : data(val), link(nullptr) {}
};


void reverse(Node* &head) {
    
    //declare 3 pointer variables for prev, current, next nodes
    Node *prev, *curr, *next;
    prev = nullptr;
    curr = head;
    next = nullptr;
    
    while (curr != nullptr){
        
        next = curr->link; //set next to the next node
        curr->link = prev; //set the first node link to p
        prev = curr; //increment first node to current
        curr=next;   //increment current value
    }
    //set head to prev when the list is finish traversing
    head = prev;
}

void printList(Node* head) {
    while (head!= nullptr) {
        cout << head->data << " ->";
        head = head->link;
    }
    cout << "null" << endl;
}

int main() {
    
    Node* head = new Node(1);
    head->link = new Node(2);
    head->link->link= new Node(3);
    head->link->link->link = new Node(4);
    head->link->link->link->link = new Node(5);
    
    cout << "original linked list: ";
    printList(head);
    
    reverse(head);
    
    cout << "Reversed: ";
    printList(head);
    
  return 0;
}

