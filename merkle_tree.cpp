/*
Implementation of the merkle tree and node classes and helper function to read from an inputed file.
*/

#include "merkle_tree.h"

#include <cstdint>

using namespace std;

//the reading ints from a file function

vector<int> readIntsFromFile(const string& filename){
    vector<int> data;
    ifstream input_stream(filename);
    int current;

    while(input_stream>>current){
        data.push_back(current);
    }

    return data;
}

/* Hash function*/
inline string fnv1a(string const & text) {
    // 64 bit params
    uint64_t constexpr fnv_prime = 1099511628211ULL;
    uint64_t constexpr fnv_offset_basis = 14695981039346656037ULL;
    
    uint64_t hash = fnv_offset_basis;
    
    for(auto c: text) {
        hash ^= c;
        hash *= fnv_prime;
    }

    return to_string(hash);
}

/* Merkle Tree method for computing the hash of the concatenated hashes of children nodes 
   Using the provided hash function, concatenates child hashes from left to right and returns the hash 
   of the concatenation */
string merkleTree::concatenateHash(const vector<Node*>& nodes){
    string merged;
    //concatenate hashes of all inputed nodes 
    for(const Node* node: nodes){
        merged += node->key;
    }

    //take hash of concatenated nodes
    string mergedHash = fnv1a(merged);

    return mergedHash;
}

Node* merkleTree::getRoot(){
    return root;
}
Node::Node(const string& val){                             
    key = val;
    vector<Node *> empty;
    this->children = empty;
}       
merkleTree::merkleTree(){
    vector<int> empty;
    root = nullptr;
    this->data=empty;
}


merkleTree::merkleTree(const vector<int>& data){
    vector<Node *> allHashed;
    this->data = data;
    int size = data.size();
    for(int i=0; i<size;i++){   //the level where it's all hashes of the data
        string currentHash = fnv1a(to_string(data[i]));
        Node* temp = new Node(currentHash);
        allHashed.push_back(temp);
    }
    
    vector<Node *> currentLevel=allHashed;
    int currentLevelSize=currentLevel.size();
    int numberofChilds=1;
    vector<Node *> empty;
    /*the logic is looping until we reach the root/ so that the top layer has only one node, and for every 4 nodes we concat them
    using the function given and set those 4 nodes as the children of the new concat node. or if it reaches the end of that layer*/
    while(currentLevelSize>1){
        vector<Node *> nextLevel;
        vector<Node *> concatNodes;
        for(int i =0; i<currentLevelSize;i++){
            if (numberofChilds==4||i==currentLevelSize-1)
            {
                concatNodes.push_back(currentLevel[i]);
                numberofChilds=1;
                string newHash = concatenateHash(concatNodes);
                Node * temp = new Node(newHash);
                temp->children = concatNodes;
                nextLevel.push_back(temp);
                concatNodes = empty;
            }else{
            concatNodes.push_back(currentLevel[i]);
            numberofChilds++;
            }
        }
        currentLevel=nextLevel;
        currentLevelSize = currentLevel.size();
    }
    root = currentLevel[0];

}

void merkleTree::printTree(const Node* node, int depth) {      //prints tree
    cout << "Level " << depth << ":" << " " << root->key << endl;
    vector<const Node *> topLayer;
    vector<const Node *> nextLayer;
    bool done = false;
    topLayer.push_back(node);
    for(const Node* temps:node->children){
        nextLayer.push_back(temps);
    }
    while(done==false){
        depth++;
        vector<const Node *> tempNextLayer;
        for(int i =0; i<topLayer.size();i++){
            for(const Node* current:topLayer[i]->children){
                cout << "Level " << depth << ":" << " " << current->key << endl;
                for(const Node* temps: current->children){
                    tempNextLayer.push_back(temps);
                }
            }
        }
        topLayer=nextLayer;
        nextLayer=tempNextLayer;
        if(nextLayer.size() ==0){
            done = true;
        }
    }
}

//checks if the current root matches a rebuilt root using the data to see if it's been tamered with. 
void merkleTree::verify() {
    merkleTree temp(data);  
    if ((root->key) != (temp.getRoot()->key)) {    
        cout << "False" << endl;
    }
    else {
        cout << "True" << endl;
    }
}               

void merkleTree::overwrite(int originalValue, int newValue) {   
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == originalValue) {
            data[i] = newValue;
        }
    }
    merkleTree tempTree(data);
    root = tempTree.getRoot();
}      

//insert function. just adds a data point and recomputes
void merkleTree::insert(int newValue) { 
    data.push_back(newValue);
    merkleTree anotherTree(data);
    root = anotherTree.getRoot();
}

void merkleTree::printRoot() {//print root of tree
    cout << root->key << endl;
}
