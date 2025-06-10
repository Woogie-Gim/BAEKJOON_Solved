#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n, m;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int graph[101][101];
bool vis[101][101];
bool isPeak;

void BFS(int yy, int xx)
{
    queue<pair<int, int>> q;
    q.push({ yy, xx });
    vis[yy][xx] = true;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            {
                continue;
            }

            if (graph[yy][xx] < graph[ny][nx])
            {
                isPeak = false;
            }

            if (vis[ny][nx])
            {
                continue;
            }

            if (graph[yy][xx] != graph[ny][nx])
            {
                continue;
            }

            q.push({ ny, nx });
            vis[ny][nx] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j])
            {
                continue;
            }

            if (graph[i][j] == 0)
            {
                continue;
            }

            isPeak = true;
            BFS(i, j);

            if (isPeak)
            {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
