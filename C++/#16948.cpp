#include <iostream>
#include <queue>

using namespace std;

int n;
int r1, c1, r2, c2;
int visited[200][200];
int dy[6] = { -2, -2, 0, 0, 2, 2 };
int dx[6] = { -1, 1, -2, 2, -1, 1 };

queue<pair<int, int>> q;

int bfs(int sty, int stx, int edy, int edx)
{
	int flag = 0;

	q.push({ sty, stx });
	visited[sty][stx] = 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == edy && x == edx)
		{
			flag = 1;
			break;
		}

		for (int i = 0; i < 6; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	return flag;
}

int main()
{
	cin >> n >> r1 >> c1 >> r2 >> c2;

	int rtn = bfs(r1, c1, r2, c2);

	if (rtn)
	{
		cout << visited[r2][c2] - 1 << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}

	return 0;
}
