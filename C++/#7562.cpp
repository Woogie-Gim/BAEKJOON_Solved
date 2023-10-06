#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, l;
int sty, stx, edy, edx;
int map[301][301];
int visited[301][301];
int dy[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dx[8] = { -1, 1, -2, 2, -2, 2,-1, 1 };

queue<pair<int, int>> q;

void bfs(int y, int x)
{
	q.push({ y, x });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= l || nx < 0 || nx >= l) continue;

			if (!visited[ny][nx])
			{
				visited[ny][nx] = 1;
				q.push({ ny, nx });
				map[ny][nx] = map[y][x] + 1;
			}
		}
	}

}

int main()
{
	cin >> n;

	while (n--)
	{
		cin >> l >> sty >> stx >> edy >> edx;
		visited[sty][stx] = 1;
		bfs(sty, stx);
		memset(visited, 0, sizeof(visited));
		cout << map[edy][edx] << "\n";

		memset(map, 0, sizeof(map));
	}

	return 0;
}