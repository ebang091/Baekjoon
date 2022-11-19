#include <string>
#include <vector>

using namespace std;

//DFS
int DFS(int i,  int N, int target, int sum, vector<int> numbers)
{
    //base case
    if (i == N)
    {
        if(sum == target)
            return 1;
        else
            return 0;
    }
    //recursion case
    
    return DFS(i + 1, N, target, sum + numbers[i], numbers) + DFS(i + 1, N , target, sum - numbers[i], numbers);
               
               
               
               
}



int solution(vector<int> numbers, int target) {
    int answer = 0, N = numbers.size();
    
    //DFS
    return DFS(0, N, target, 0, numbers);
    
    
    
    
    return answer;
}