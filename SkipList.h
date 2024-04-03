//
//  SkipList.h
//  Skip_List
//
//  Copyright © Tali Moreshet. All rights reserved.
//
//
//  This is an implementation of a Skip List class, consisting of Linked Lists, which are made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef SkipList_h
#define SkipList_h

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <vector>

using namespace std;

template<class T>
class Node {
public:
    Node(const T& data);                            // constructor
    T data;                                         // node data, doubles as key
    Node<T> *next;                                  // node next pointer
    Node<T> *prev;                                  // node previous pointer
    Node<T> *up;                                    // node above pointer
    Node<T> *down;                                  // node below pointer
    void printData();                               // prints data value
    void print();                                   // prints entire node object content
};

template <class T>
class LinkedList {
public:
    LinkedList(T minVal, T maxVal);                 // constructor: accepts -infinity, +infinity values,
                                                    //  creates linked list with two corresponding nodes
    ~LinkedList();                                  // destructor
    Node<T>* search(Node<T>* location, T data);     // search for data starting at location, return node <= data
    Node<T>* insert(Node<T>* location, T data);     // insert node with data at new node to be placed directly 
                                                    //  after node with povided location, return new node
    void printData();                               // prints linked list data
    void print();                                   // prints linked list with all nodes pointers
    Node<T>* head;                                  // head of list
    Node<T>* tail;                                  // tail of the list

};

template <class T>
class SkipList {
public:
    SkipList(T minVal, T maxVal);                   // constructor: accepts -infinity, +infinity values,
                                                    //  creates skip list with top-level only
    ~SkipList();                                    // destructor
    Node<T>* search(T data);                        // search for data, return node <= data (existing node, or location
                                                    //  where new node should be inserted in the bottom-most list)
    Node<T>* insert(T data);                            // insert node with data, return pointer if inserted, NULL if error
    void printData();                               // prints skip list data
    void print();                                   // prints skip list with all nodes pointers
    LinkedList<T> *topList;                         // pointer to the top-most list
    LinkedList<T> *bottom;                         // pointer to the top-most list
    int randSeed = 330;                             // to be used as seed for the getRand() function
    vector<LinkedList<T> *> vectorOfLinkedLists;  //a vector of linkedlists

};

//returns 0 or 1 with a 50% chance 
//When it returns 1, insert the node to next level of the skiplist
int getRand(){
    return rand()%2;
}

/********************** From here down is the content of the LinkedList.cpp file: ***********************/

/****** Implementation of Node ******/

// Constructor
template<class T>
Node<T>::Node(const T& data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

// Print node's data value
template <class T>
void Node<T>::printData()
{
    cout << data << " ";
}

// Print entire node object content (data value, object's address, and all pointers)
template <class T>
void Node<T>::print()
{
    cout << " * " << data << ": [addr: " << this << " next: " << this->next << " prev: " << this->prev << " up: " << this->up << " down: " << this->down << "]  ";
}


/****** Implementation of linked list ******/

template <class T>
LinkedList<T>::LinkedList(T minVal, T maxVal)
{
    head = new Node<T>(minVal);
    tail = new Node<T>(maxVal);
    head->next=tail;
    tail->prev=head;
}

//the destructor
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* current = this->head;
    while (current != NULL) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

//the search function that takes in location and
template <class T>
Node<T>* LinkedList<T>::search(Node<T>* location, T data){
    Node<T>* current = location;
    Node<T>* temp = current->next;
        for(current = location; current != NULL; current= current->next){
            if((current->data < data && temp->data > data) ||(current->data < data && temp->data < data)){
                temp=temp->next;
            }else{
                return current;
            }
            
        }
    return current;//this is to get rid of the warning
}




//inserts the new node and makes sure everything is pointing to where it needs to be pointing at
template <class T>
Node<T>* LinkedList<T>::insert(Node<T>* location, T data){
    Node<T>* insert_Loc = new Node<T>(data);
    Node<T>* before_Insert = location->prev;
    Node<T>* front_Insert = location;

    if(data < location->data){
        insert_Loc->next = front_Insert;
        insert_Loc->prev = before_Insert;
        before_Insert->next=insert_Loc;
        front_Insert->prev = insert_Loc;
        return insert_Loc;
    }else{
        return NULL;
    }

}

template <class T>
void LinkedList<T>::printData()
{
    Node<T>* current =this-> head;
    for(current =this->head; current != NULL; current= current->next){
        current->printData();
    }
    cout<<endl;
    
}

template <class T>
void LinkedList<T>::print()
{
    Node<T>* current = this->head;
    for(current =this->head; current != NULL; current= current->next){
        current->print();
    }
    cout<<endl;

}



/****** Skip List Implementation ******/

template <class T>
SkipList<T>::SkipList(T minVal, T maxVal)
{
    srand(this->randSeed);

    bottom = new LinkedList<T>(minVal, maxVal);
    topList = new LinkedList<T>(minVal, maxVal);
    bottom->head->up= topList->head;
    topList->head->down= bottom->head;
    bottom->tail->up= topList->tail;
    topList->tail->down= bottom->tail;
    vectorOfLinkedLists.push_back(bottom);
    vectorOfLinkedLists.push_back(topList);
}

template <class T>
SkipList<T>::~SkipList()
{
  for (int i = vectorOfLinkedLists.size()-1; i >=0 ; i--) {
    delete vectorOfLinkedLists[i];
  }

}


template <class T>
Node<T>* SkipList<T>::search(T data){
    Node<int> *newNodeLoc;
    newNodeLoc = bottom->search(bottom->head, data);
    return newNodeLoc;
}


template <class T>
Node<T>* SkipList<T>::insert(T data){
    Node<T>* location = bottom->search(bottom->head, data);
    Node<T>* newLoc = bottom->search(bottom->head, data);
    vectorOfLinkedLists.pop_back();
    int currentlevel=0;
    if(location->data == data){
        vectorOfLinkedLists.push_back(topList);
        return NULL;
    }else{
        bottom->insert(location, data);
        while(getRand()){ 
   
            if(currentlevel + 1 >= vectorOfLinkedLists.size()){
                LinkedList<T> *myLL = new LinkedList<T>(bottom->head->data, bottom->tail->data);
                vectorOfLinkedLists.push_back(myLL);

                //this code connects the new list ends to the list below it
                vectorOfLinkedLists[currentlevel]->head->up= vectorOfLinkedLists[currentlevel+1]->head;
                vectorOfLinkedLists[currentlevel]->tail->up= vectorOfLinkedLists[currentlevel+1]->tail;
                vectorOfLinkedLists[currentlevel+1]->head->down= vectorOfLinkedLists[currentlevel]->head;
                vectorOfLinkedLists[currentlevel+1]->tail->down= vectorOfLinkedLists[currentlevel]->tail;
                
                //this connects the new list ends to the list above it
                vectorOfLinkedLists[currentlevel+1]->head->up= topList->head;
                vectorOfLinkedLists[currentlevel+1]->tail->up= topList->tail;
                topList->head->down= vectorOfLinkedLists[currentlevel+1]->head;
                topList->tail->down= vectorOfLinkedLists[currentlevel+1]->tail;

            }               
             //uses location of the previous node then finds new location and uses those to connect the nodes together
            location = vectorOfLinkedLists[currentlevel]->search(vectorOfLinkedLists[currentlevel]->head, data);
            currentlevel++;
            newLoc= vectorOfLinkedLists[currentlevel]->search(vectorOfLinkedLists[currentlevel]->head, data);
            vectorOfLinkedLists[currentlevel]->insert(newLoc, data);
            location->up=newLoc;
            newLoc->down=location;
        }
        vectorOfLinkedLists.push_back(topList);
        return newLoc;
    }
    cout<<endl;
}

template <class T>
void SkipList<T>::printData()
{
  for (int i = vectorOfLinkedLists.size()-1; i >=0 ; i--) {
    vectorOfLinkedLists[i]->printData();
  }
    
}

template <class T>
void SkipList<T>::print()
{
  for (int i = vectorOfLinkedLists.size()-1; i >=0 ; i--) {
    vectorOfLinkedLists[i]->print();
  }

}





#endif /* SkipList_h */
