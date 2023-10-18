#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int point[100001], n, m, x, y;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> point[i];

	sort(point, point + n);
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		cout << upper_bound(point, point + n, y) - lower_bound(point, point + n, x) << "\n";
	}
	return 0;
}