#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
char map[101][101];
int visited[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;


void bfs(int y, int x, char ch)
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
			if (map[ny][nx] == ch && !visited[ny][nx])
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
		string str;
		cin >> str;
		for (int x = 0; x < n; x++)
		{
			map[y][x] = str[x];
		}
	}

	int cnt1 = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!visited[y][x])
			{
				visited[y][x] = 1;
				bfs(y, x, map[y][x]);
				cnt1++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (map[y][x] == 'G')
			{
				map[y][x] = 'R';
			}
		}
	}

	int cnt2 = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!visited[y][x])
			{
				visited[y][x] = 1;
				bfs(y, x, map[y][x]);
				cnt2++;
			}
		}
	}

	cout << cnt1 << " " << cnt2 << "\n";
}