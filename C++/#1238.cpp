#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
 
#define inf 999999999
#define pii pair<int, int>
 
using namespace std;
 
struct cmp
{
    bool operator()(pii &a, pii &b)
    {
        return a.second>b.second;
    }
};
 
int N, M, X;
 
vector<pii> graph[1001], rev_graph[1001];
 
vector<int> dijkstra(int start, vector<pii> graph[])
{
    priority_queue<pii, vector<pii>, cmp> pq;
    vector<int> dist(N+1, inf);
    pii cur;
 
    dist[start]=0;
    pq.push({start, 0});
 
    while(!pq.empty())
    {
        cur=pq.top();
        pq.pop();
 
        for(pii next:graph[cur.first])
        {
            int next_dist=dist[cur.first]+next.second;
 
            if(next_dist<dist[next.first])
            {
                pq.push({next.first, next_dist});
                dist[next.first]=next_dist;
            }
        }
    }
 
    return dist;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin>>N>>M>>X;
 
    int a, b, c;
 
    for(int i=0; i<M; i++)
    {
        cin>>a>>b>>c;
 
        graph[a].push_back({b, c});
        rev_graph[b].push_back({a, c});
    }
 
    vector<int> time, rev_time, total_time;
 
    time=dijkstra(X, graph);
    rev_time=dijkstra(X, rev_graph);
 
    for(int i=1; i<=N; i++)
    {
        total_time.push_back(time[i]+rev_time[i]);
    }
 
    sort(total_time.rbegin(), total_time.rend());
 
    cout<<total_time[0];
 
    return 0;
}

구독하기이 글은 본 저작자 표시 규칙 하에 배포할 수 있습니다. 자세한 내용은 Creative Commons 라이선스를 확인하세요.
