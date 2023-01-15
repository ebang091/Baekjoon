#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

//첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.
using namespace std;
vector <int> nums;
#define MAX  4001
int N;
vector <int> A;
vector <int> B;
vector <int> C;
vector <int> D;
vector <long long> AB;
vector <long long> CD;

void make_array()
{
	long long ret = 0;
	long long  ans = 0;
	//AB의 합 저장, CD의 합 저장
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}
	//AB, CD 정렬 : 이진탐색을 위해
	//AB의 값에 대해 그 반대 부호의 값이 CD에 있는지 그 개수를 이진탐색 수행.   <- 중복되었을 떄 이진탐색?
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());
	

}

long long find_zero()
{
	make_array();
	long long low = 0, high = N * N - 1, ans = 0;
	long long tl, th;
	while(low < N*N && high >= 0)
	{
		if (AB[low] + CD[high] == 0)
		{
			tl = low;
			while (low < N*N && AB[tl] == AB[low])
				low++;
			th = high;
			while (high >= 0 && CD[th] == CD[high])
				high--;
			ans += (low - tl) * (th - high);
		}
		else if (AB[low] + CD[high] > 0)
			high--;
		else
			low++;
	}
	return ans;
}

void input() {
	int a, b, c, d;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
}

int main()
{
	cin >> N;
	input();
	cout << find_zero() << "\n";
}

