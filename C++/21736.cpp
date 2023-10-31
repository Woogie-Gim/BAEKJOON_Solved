#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
int sty, stx;
int cnt;
char map[601][601];
int visited[601][601];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

int bfs(int sty, int stx)
{
	int cnt = 0;
	q.push({ sty, stx });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (map[y][x] == 'P') cnt++;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (!visited[ny][nx] && map[ny][nx] != 'X')
			{
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
	return cnt;
}

int main()
{
	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < m; x++)
		{
			map[y][x] = str[x];
			if (str[x] == 'I')
			{
				sty = y;
				stx = x;
			}
		}
	}

	visited[sty][stx] = 1;
	int cnt = bfs(sty, stx);

	if (cnt)
	{
		cout << cnt << "\n";
	}
	else
	{
		cout << "TT" << "\n";
	}

	return 0;
}