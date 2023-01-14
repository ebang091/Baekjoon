#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>


#define MAX 10000000
using namespace std;
int N;
vector <int> v;
long long ansA = -1, ansB; //최대 공약수, 그 때의 뺀 수
vector <int> leftside;
vector <int> rightside(MAX);


void input()
{
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		v.push_back(n);
	}
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

void find()
{
	int a, b ,ans, tmin, tmax, flag;
	for (int i = 0; i < N; i++)//i가 곧 빼려는 값의 인덱스
	{
		flag = 0;
		//왼쪽에서 구하고
		if (i > 0)
			a = leftside[i-1];
		else
		{
			ans = rightside[1];
			flag = 1;
		}//어차피 제일 왼쪽 빼면 답자체가 right에서 처음에서 1칸 뒤
		//오른쪽에서 구하고
		if(flag != 1)
		{
			if (i < N - 1)
			b = rightside[i + 1];
		
			else
			{
				ans = leftside[N - 2];
				flag = 1;
			}//어차피 제일 오른쪽빼면 답자체가 left에서 맨 뒤에서 한칸 앞
		}
		
		
		if (!flag)
		{
			tmax = a > b ? a : b;
			tmin = a < b ? a : b;
			ans = gcd(tmax, tmin);
		}
		//printf("except %d - gcd %d\n", v[i], ans);
		if (v[i] % ans == 0)
			continue;
		else if(ans > ansA)
		{
			ansA = ans;
			ansB = v[i];
		}
	}
}

void save_gcd()
{
	int GCD;
	//gcd의 값을 누적해서 vector에 저장한다. 
	//왼쪽에서 오른쪽 방향으로 가면서 누적한다. 
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			GCD = v[i];
		else
			GCD = gcd(leftside[i - 1], v[i]);
				leftside.push_back(GCD);
	}
	//오른쪽에서 왼쪽 방향
	for (int i = N - 1; i >= 0; i--)
	{
		if (i == N - 1)
			GCD = v[i];
		else
			GCD = gcd(rightside[i+1], v[i]);
		rightside[i] = GCD;
	}
//	for (int i = 0; i < N; i++)
	//	printf("%d ", leftside[i]);
//	cout << "\n";
//	for (int i = 0; i < N; i++)
//		printf("%d ", rightside[i]);
//	printf("--------------------------------\n");

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	input();
	sort(v.begin(), v.end());
	save_gcd();
	find();
	if (ansA != -1)
	{
		cout << ansA << " ";
		cout << ansB;
	}
	else
		cout << "-1";



}


