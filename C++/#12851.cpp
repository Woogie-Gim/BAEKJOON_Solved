#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int dist[100002];
int cnt[100002];
queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (n == k)
	{
		cout << 0 <<"\n"<<1;
		return 0;
	}

	fill(dist, dist + 100002, -1);

	dist[n] = 0;
	cnt[n] = 1;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int nx : {cur + 1, cur - 1, cur * 2})
		{
			if (nx < 0 || nx>100000) continue;
			if (dist[nx] != -1)
			{
				if (dist[cur] + 1 == dist[nx])
					cnt[nx] += cnt[cur];
			}
			else
			{
				dist[nx] = dist[cur] + 1;
				cnt[nx] = cnt[cur];
				q.push(nx);
			}
		}
	}

	cout << dist[k] << "\n" << cnt[k];

	return 0;
}