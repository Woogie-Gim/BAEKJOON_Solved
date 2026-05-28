#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps) 
{
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    
    q.push(make_pair(0, 0));
    dist[0][0] = 1;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (x == n - 1 && y == m - 1) 
        {
            return dist[x][y];
        }
        
        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) 
            {
                if (maps[nx][ny] == 1 && dist[nx][ny] == -1) 
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    return -1;
}