#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

int popul[50][50];
int N, L, R;
bool visited[50][50];
bool canmove = true;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int cnt = 0;

void bfs(int sx, int sy)
{
    if (visited[sy][sx])
        return;
    visited[sy][sx] = true;
    queue<pair<int, int>> q;
    queue < pair<int, int>> checkq;
    q.push(make_pair(sx, sy));
    checkq.push(make_pair(sx, sy));
    int popsum = 0;
    popsum += popul[sy][sx];
    int country = 0;
    country++;
    while (!q.empty())
    {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int sub = abs(popul[y][x] - popul[ny][nx]);
            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if (sub >= L && sub <= R && !visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    country++;
                    popsum += popul[ny][nx];
                    canmove = true;
                    q.push(make_pair(nx, ny));
                    checkq.push(make_pair(nx, ny));
                }
            }
        }
    }
    while (!checkq.empty())
    {
        int qx = checkq.front().first;
        int qy = checkq.front().second;
        popul[qy][qx] = popsum / country;
        checkq.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> popul[i][j];
        }
    }
    while (1)
    {
        canmove = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                bfs(j, i);
            }
        }
        if (!canmove)
            break;
        cnt++;
        memset(visited, false, sizeof(visited));
    }
    cout << cnt;
    return 0;
}