#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int map[101][101];
int visited[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void bfs(int y, int x, int height)
{
	q.push({ y, x });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (!visited[ny][nx] && map[ny][nx] > height)
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
	cin.tie(0);

	cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			int a;
			cin >> a;
			map[y][x] = a;
		}
	}

	int max_height = -21e8;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (map[y][x] > max_height)
			{
				max_height = map[y][x];
			}
		}
	}

	int height = 0;
	int Max = -21e8;

	while (height <= max_height)
	{
		int cnt = 0;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (map[y][x] > height && !visited[y][x])
				{
					visited[y][x] = 1;
					bfs(y, x, height);
					cnt++;
				}
			}
		}
		if (cnt > Max)
		{
			Max = cnt;
		}

		height++;
		memset(visited, 0, sizeof(visited));
	}

	cout << Max << "\n";

	return 0;
}