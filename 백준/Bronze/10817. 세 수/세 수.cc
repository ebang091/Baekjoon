#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int nums[3];
    for(int i = 0; i < 3; i++){
        cin >> nums[i];
    }
    sort(&nums[0], &nums[3]);
    cout << nums[1];
}