#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>


#define MAX 5000001
using namespace std;
int N, H;

int g[MAX]; // 높이(==인덱스)에 따라 만나는 석순 수 ground
int c[MAX]; // 높이(==인덱스)에 따라 만나는 종유석 수 ceiling
int crush[MAX];
int tmin = 2147483647, save = 0;

void input()
{
	int h;
	for (int i = 0; i < N; i++)//애초에 높이의 경계선에 1을 더하는데 종유석의 경우는  H-h+1이다. 
	{
		cin >> h;
		if (i % 2 == 0)//석순일때 h = 1 -> 1 
			g[h]++;
		else
			c[H-h+1]++;
	}
}

void calculate()
{

	//석순의 경우 위에서부터 누적합을 실시하고, 종유석의 경우 아래에서부터(작은 인덱스부타) 누적합을 실시한다. 
	for (int i = H-1; i >= 1; i--)
		g[i] += g[i + 1];

	for (int i = 1; i <= H-1; i++)
		c[i + 1] += c[i];

	for (int i = 1; i <= H; i++)
	{
		crush[i] = c[i] + g[i];
		//printf("%dheight - %d\n",i, crush[i]);
		if (tmin > crush[i])
			tmin = crush[i];
	}
	for (int i = 1; i <= H; i++)
	{
		if (crush[i] == tmin)
			save++;
	}
}

void find(int n)
{
	int a = lower_bound(crush +1, crush + H, tmin) - (crush + 1);
	int b = upper_bound(crush +1, crush + H, tmin) - (crush + 1) -1;
	save = b - a + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> H;
	input();
	calculate();
	sort(&crush[1], &crush[H]);
	//find(tmin);//부수는 횟수 최솟값의 구간 수를 찾아서 저장:  crush배열에서 탐색
	cout << tmin << " " << save;
	


}


