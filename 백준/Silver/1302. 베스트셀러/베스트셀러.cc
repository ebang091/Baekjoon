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

map<string, int> books;
int N;
/*
가장 많이 팔린 책의 제목을 출력하는 프로그램을 작성하시오.

*/

int main(){
    // FAST
    cin >> N;
    string title;
    for (int i = 0 ; i < N ;i++){
        cin >> title;
        if(books.find(title) == books.end())
            books.insert(make_pair(title, 1));
        else books[title]++;
    }
    map<string, int>::iterator it;
    int max = -1;
    string maxNumberTitle = "zzzzzzzzzzzz";
    for(it = books.begin(); it != books.end(); it++){
        string title = (*it).first;
        int number = (*it).second;
        // cout << "num " << number << " title "  << title << "\n";
        if(number > max){
            // cout << "update!\n";
            maxNumberTitle = title;
            max = number;
        }
        else if(number == max){
            // cout <<"same!\n";
            maxNumberTitle = (title.compare(maxNumberTitle) < 0) ? title : maxNumberTitle;
        }
    }
    cout << maxNumberTitle;

    
}