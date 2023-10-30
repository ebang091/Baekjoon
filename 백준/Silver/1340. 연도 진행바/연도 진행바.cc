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
string months[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string str, answer;
vector<string> strings;
/*
올해가 얼마나 지났나.
*/

bool isYoon(int year){
    if(year % 400 == 0)
        return true;
    else if(year % 100 == 0)
        return false;
    else if(year% 4 == 0)
        return true;
    return false;
}

int Feburaryday(int year){
    if(isYoon(year))
        return 29;
    return 28;
}

int main(){
    FAST
    string month;
    string time;
    char delimeter;
    int day, year;
    double hour, minute;

    cin >> month >> day >> delimeter >> year;
    cin >> time;
    // cout << "time : " << time << "\n";
    char *ptr;
    hour = strtod(time.substr(0,2).c_str(), &ptr);
    minute = strtod(time.substr(3,2).c_str(), &ptr);
    // cout << month << " " << day << " " << year << " " << hour << " " << minute << "\n";
    
    double seconds;
    if(isYoon(year))
        seconds = 366 * 24 * 60;
    else
        seconds = 365 * 24 * 60;
    
    
    double todaySeconds = 0;
    for(int i = 1; i <= 12; i++){
        if(months[i] == month){
            break;
        }
        if(i == 2)
            todaySeconds += Feburaryday(year) * 24 * 60;
        else
            todaySeconds += days[i] * 24 * 60;
    }
    todaySeconds += ((day - 1)* 24 * 60 + hour * 60 + minute);
    cout.precision(20);
    double ans = ((double)todaySeconds/(double)seconds) * 100;

    // if((int)(ans * 100)% 10 == 0)
        // cout << (int)ans << ".0";
    // else 
        cout << ans;
    

}