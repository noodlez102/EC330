#include<iostream>
#include<math.h>
#include <stack>
using namespace std;


bool islegal(string s){
    stack<char> stacks;
    for(char c : s){
        if(c == '(' || c== '{' || c=='['){
            stacks.push(c);
        }else{
            if(stacks.empty() && c==')' || stacks.empty() && c=='}' ||stacks.empty() && c==']' ){ //the problem is here logic wise...
                return false;
            }
            else if(c ==')' && stacks.top() != '('){
                return false;
            }else if(c =='}' && stacks.top() != '{'){
                return false;
            }else if(c ==']' && stacks.top() != '['){
                return false;
            }else if(c ==')' && stacks.top() == '('|| c =='}' && stacks.top() == '{'||c ==']' && stacks.top() == '['){
                stacks.pop();
            }
            
            
        }
    }
    if(stacks.empty()){ //still not quite sure when nothing pops up
        return true;
    }else{
        return false;
    }

}

int main(int argc, char* argv[]){
    string mainArgument = argv[1];
    if(islegal(mainArgument)){
        cout<<"legal"<<endl;
    }else{
        cout<<"illegal"<<endl;
    }
    return 0;

}