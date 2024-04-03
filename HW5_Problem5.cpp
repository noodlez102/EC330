#include <iostream>
#include <fstream>
#include "Problem5.h"

using namespace std;


int fiveA() {
    ifstream myFile("BigData.txt");
    char readVal;
    int numSum = 0;
    int numNums = 0;
    int finalCount = 0;
    bool inId = false;
    if (myFile.is_open()) {
        while (myFile >> readVal) {
            if((readVal<=48 || readVal>=57) && numNums==8 && inId && numSum>=28){ // if it is a valid BU ID add to final count
                finalCount++;
                numSum =0;
                numNums =0;
                inId=false; //we can set this to false because even if it is a U for the end the nxt if statment will catch it
            }
            if((readVal<=48 || readVal>=57) && numNums==8 && inId && numSum<28){ // if it is a valid BU ID but not above 28 reset
                numSum =0;
                numNums =0;
                inId=false; //we can set this to false because even if it is a U for the end the nxt if statment will catch it
            }
            if(readVal == 85 ){ //checks if it starts with a U and if it is set everything to 0 again
                numSum=0;
                numNums=0;
                inId= true;
                continue;
            }
            if(readVal>=48 && readVal<=57 && numNums<8 && inId){ //checks if it is an number, and if it is in id, where we add the value and increment the number of numbers
                numSum+=(int)readVal;
                numNums++;
                continue;
            }
            if(readVal<=48 || readVal>=57 || numNums!=8 && inId && numNums!=0){ //checks if it's not a number, and not a U, but still in an ID
                numSum=0;
                numNums=0;
                inId =false;
                continue;
            }
        }
    }
    myFile.close();
    return finalCount;
}

int fiveB() {return 0;}

int fiveC() {

    ifstream myFile("BigData.txt");   
    string theData;
    getline(myFile,theData);   
    int n = theData.size();
    int left, right;
    int maxLength = 1;
    for (int i = 0; i < n; i++) {      
        left = i;
        right = i+1;
        while ((left >= 0) && (right < n) && (theData[left] == theData[right])) {//as long as it fits within the bounds and is a palidrone
            if ((right - left + 1) > maxLength) {  
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
        left = i - 1;
        right = i + 1;
        while ((left >= 0) && (right < n) && (theData[left] == theData[right])) {  //same but this time there's a pivot point
            if ((right - left + 1) > maxLength) {  
                maxLength = right - left + 1;
            }
            left--;  
            right++;
        }
     }
    myFile.close();
    return maxLength;
}
