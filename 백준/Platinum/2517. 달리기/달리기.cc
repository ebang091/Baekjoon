#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>


#define MAX 10000000
using namespace std;
int N;
long long tree[MAX];
long long rank_a[MAX];
int PIV;

vector <pair <int, int> > player;

long long query(long long start, long long end)
{
	start += PIV;
	end += PIV;
	long long sum = 0;
	while (start <= end)
	{
		if (start % 2 != 0)
			sum += tree[start++];
		if (end % 2 == 0)
			sum += tree[end--];
		start /= 2;
		end /= 2;
	}
	return sum;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

void update(long long idx, int value)
{
	idx += PIV;
	while (idx)
	{
		tree[idx] += value;
		idx /= 2;
	}
}
void input()
{
	long long cur;

	int ability;
	for (int i = 0; i < N; i++)
	{
		cin >> ability;
		player.push_back(make_pair(ability, i));//실력과 들어온 순서 쌍을 저장.
	}
	sort(player.begin(), player.end(), cmp); //선수들을 실력 순으로 나열

	for (int i = 0; i < N; i++)//실력 순서대로 선수들의 값을 저장하고 앞서있는 선수로 index tree에 등록 : index는 출발순서
	{
		cur = player[i].second;
		update(cur, 1);
		rank_a[cur] = query(0, cur);
		//	printf("%d player ability %d rank : %d\n", cur, player[i].first, rank_a[cur]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << rank_a[i] << "\n";
	}
}
int find_log(int N)
{
	int i = 1;
	int cnt = 0;
	while (i < N)
	{
		i *= 2;
		cnt++;
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	PIV = 1 << find_log(N);
	input();
}


