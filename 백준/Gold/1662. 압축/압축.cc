#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <cstring>
#include <sstream>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
#define all(v) v.begin(), v.end()
#define NONE -1
#define EMPTY ' '
#define INF 2147483647
using namespace std;

bool isOpenBracket(char c){
    return c == '(';
}

bool isClosingBracket(char c){
    return c == ')';
}
void printStack(stack<pair<char, int> > s){
    int size = s.size();
    cout << "stack info \n";
    for(int i = 0; i < size; i++){
        if(s.top().first == '(')
            cout << "( ";
        else 
            cout << s.top().second << " ";
        s.pop();
    }
    cout << "\n";
}
int main(){
    // FAST
    
    string str;
    cin >> str;
    stack<pair<char, int> > words;
    stack<long long > multiply;
    stack<long long > wordcount;


   for(int i = 0; i < str.length(); i++){
        char c = str[i];
    
        if(isOpenBracket(c)){
            char number = words.top().first;
            words.pop();

            words.push(make_pair(number , number - '0'));
            words.push(make_pair(c, 1));
            // printStack(words);
        }
        else if(isClosingBracket(c)){
            int count = 0;
            while(!words.empty() && !isOpenBracket(words.top().first)){
                count += words.top().second;
                words.pop();
            }
            if(words.empty())
                continue;
            words.pop();
            // cout << "count : " << count << "\n";
            count *= words.top().second;
            words.pop();
            words.push(make_pair(c, count));
        }
        else{
            words.push(make_pair(c, 1));
        }
   }


   int total  = 0;
   if(wordcount.size())
    total = wordcount.top();
   while(!words.empty())
   {   
        total += words.top().second;
        words.pop();
   }
    
    cout << total;
    
}