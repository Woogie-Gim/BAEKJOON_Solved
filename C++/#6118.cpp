#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
 
int N, M;
vector<pair<int, int>> v[20010];
int d[20010];
int Max;
int MaxIdx;
int MaxNum;
 
void dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    d[1] = 0;
    
    while(!pq.empty())
    {
        int now = pq.top().second;
        int nowCost = pq.top().first;        
        pq.pop();
        
        if(d[now] != nowCost)
        {
            continue;
        } 
        
        for(int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i].first;
            int nextCost = v[now][i].second; 
            
            if(d[next] > d[now] + nextCost)
            {
                d[next] = d[now] + nextCost;
                pq.push({d[next], next});
            }
        }
    }
}
 
int main(void)
{   
    cin >> N >> M;
    
    for(int i = 2; i <= N; i++)
    {
        d[i] = 99999999;
    }
    
    for(int i = 1; i <= M; i++)
    {
        int from, to;
        cin >> from >> to;
        
        v[from].push_back({to, 1});
        v[to].push_back({from, 1});    
    }
    
    dijkstra();
 
    for(int i = 2; i <= N; i++)
    {
        if(d[i] > Max)
        {
            Max = d[i];
            MaxIdx = i;
        }
    }
    
    for(int i = 2; i <= N; i++)
    {
        if(Max == d[i])
        {
            MaxNum++;
        }
    }
    
    cout << MaxIdx << " " << Max << " " << MaxNum;
    
    return 0;
}
