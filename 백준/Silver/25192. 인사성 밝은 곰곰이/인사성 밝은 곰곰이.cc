#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>
#include <sstream>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

#define NONE -1
#define INF 198765432



string str;
bool flag = false;
int names[100] = {0,};
int N;
int main(){
    FAST
    cin >> N;
    int cnt = 0;
    map<string, bool> clients;
    int idx = 0;
    for(int i = 0 ; i < N; i++){
        cin >> str;
        if(str == "ENTER"){
            clients.clear();
        }
        else{
           if(clients.find(str) == clients.end()){
                clients.insert(make_pair(str, true));
                cnt++;
           }
           
            
            
            // cout << "check: \n";
            // for(int i = 0 ; i < idx; i++){
            //     cout << clients[i] << "\n";

            // }
            // cout << "done \n";
        }

    }
    cout << cnt;
}