#include <iostream>
#include <queue>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	priority_queue<int> q;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		q.push(a);

		if (q.empty())
		{
			cout << 0 << "\n";
		}

		if (a == 0)
		{
			cout << q.top() << "\n";
			q.pop();
		}
	}

	return 0;
}