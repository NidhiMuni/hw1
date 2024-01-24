/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
// added
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

  Node* odds = nullptr;
  Node* evens = nullptr;

  //TEST 1 - All numbers 1 thru 10
  /*Node* head = new Node(1, nullptr);
  Node* curr = head;
  for (int i = 2; i < 10; i++){
    curr->next = new Node(i, nullptr);
    curr = curr->next;
  }
  split(head, odds, evens);*/

  //TEST 2 - Even Numbers 1 - 10
  /*Node* head = new Node(2, nullptr);
  Node* curr = head;
  for (int i = 4; i < 10; i+=2){
    curr->next = new Node(i, nullptr);
    curr = curr->next;
  }
  split(head, odds, evens);*/

  //TEST 3 - edge case - NULL head
  /*Node* head = nullptr;
  Node* curr = head;
  split(head, odds, evens);*/

  //PRINT
  cout << "Odds->";
  curr = odds;
  if (curr != nullptr){
    while (curr->next != nullptr){
      cout << curr->value << "->";
      curr = curr->next;
    }
    cout << curr->value << endl;
  }

  cout << "Evens->";
  curr = evens;
  if (curr != nullptr){
    while (curr->next != nullptr){
      cout << curr->value << "->";
      curr = curr->next;
    }
    cout << curr->value << endl;
  }


}
