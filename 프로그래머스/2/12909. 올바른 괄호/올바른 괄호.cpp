#include<string>
#include <iostream>
#include <stack>


using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> bracket;
    for(int i = 0; i < s.length(); i++){
        
        char value = s[i];
        if(value == '(')
            bracket.push(s[i]);
        
        else if(value == ')'){
            if(bracket.empty() == true)
                return false;
            else if(bracket.top() == '('){
                bracket.pop();
                continue;
            }
        }
        
            
            
    }
    
    if(bracket.empty() == false){
        return false;
    }

    return true;
}