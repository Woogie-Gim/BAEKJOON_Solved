#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];
int map[1001][1001];
int Start,End;
int ans = 0;
 
void init(int n)
{
    for(int i = 0;i<=n;i++)
    {
        visited[i] = false;
    }
}
 
void dfs(int start,int depth)
{
    if(start == End)
    {
        ans = depth;
        return;
    }
    if(visited[start])
    {
        return;
    }
    visited[start] = true;
    for(int i = 0;i<graph[start].size();i++)
    {
        int y = graph[start][i];
        
        if(map[start][y] != 0)
        {
            dfs(y,depth+map[start][y]);
        }
        else if(map[start][y] == 0 && map[y][start] != 0)
        {
            dfs(y,depth+map[y][start]);
        }
    }
 
}
int main()
{
    int n,m;
    cin >> n >> m;
    
    for(int i = 0;i<n-1;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        map[a][b] = c;
        map[b][a] = c;
    }
    
    for(int i = 0;i<m;i++)
    {
        init(n);
        cin >> Start >> End;
        dfs(Start,0);
        cout << ans << '\n';
    }
}