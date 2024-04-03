
#include "Huffman.h"
Node::Node(char datas, int freq){
    this->left=this->right=NULL;
    this->data = datas;
    this->frequency=freq;
}
priority_queue<Node*, vector<Node*>, Larger > Huffman::minheap(char data[], int freq[], int size){

    for (int i = 0; i < size; ++i){
        Node* current = new Node(data[i],freq[i]);
        daHeap.push(current);
    }
    return daHeap;
}

// Function to build a Huffman tree from the given arrays
void Huffman::buildHuffmanTree(char data[], int freq[], int size) {
    Node *left, *right, *top;
    int i=0;
    this->sizes=size;
    
    minheap(data,freq,size);
    toHold=daHeap;

    while (daHeap.size() > 1) {
        Node* left = daHeap.top();
        daHeap.pop();

        Node* right = daHeap.top();
        daHeap.pop();

        Node* top = new Node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        daHeap.push(top);
    }
    root = daHeap.top();
}

// Function to print the Huffman codes from the tree
void Huffman::printCodes() {
    Node* current = root;
    string code = "";
    while(current->left != NULL){
        if(current->right->left == NULL){
            current->right->Huffmancode = code+"0";
            cout <<current->right->data<<" "<<current->right->Huffmancode<<endl;
            current->left->Huffmancode = code+"1";
            cout <<current->left->data<<" "<<current->left->Huffmancode<<endl;
            current = current->right;

        }else{
            current->left->Huffmancode = code +"0";
            cout <<current->left->data<<" "<<current->left->Huffmancode<<endl;
            current = current->right;
            code = code+"1";
        }
        
    }
    cout<<endl;
    
}

void Huffman::decodeText(const char* filename){
    ifstream input_stream(filename);
    char current;
    string total;
    priority_queue <Node*, vector<Node*>, Larger > loop=toHold;

    
    while(input_stream>>current){
        total = total+current;
        if(current == '0' || total.length()==sizes-1){
            while(loop.empty() == false){
                Node* cur = loop.top();
                loop.pop();
                if(cur->Huffmancode == total){
                    cout<<cur->data;
                }
            }
            total = "";
            loop = toHold;

        }        
    }
    input_stream.close();
}