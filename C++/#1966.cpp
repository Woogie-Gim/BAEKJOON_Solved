#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int t;
	int n, m, num;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int cnt = 0;
		queue<pair<int, int>>q;
		priority_queue<int>printer;
		cin >> n >> m;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			q.push({ j, num });
			printer.push(num);
		}
		while (!printer.empty())
		{
			int idx = q.front().first;
			int prior = q.front().second;
			q.pop();
			if (printer.top() == prior)
			{
				cnt++;
				printer.pop();
				if (idx == m)
				{
					cout << cnt << '\n';
					break;
				}
			}
			else
				q.push({idx,prior});
		}
	}
	return 0;
}