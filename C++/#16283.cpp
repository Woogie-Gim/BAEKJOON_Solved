#include <iostream>
#include <vector>

using namespace std;

int a, b, n, w;

vector<pair<int, int>> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> n >> w;

	for (int i = 1; i < n; i++)
	{
		if (a * i + b * (n - i) == w) v.push_back({ i, (n - i) });
	}

	if (v.size() == 1) cout << v[0].first << " " << v[0].second;
	else cout << -1;

	return 0;
}