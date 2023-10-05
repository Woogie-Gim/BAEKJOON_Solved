#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int t, m, n, k;
int map[51][51];
int visited[51][51];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void bfs(int a, int b)
{
	q.push({ a, b });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (!visited[ny][nx] && map[ny][nx])
			{
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	while(t--)
	{
		int cnt = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (!visited[y][x] && map[y][x])
				{
					visited[y][x] = 1;
					bfs(y, x);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
	}

	return 0;
}
