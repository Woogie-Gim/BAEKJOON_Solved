#include <iostream>
#include <string>
#include <vector>

#define MAX 201

using namespace std;

int n, m;

string Map[MAX];

int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };

bool Check(int y, int x)
{
    return y < 0 || x < 0 || y >= n || x >= m;
}

int dfs(int y, int x)
{
    int ret = 0;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (Check(ny, nx))
        {
            continue;
        }

        if (Map[ny][nx] == 'N' || Map[ny][nx] == 'S')
        {
            nx += dx[i];
            ny += dy[i];

            if (Check(ny, nx))
            {
                continue;
            }

            if (Map[ny][nx] == 'F' || Map[ny][nx] == 'T')
            {
                nx += dx[i];
                ny += dy[i];

                if (Check(ny, nx))
                {
                    continue;
                }

                if (Map[ny][nx] == 'P' || Map[ny][nx] == 'J')
                {
                    ret++;
                }
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> Map[i];
    }

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Map[i][j] == 'E' || Map[i][j] == 'I')
            {
                res += dfs(i, j);
            }
        }
    }

    cout << res;
}
