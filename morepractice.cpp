#include<iostream>
#include<math.h>
#include <stack>
using namespace std;


bool islegal(string s){
    int strlength = s.length();
    int halfway;
    bool TrueorFalse=true;
    int index2=0;
    
}

int main(){
    string s;
    cout<<"type in string input:";
    cin>>s;
    if(islegal(s)){
        cout<<"legal"<<endl;
    }else{
        cout<<"illegal"<<endl;
    }
    return 0;

}