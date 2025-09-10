/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"
#include <cstddef> //solving the "NULL is not defined in this scope" error as instructed by the guide
using namespace std;

int main(int argc, char* argv[])
{
  //constructing the original linked list
  Node* myN = new Node(0,NULL);
  Node* myN1 = new Node(2,NULL);
  myN->next = myN1;
  Node* myN2 = new Node(3,NULL);
  myN1->next = myN2;
  Node* myN3 = new Node(11,NULL);
  myN2->next = myN3;

  //initial odd and even linked lists
  Node* myOdds = NULL;
  Node* myEvens = NULL;

  split(myN, myOdds, myEvens);

  Node* temp1=myOdds;
  Node* temp2=myEvens;

  if(myN==NULL){
    cout << "Original List Successful!" << endl;
  }
  
  bool status1 = true;
  bool status2 = true;

  while(temp1!=NULL){
    if(temp1->value%2==0){
      status1 = false;
      break;
    }
    temp1=temp1->next;
  }
  while(temp2!=NULL){
    if(temp2->value%2!=0){
      status2 = false;
      break;
    }
    temp2=temp2->next;
  }
  if (status1&&status2){
    cout << "Odd and Even Lists Successful!" << endl;
  }
}
