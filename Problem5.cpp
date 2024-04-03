#include<iostream>
#include<math.h>
#include <stack>
#include <string>

using namespace std;


//if the n is an odd number, then the Os are off the x's by 1and there will be 2 Os with one o with one space between the top O,
//the x's will always be up and to the right by 1 compared to the last iteration. if n is an even number, o touches x and isonly 1 O
//basically n%2 determines the space between os and xs. 


int drawsquare(int value){
    char graph[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
           graph[i][j]='-'; 
        }

    }

    // for the x's in the grid
    int y=9;
    for(int x=0; x<=value;x++){
        graph[y][x]='x';
        y--;
        graph[y][x]='x';
    }



    //for the Os in the grid.
    int Ox= 1+ value+value%2;

    if(value%2){
        y--;
        graph[y][Ox]='o';
        y++;
        y++;
        graph[y][Ox]='o';
    }else{
        graph[y][Ox]='o';

    }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
           cout<<graph[i][j];

        }
        cout<<endl;

    }
    return 0;
    
}

int main(int argc, char* argv[]){
    int mainArgument =stoi(argv[1]);
    drawsquare(mainArgument);
    return 0;
}