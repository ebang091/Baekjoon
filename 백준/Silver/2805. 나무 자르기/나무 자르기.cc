#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

#define PIV 1<<12
using namespace std;
int N, target;
int MAX;

vector <int> tree;

void input()
{
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (n > MAX)
			MAX = n;
		tree.push_back(n);
	}
}

long long cutted(int n)//높이 n으로 나무를 잘랐을 때 얼마나 자르는지 반환
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (tree[i] > n)
		{
			
			sum += tree[i] - n;
		}
	}
	return sum;
}

int find()
{
	sort(tree.begin(), tree.end());
	int low = 0;
	int high = MAX;
	int ans;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		
	
		if (cutted(mid) >= target)
		{
			ans = mid;
			low = mid + 1;
		
		}
		else
		{
			high = mid - 1;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> target;
	input();
	cout << find();
}


