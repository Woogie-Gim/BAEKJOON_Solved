#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int INF = 98765432;
vector<pair<int, int>> v[802];
int dist[803];
void bfs(int a)
{
    memset(dist, INF, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, a));
    dist[a] = 0;
    while (!q.empty())
    {
        int sum_distance = q.top().first;
        int x = q.top().second;
        q.pop();
        
        if(dist[x] < sum_distance)
            continue;
        for (int i = 0; i < v[x].size(); i++){
            int nx = v[x][i].first;
            int ncost = sum_distance + v[x][i].second;
 
            if(dist[nx] > ncost){
                q.push({ncost, nx});
                dist[nx] = ncost;
            }
        }
    }
}
int mn(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}
int main(){
    int n, e;
    cin >> n >> e;
    int a1,a2,a3;
    for (int i = 0; i < e; i++){
        cin >> a1 >> a2 >> a3;
        v[a1].push_back({a2, a3});
        v[a2].push_back({a1, a3});
    }
    int dt1, dt2;
    cin >> dt1 >> dt2;
    
    bfs(1);
    int To_dt1 = dist[dt1];
    int To_dt2 = dist[dt2];
 
    bfs(dt1);
    int dt1_To_dt2 = dist[dt2];
    int dt1_To_n = dist[n];
 
    bfs(dt2);
    int dt2_To_n = dist[n];
 
    int result;
 
    result = mn(INF, To_dt1 + dt1_To_dt2 + dt2_To_n);
    result = mn(result, To_dt2 + dt1_To_dt2 + dt1_To_n);
    if(result >= INF)
        cout << -1;
    else
        cout << result;
    return 0;
}