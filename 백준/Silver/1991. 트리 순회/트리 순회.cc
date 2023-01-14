#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

#define MAX 1<<20
using namespace std;
int N;
int position[27];
char tree[MAX];



char get(char c)
{
	if (c == '.')
		return 0;
	return c;
}

long long getIdx(char c)
{
	if (get(c) == 0)
		return 0;
	else
		return c - 'A' + 1;
}
long long findIdx(char a)
{
	return position[getIdx(a)];
}


void input()
{
	char a, b, c;
	long long idx;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		if (i == 0)
		{
			tree[1] = a;
			tree[2] = get(b);
			position[getIdx(b)] = 2;
			//printf("get idx : %c %d", b, getIdx(b));
			tree[3] = get(c);
			position[getIdx(c)] = 3;
			continue;
		}
		idx = findIdx(a);
		tree[idx * 2] = get(b);
		position[getIdx(b)] = idx * 2;
		tree[idx * 2 + 1] = get(c);
		position[getIdx(c)] = idx * 2 + 1;
	}
}

void preSearch(int root)
{
	if (tree[root] == 0)
		return;
	cout << tree[root];
	preSearch(root * 2);
	preSearch(root * 2 + 1);
}

void midSearch(int root)
{
	if (tree[root] == 0)
		return;
	midSearch(root * 2);
	cout << tree[root];
	midSearch(root * 2 + 1);
}

void postSearch(int root)
{
	if (tree[root] == 0)
		return;
	postSearch(root * 2);
	postSearch(root * 2 + 1);
	cout << tree[root];
}

int main()
{
	cin >> N;
	input();
	
	preSearch(1);
	cout << "\n";
	midSearch(1);
	cout << "\n";
	postSearch(1);
	cout << "\n";


}