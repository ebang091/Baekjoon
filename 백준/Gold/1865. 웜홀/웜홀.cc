#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define MAX 1000000
#define INF 2147483647
#define FAST cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);

using namespace std;
int TC;
int N , M, W;
long long  dist[2501] = {0,};
// long long maxDis = -1;
// bool visited[10001] = {0,};

vector<pair<pair<int, int > , int> > edges;
// vector <pair<int, int > > worm;

void initialized(){
  for(int i = 1; i <= N; i++){
        dist[i] = -1;
    }   
}

bool bellmanFord(int S){



    initialized();
    bool updated;


    // dist[S] = 0;
    for(int iter = 0; iter < N-1; iter++){
        for(int j = 0; j < edges.size(); j++)
        {
            int cur = edges[j].first.first;
            int next = edges[j].first.second;
            int cost = edges[j].second;
            if(dist[cur] == INF)
                continue;
            if(dist[next] > cost + dist[cur]){
                dist[next] = cost + dist[cur];
            }    
        }
    }

    updated = false;
    for(long unsigned int j = 0; j < edges.size(); j++)
        {
            int cur = edges[j].first.first;
            int next = edges[j].first.second;
            int cost = edges[j].second;
            if(dist[cur] == INF)
                continue;
            if(dist[next] > cost + dist[cur]){
                dist[next] = cost + dist[cur];
                updated = true;
            }    
        }


    if(updated)
        return true;
    return false;
}

int main(){
    cin >> TC;
    int u, v, w;

    for(int i = 0; i < TC; i++){
        // cout << "-------------------case " << i << "--------------------\n";
        edges.clear();
        cin >> N >> M >> W;
        if(N == 1){
            cout << "NO\n";
            break;
        }
        for(int j = 0 ; j < M; j++){
            cin >> u >> v >> w;
            edges.push_back(make_pair(make_pair(u,v), w));
            edges.push_back(make_pair(make_pair(v,u), w));
        }
        for(int j = 0; j < W; j++){
            cin >> u >> v >> w;
            edges.push_back(make_pair(make_pair(u,v), -w));
            // worm.push_back(make_pair(u,v));
        }
        
        //시작점으로 돌아오기 위해서는, 
        //시작점으로 가는 웜홀이 있거나 
        //시작점과 연결된 노드가 있어야 한다. 일단 확인
        
        if (bellmanFord(1))
            cout << "YES\n";
        else
            cout << "NO\n"; 


    }
    
}
