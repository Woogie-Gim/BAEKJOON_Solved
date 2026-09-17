#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = (int)maps.size();
    int m = (int)maps[0].size();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // -1 = 아직 방문 안 함. 방문 표시와 거리를 하나로
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 1;                 // 시작 칸도 1칸으로 셈

    while (q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
            if (dist[nx][ny] != -1) { continue; }
            if (maps[nx][ny] == 0) { continue; }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return dist[n - 1][m - 1];       // 못 갔으면 -1 그대로
}