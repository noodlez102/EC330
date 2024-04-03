#ifndef HUFFMAN_H
#define HUFFMAN_H


#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
#include <fstream> 
#include <queue>
using namespace std;



class Node{
    public:
        char data;
        int frequency;
        string Huffmancode;
        Node *left, *right;
        Node(char datas, int freq);
};
class Larger{
    public:
    int operator() (Node* first, Node* second){
        if(first->frequency>second->frequency &&  first->frequency!=second->frequency){
            return true;
        }else if( first->frequency==second->frequency){
            if(first->data < second->data){
                return true;
            }
            return false;
        }else{
            return false;
        }
    }
};


class Huffman {
    private:
    vector<char> codedtxt; 
    Node* root;
    int sizes;
    priority_queue <Node*, vector<Node*>, Larger > daHeap;
    priority_queue <Node*, vector<Node*>, Larger > toHold;

    
    public:
        priority_queue <Node*, vector<Node*>, Larger >minheap(char[], int[], int);
        void buildHuffmanTree(char[], int[], int);
        void printCodes();
        void decodeText(const char* filename);
        void printCodesHelper(Node* current, string code);
};


#endif