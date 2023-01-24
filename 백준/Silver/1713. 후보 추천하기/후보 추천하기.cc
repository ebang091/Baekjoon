#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, K; //사진 틀 수, 추천 수
bool isin[101];
int recommend[101];//학생번호에 따른 추천 수.
int update[101];//저장한 날짜.
int posted;

void init()
{
    for(int i=1;i<22;i++)
        isin[i] = false;
}
void output()
{

    for(int i=1;i<101;i++)
    {
        if(isin[i] == true && recommend[i] > 0)
            printf("%d ", i);
    }
    cout << "\n";
}

void input()
{
    int n;
    for(int i=0;i<K;i++)
    {
        scanf("%d", &n);
        if (isin[n] == true)//이미 있다면
        {
            recommend[n]++;
        }
        else
        {
            //액자가 덜 찼다면 추가
            if (posted < N) {
                isin[n] = true;
                recommend[n] = 1;
                update[n] = i;
                posted++;
            }
            else
            {
                int min = 1987654321;
                int date, id;
                for(int i=1;i<101;i++)
                {
                    if(isin[i] == true && recommend[i] < min)
                    {
                        id = i;
                        min = recommend[i];
                        date = update[i];
                    }
                    else if(isin[i] == true && recommend[i] == min)
                    {
                        if(update[i] < date) {
                            id = i;
                            date = update[i];
                        }
                    }
                }
                isin[id] = false;
                recommend[id] = 0;
                update[id] = 0;

                isin[n] = true;
                recommend[n] = 1;
                update[n] = i;
            }

            //액자가 꽉 찼다면 제거 후 추가
            //true
        }
    }
}


int main()
{

    cin >> N >> K;
    init();
    input();
    output();
}