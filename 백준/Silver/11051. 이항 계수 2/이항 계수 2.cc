#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>


#define MAX 1005
using namespace std;
int N, K;
int nums[MAX][MAX] = { 0, };
int save;

void calculate()
{
	for (int i = 0; i <= N; i++)
	{
		for (int j= 0; j <= i; j++)
		{
			if (j == 0)
				nums[i][j] = 1;
			else
				nums[i][j] = (nums[i - 1][j - 1] + nums[i - 1][j])%10007;

		}
	}
}


void printarray()
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; nums[i][j] != 0; j++)
			printf("%d ", nums[i][j]);
		printf("\n");
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	//nCk 의 계산 : 이항분포를 그린 뒤 해당 배열 [n][k] 를 리턴한다. 
	calculate();

	cout << nums[N][K];

}


