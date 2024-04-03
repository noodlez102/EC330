//
//  main.cpp
//  Linked_List
//
//  Copyright © Tali Moreshet. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <vector>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {

  /* Uncomment */
  LinkedList<int> *myLL = new LinkedList<int>(INT_MIN, INT_MAX);
  Node<int> *newNodeLoc;
  
  newNodeLoc = myLL->search(myLL->head, 3);
  myLL->insert(newNodeLoc, 3);
  newNodeLoc = myLL->search(myLL->head, 1);
  myLL->insert(newNodeLoc, 1);
  newNodeLoc = myLL->search(myLL->head, 2);
  myLL->insert(newNodeLoc, 2);

  LinkedList<int> *myLL2 = new LinkedList<int>(INT_MIN, INT_MAX);
  
  newNodeLoc = myLL2->search(myLL2->head, 4);
  myLL2->insert(newNodeLoc, 4);
  newNodeLoc = myLL2->search(myLL2->head, 6);
  myLL2->insert(newNodeLoc, 6);
  newNodeLoc = myLL2->search(myLL2->head, 9);
  myLL2->insert(newNodeLoc, 9);

  vector<LinkedList<int> *> vectorOfLinkedLists;

  vectorOfLinkedLists.push_back(myLL);
  vectorOfLinkedLists.push_back(myLL2);

  for (int i = 0; i < 5; i++) {
    LinkedList<int> *myLL3 = new LinkedList<int>(INT_MIN, INT_MAX);
    vectorOfLinkedLists.push_back(myLL3);
  }

  for (int i = 0; i < 5; i++) {
    vectorOfLinkedLists[i]->printData();
  }


  cout << "Linked list data: \n";
  cout<<newNodeLoc->prev->data<<endl;
    cout << "Linked list data: \n";

  myLL->printData();

  // cout << "\n Linked List entire content: \n";
  // myLL->print();
  // delete myLL;
  
    
  return 0;
}
