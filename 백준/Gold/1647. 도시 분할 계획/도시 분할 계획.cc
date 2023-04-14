#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair< pair < int , int> , int > > edge;
int N;
int M;
int parent[100001];
int getParent(int n);

int isUnion(int a, int b)
{
    int pA = getParent(a);
    int pB = getParent(b);
    return pA == pB;
}

bool unionParent(int a, int b)
{
    int pA = getParent(a);
    int pB = getParent(b);
    if(pA == pB)
        return false;
    parent[pB] = pA;
    return true;
   
}

int getParent(int n)
{
    if(parent[n] == n)
        return n;
    int result =  getParent(parent[n]);
    parent[n] = result;
    return result;
}

void initUnion()
{
    for(int i = 0; i <= N ; i++)
        parent[i] = i;
}

bool greater_(const pair<pair<int ,int >, int> &a, const pair <pair<int ,int>, int> &b)
{
    return a.second < b.second;
}

long long Kruskal()
{
    long long totalCost = 0;
    int numEdge = 0;

    sort(edge.begin(), edge.end(), greater_);
    initUnion();
    for(int i = 0; i < edge.size(); i++)
    {
        if (!isUnion(edge[i].first.first, edge[i].first.second))
        {
            totalCost += edge[i].second;
            numEdge++;
            unionParent(edge[i].first.first, edge[i].first.second);
        }
        if(numEdge == N - 2)
            break;
            
    }
    // for(int i = 1; i <= N ; i++)
    //     cout << parent[i] << " ";
    // cout << "\n";
    
    return totalCost;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
/*
2 3 4 5 6 7 8 8 11

(1 2, 3  4,5 6)

2 3 4 6 8


*/
int main()
{
    cin >> N;
    cin >> M;    
    int u, v, w;
    for(int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        if(u > v )
            swap(u,v);
        edge.push_back(make_pair(make_pair(u,v), w));
    }
    cout << Kruskal();


}