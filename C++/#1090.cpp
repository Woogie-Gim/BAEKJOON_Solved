#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;
vector<pair<int, int>> v2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v2.push_back({ v[i].first, v[j].second });
		}
	}

	for (int i = 1; i <= n; i++) {
		int ans = 987654321;
		for (int j = 0; j < v2.size(); j++) {
			int mid_x = v2[j].first;
			int mid_y = v2[j].second;

			vector<int> dis;
			for (int k = 0; k < n; k++)
			{
				dis.push_back(abs(mid_x - v[k].first) + abs(mid_y - v[k].second));
			}
			sort(dis.begin(), dis.end());
			int sum = 0;
			for (int k = 0; k < i; k++) sum += dis[k];
			ans = min(ans, sum);
		}
		cout << ans << ' ';
	}

	return 0;
}
