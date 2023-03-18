#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, S[21][21];
vector <int> start;


long long fmin = 1987654;


long long ft_abs(long long a) 
{
    return (a >= 0 ? a : -a);
}

long long sum_start(int member)
{
    /*
    0 1 2 3 4

    0 -> 1 2 3 4
    1 -> 0 2 3 4 
    
    */
   long long ret = 0;
    for(int i = 0 ; i < N/2; i++)
    {
        int next = start[i];
        if (member != next)
        {
            // printf("next : %d, member : %d\n", next, member);
            ret += S[member][next];
        }
    }
    return ret;
}


long long sum_link(int member, vector<int> link)
{
   long long ret = 0;
    for(int i = 0 ; i < N/2; i++)
    {
        int next = link[i];
        if (member != next)
            ret += S[member][next];
    }
    return ret;
}

void make_combination(int depth, int idx)
{  
   if (depth == N/2)
   {
        long long result1 = 0;
        long long result2 = 0;
        for (int i = 0; i < start.size(); i++)
        {
            // printf("try1 : %d\n", start[i]);
            result1 += sum_start(start[i]);
        }
        bool isin = false;
        vector <int> link;
        for (int i = 1; i <= N ; i++)
        {
            isin = false;
            for(int j = 0; j < start.size(); j++)
            {
                if (start[j] == i)
                    isin = true;
            }
            if(!isin)
                link.push_back(i);
        }
        
        // printf("size : start : %d, link : %d\n", start.size(), link.size());
         for(int i = 0; i < link.size(); i++)
        {
            // printf("try : %d\n", link[i]);
            result2 += sum_link(link[i], link);
        }
        fmin = min(fmin, ft_abs(result1 -  result2));
        // printf("result1 = %lld, result2 = %lld, fmin  = %lld\n", result1, result2, fmin);
        return ;
   }

   for(int i = idx + 1; i <= N; i++)
   {
        start.push_back(i);
        make_combination(depth + 1, i);
        start.pop_back();
   }
}

long long solve()
{
    // 모든 조합에 대해서 {(0,1) (1,0) 조합도 허용}
    // N/2개짜리 조합 2개를 만든 뒤
    // 1.3.5.  2.4.6 
    // 각 점수를 구한다: (1,3+ 3,1 + 1,5 + 5,1 + 3,5 + 5,3)  , (2,4 + 4,2 + 2,6 + 6,2 + 4,6 + 6,4)
    // 그 점수 차를 구한다. (최솟값을 저장 갱신)
    

    // 조합 만들기 : 
    // 각 팀이 어디에 속하는지 1, 0으로 구분할까? -> 그래서 1이면 스타트, 0이면 링크.
    // 배열을 순회하면서 각 팀의 점수 구하기 : 각 팀의 요소를 2개씩 조합으로 만들어서 S값을 더해줘야 함. 
    
    //내가 아는 백트레킹 기법: 
    //1. 중복없이 하기 위해서 크기 순으로 조합을 구한다. 
    //2. for 문에서 push_back, pop_back을 통해서 조합을 구성한다. 
    //3. 마지막에 원하는 개수에 도달하면 내가 원하는 시행을 수행한다. 

    //내가 잘 모르겠는 것: 
    //정형화된 방법 말고, 팀을 모두 구성했으면 자기자신만 뺴고 모든 가능한 조합에 대해(무조건 0부터 시작하고 자기자신 빼면되겠다)
    //오로지 '2개'씩만 뽑아서 합을 계속 더해가는 방법이 있을까?

    /*

    int comb(int member)

    //start = {1,3,5} 
    for(int i = 0; i < N/2; i++)
    {
        int next = S[i];
        if(i != member)
            result +=  S[start[idx]][next];
    }

    //comb(start[0] : 1) -> {next : 3} result +=  S[1][3]
    //                   -> {next : 5} result +=  S[1][5]
    //comb(start[1] : 3) -> {next : 1} result +=  S[3][1]
    //                   -> {next : 5} result +=  S[3][5]
    //comb(start[2] : 5) -> {next : 1} result +=  S[5][1]
    //                   -> {next : 3} result +=  S[5][3]


    */

    make_combination(0, 0);
    return fmin;
}

int main()
{
    cin >> N;
    for(int i = 1 ; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> S[i][j];
    }
    cout << solve();

}