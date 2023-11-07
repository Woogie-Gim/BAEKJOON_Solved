#include <iostream>
#include <queue>

using namespace std;

int map[5][5];
int visited[5][5];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int r, c;
queue<pair<int, int>> q;

void bfs(int sty, int stx)
{
	q.push({ sty, stx });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (map[y][x] == 1) break;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
			if (!visited[ny][nx] && map[ny][nx] != -1)
			{
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}

	}
}

int main()
{
	int edy = 0;
	int edx = 0;
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			int a;
			cin >> a;
			map[y][x] = a;
			if (a == 1)
			{
				edy = y;
				edx = x;
			}
		}
	}

	cin >> r >> c;
	bfs(r, c);

	if (visited[edy][edx])
	{
		cout << visited[edy][edx] << "\n";
	}
	else
	{
	cout << -1 << "\n";
	}

	return 0;
}