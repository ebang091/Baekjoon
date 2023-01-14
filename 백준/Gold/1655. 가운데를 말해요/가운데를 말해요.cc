#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;
int N;
vector <int> v;
priority_queue <int> minheap;
priority_queue <int> maxheap;
#define MIN 1
#define MAX 2
/*

수열을 두 개의 힙에 저장하되,
작은 값들은 최대힙에 저장하고 큰 값들은 최소힙에 저장한다.

새로운 값을 넣을 때, 두개의 힙에서 pop한 값을 비교해서 저장하고,
개수가 2개 이상 차이날 때는 pop해서 두개를 바꿔서 넣어준다.

작은 값들이 저장되어있는 최대힙에서 pop해서 출력한다.


maxheap은 최소힙이므로 음수 처리해서 저장하고 꺼내도 부호를 바꾸어주어야한다!

*/

void ft_swap(int flag)
{
	int data;
	if(flag == MIN)
	{
		data = minheap.top();
		minheap.pop();
		maxheap.push(-data);
		//printf("swap min to max\n");
	}
	else
	{
		data = -maxheap.top();
		maxheap.pop();
		minheap.push(data);
		//printf("swap max to min\n");
	}
}

void check_size(int flag)
{
	if (minheap.size() < maxheap.size() || minheap.size () > maxheap.size() + 1)
		ft_swap(flag);
	else
		return;
}

void push_heap(int n)
{
	//1. heap 사이즈 확인: 두번째 저장해서 min에만 들어있는 경우 대소 비교 후 힙에 저장.
	//2. maxheap 의 최소값과 min힙의 최댓값과 n을 비교해서 삽입.
	//3. 힙의 개수를 비교한 후 바꿔서 저장.

	//printf("max heap size :%d", maxheap.size());
	if (maxheap.size() == 0)
	{
		if (minheap.top() > n) //min 에 들어있는 수보다 더 작은 수가 들어온 경우 자리를 바꾼다.
		{
			int data = minheap.top();
			minheap.pop();
			maxheap.push(-data);
			minheap.push(n);
			//printf("push max %d\n", n);
			return;
		}
		else
			maxheap.push(-n);
		return;
	}
	int min = -maxheap.top();
	if (n >= min)
	{
		maxheap.push(-n);
		check_size(MAX);
	}
	else
	{
		minheap.push(n);
		check_size(MIN);
	}		
}


void input()
{
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (i == 0)
			minheap.push(n);
		else
			push_heap(n);
		cout << minheap.top() << "\n";	
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	input();

}