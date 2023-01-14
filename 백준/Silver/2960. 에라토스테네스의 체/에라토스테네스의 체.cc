#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>


#define MAX 1000000
using namespace std;
int N, K;
int nums[MAX] = { 0, };
int save;
void input()
{
	int cnt = 0;
	for (int i = 2; i <= N; i++)
	{
		
		for (int j = i; j <= N; j+=i)
		{
			if (nums[j] == 1)
				continue;
			nums[j] = 1;//소수가 아니라고 표시. 
			cnt++;
			if (cnt == K)
				cout << j;
			
		}
		
			
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	input();

}


