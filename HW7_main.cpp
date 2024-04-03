//
//  main.cpp
//  Huffman
//
//  Created by Tali Moreshet
//

#include <iostream>
#include <fstream>
#include "Huffman.h"

using namespace std;

int main(int argc, const char * argv[]) {
    char characters[] = {'t', 'o', 'u', 'a', 'i', 's', 'e'};
	int freq[] = 		{ 1 ,  3 ,  4 , 10 , 12 , 13 , 15 };
    int size = sizeof(characters) / sizeof(characters[0]);
    
    Huffman huffman;
    
    huffman.buildHuffmanTree(characters, freq, size);
    huffman.printCodes();
    
    if (argc != 2)
        cout << "Please supply a file name with Huffman encoded text\n";
        
    huffman.decodeText(argv[1]);
    
    return 0;
}
