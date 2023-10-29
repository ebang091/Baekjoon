#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	string result = "zzzzzzzzzz";
	cin >> str;

	int len = str.length();

	for (int i = 0; i < len - 2; i++)
	{
		for (int j = i + 1; j < len - 1; j++)
		{
			string temp;

			//나눠서 거꾸로 temp에 넣어주기
			for (int k = i; k >= 0; k--)
				temp += str[k];

			for (int k = j; k > i; k--)
				temp += str[k];

			for (int k = len-1; k > j; k--)
				temp += str[k];

			//result가 사전보다 앞서있다면 temp로 바꿔주기
			if (result > temp) 
				result = temp;
		}
	}

	cout << result;

	return 0;
}