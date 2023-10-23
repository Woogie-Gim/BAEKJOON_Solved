/* 우선순위 큐 풀이 */

#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		pq.push({ x, y });
	}

	for (int i = 0; i < n; i++)
	{
		cout << pq.top().first << ' ' << pq.top().second << "\n";
		pq.pop();
	}

	return 0;
}

/* sort 풀이 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<int>> v;

bool comp(vector<int> &v1, vector<int> &v2)
{
	if (v1[0] == v2[0]) return v1[1] < v2[1];
	else return v1[0] < v2[0];
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		v.push_back({ x, y });
	}

	sort(v.begin(), v.end(), comp);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			cout << v[y][x] << ' ';
		}
		cout << "\n";
	}

	return 0;
}