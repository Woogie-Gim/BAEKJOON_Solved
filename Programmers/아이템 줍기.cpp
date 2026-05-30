#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) 
{
    int board[102][102];
    for (int i = 0; i < 102; i++) 
    {
        for (int j = 0; j < 102; j++) 
        {
            board[i][j] = 0;
        }
    }
    
    for (int i = 0; i < rectangle.size(); i++) 
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for (int x = x1; x <= x2; x++) 
        {
            for (int y = y1; y <= y2; y++) 
            {
                board[x][y] = 1;
            }
        }
    }
    
    for (int i = 0; i < rectangle.size(); i++) 
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for (int x = x1 + 1; x < x2; x++) 
        {
            for (int y = y1 + 1; y < y2; y++) 
            {
                board[x][y] = 0;
            }
        }
    }
    
    int startX = characterX * 2;
    int startY = characterY * 2;
    int targetX = itemX * 2;
    int targetY = itemY * 2;
    
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    
    int dist[102][102];
    for (int i = 0; i < 102; i++) 
    {
        for (int j = 0; j < 102; j++) 
        {
            dist[i][j] = -1;
        }
    }
    dist[startX][startY] = 0;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (x == targetX && y == targetY) 
        {
            return dist[x][y] / 2;
        }
        
        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < 102 && ny >= 0 && ny < 102) 
            {
                if (board[nx][ny] == 1 && dist[nx][ny] == -1) 
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    return 0;
}