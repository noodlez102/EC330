#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
#include <fstream> 
#include "MaxProduct.h"
#include <bits/stdc++.h>
using namespace std;


long MaxProductClass::MaxProduct(string file) {
    vector<int> maxMultiples;
    ifstream MyReadFile(file);
    vector<int> lineMultiples;


    string line;
    int current_num;
    int current_multiple = 1;
    vector<int> linesNumbers;
    while (MyReadFile >> current_num) {
        if (current_num == -999999) {
            int linesSize = linesNumbers.size();
            if (linesSize <= 3) {
                for (int i : linesNumbers) {
                    current_multiple *= i;
                    lineMultiples.push_back(current_multiple);
                }
                
                current_multiple=1;
            } else {
                for (auto i = linesNumbers.begin(); i != linesNumbers.end(); ++i) {
                    if (i + 3 > linesNumbers.end()) {
                        for (auto j = linesNumbers.begin(); j != linesNumbers.end(); ++j) {
                            current_multiple *= (*j);
                            lineMultiples.push_back(current_multiple);
                            
                        }
                        
                        current_multiple=1;
                    } else {
                        for (auto k = i; k != i + 3; ++k) {
                            current_multiple *= (*k);
                            lineMultiples.push_back(current_multiple);
                        }
                        current_multiple=1;
                    }
                }
            }
            maxMultiples.push_back(*max_element(lineMultiples.begin(), lineMultiples.end()));
                // for (int lineMultiples : lineMultiples) {
                //     cout << lineMultiples << endl;
                // }
            lineMultiples.clear();
            linesNumbers.clear();
        } else {
            linesNumbers.push_back(current_num);
        }
    }

    MyReadFile.close(); 
    // cout<<"this is max multiple"<< endl;
    for (int maxMultiple : maxMultiples) {
        cout << maxMultiple << endl;
    }

    return *max_element(maxMultiples.begin(), maxMultiples.end());
}