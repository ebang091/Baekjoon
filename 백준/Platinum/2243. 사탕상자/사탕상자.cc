#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;
int N;
#define PIV (1<<20)

int tree[PIV * 2];

int query(int rank)
{
	long long idx = 1;
	while (idx < PIV)
	{
		idx *= 2;
		if (tree[idx] < rank)
		{
			rank -= tree[idx];
			idx++;
		}
	}
	return idx - PIV;
}

void update(long long idx, int value)
{
	idx += PIV;
	while (idx)
	{
		tree[idx] += value;
		idx /= 2;
	}
	return;
}

void input()
{
	long long a, b, c, ans;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 1)//꺼내기
		{
			cin >> b;
			ans = query(b);
			cout << ans << "\n";
			update(ans, -1);
		}
		else if (a == 2)
		{
			cin >> b >> c;
			update(b, c);
		//	printf("for check : %d\n", tree[b + PIV]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	input();
}