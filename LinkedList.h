//
//  LinkedList.h
//  Linked_List
//
//  Copyright © Tali Moreshet. All rights reserved.
//
//  This is an implementation of an ordered Linked List class, which is made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <cstdlib>
#include <time.h>

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
};

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

/*** TO BE COMPLETED ***/

//constructor
template <class T>
LinkedList<T>::LinkedList(T minVal, T maxVal)
{
    head = new Node<T>(minVal);
    Node<T>* HighBound = new Node<T>(maxVal);
    head->next=HighBound;
    HighBound->prev=head;
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

#endif /* LinkedList_h */
