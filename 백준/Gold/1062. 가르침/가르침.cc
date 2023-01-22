#include <iostream>
#include <queue>
#include <vector>
#include <queue>

#define MAX 51
using namespace std;
int N, K;


string s[MAX];
int word[MAX];
int learned;
vector <char> selected;
int answer = 0;

void input()
{
    string str;
    for(int i=0;i<N;i++)
    {
        cin >> str;
        for(int j=0;j<str.size();j++)
        {
            if((word[i] & ( 1 << str[j] - 'a')) == 0)  {
                word[i] |= (1 << str[j] - 'a');
            }
        }
    }
}

void find_learned()
{
    //1.배운 단어들을 배웠다고 표시
    //2.읽을 수 있는 단어들 세기
         //-> 더 나은 시간 복잡도를 위해서 비트 연산으로 풀어보자.
         //비트 연산: 합도 |= 로 더해야 한다.
         //string [i] = a의 경우 value |= (1 << string[i] -'a') 를 하면 0000 0000 0000 0000 0001 처럼 설정된다.
         //총 26개의 비트가 필요한데 int형은 32bit로, 표현이  가능하다. (십진수로 몇자리수인가와는 상관이 없다)
    //3.최댓값 갱신
    //4.그다음 풀이를 위해 다시 선택된 단어 되돌리기.
//    cout << "start " <<"\n";
    for(int i=0;i<selected.size();i++)
    {
        //cout << "selected : " << selected[i] <<   " ";
        if((learned & (1 << (selected[i] - 'a'))) == 0)
            learned |= (1 << (selected[i] - 'a'));
    }

//    cout << "\n";
    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        if((word[i] & learned) == word[i]) {
            //cout << i << "\n";
            cnt++;
        }
    }
    if(cnt > answer)
        answer = cnt;
//    4. 그다음 풀이를 위해 다시 선택된 단어 되돌리기.
    for(int i=0;i<selected.size();i++)
    {
        // cout << "selected : " << selected[i] <<   " ";
        learned &= ~(1<< (selected[i] - 'a'));
    }
}

void comb(int index, int cnt, int v)
{
    //기저조건
    if(cnt == v)
    {
        //단어 세기
        find_learned();
        return;
    }

    for(int i = index; i < 26;i++)
    {
        if((learned & (1 << i)) == 0)
        {
//            cout << "index : " << i << "\n";
            selected.push_back(i + 'a');
            comb(i + 1, cnt +1 , v);
            selected.pop_back();
        }
    }
}

int solve()
{
    if(K < 5)
        return 0;
    //문자를 조합해서 각 조합별로 단어들을 순회하면서 읽을 수 있는 단어를 센다.
    //조합: 백트레킹
    learned |= (1 << ('a' - 'a'));
    learned |= (1 << ('n' - 'a'));
    learned |= (1 << ('t' - 'a'));
    learned |= (1 << ('i' - 'a'));
    learned |= (1 << ('c' - 'a'));
    comb(0,0,K-5);
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    input();
    cout << solve();
}
